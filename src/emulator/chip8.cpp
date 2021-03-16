#include <chip8emu/emulator/chip_8.hpp>


namespace emulator
{

void chip8::insert_cartridge(const cartridge& cartridge)
{
    m_bus.ram.load_machine_code(cartridge.binary);
}

void chip8::remove_cartridge()
{
    /* Reset all components */
}

void chip8::run()
{
    while (true)
    {
        m_bus.cpu.fetch_instruction();
        m_bus.cpu.exec_instruction();
    }
}

}
