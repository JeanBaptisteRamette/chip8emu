#include <chip8emu/emulator/memory.hpp>


namespace emulator
{
    memory::memory() : m_ram{}
    {
        const auto font_set = {
                0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
                0x20, 0x60, 0x20, 0x20, 0x70, // 1
                0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
                0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
                0x90, 0x90, 0xF0, 0x10, 0x10, // 4
                0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
                0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
                0xF0, 0x10, 0x20, 0x40, 0x40, // 7
                0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
                0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
                0xF0, 0x90, 0xF0, 0x90, 0x90, // A
                0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
                0xF0, 0x80, 0x80, 0x80, 0xF0, // C
                0xE0, 0x90, 0x90, 0x90, 0xE0, // D
                0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
                0xF0, 0x80, 0xF0, 0x80, 0x80  // F
        };

        std::copy_n(std::begin(font_set), std::size(font_set), std::begin(m_ram) + FONT_ADDRESS);
    }

    /* read and write operations */
    uint8_t &memory::operator[](address_type address)
    {
        if (address < CODE_ADDRESS || address >= MEMORY_SIZE)
            throw memory_access_error(address);

        return m_ram[address];
    }

    const uint8_t &memory::operator[](address_type address) const
    {
        if (address < CODE_ADDRESS || address >= MEMORY_SIZE)
            throw memory_access_error(address);

        return m_ram[address];
    }

    void memory::load_machine_code(const std::vector<uint8_t> &binary)
    {
        std::copy_n(std::begin(binary), std::size(binary), std::begin(m_ram) + CODE_ADDRESS);
    }
}

