#include <chip8emu/emulator/screen_display.hpp>


namespace emu
{
    screen_display::screen_display(const std::shared_ptr<SDL_Renderer>& renderer) :
        m_renderer(renderer),
        m_texture {
                    SDL_CreateTexture(m_renderer.get(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT),
                    SDLTextureDestroyer() }
    {
        m_video_buffer.resize(WIDTH * HEIGHT);
    }

    void screen_display::clear()
    {
        std::fill(std::begin(m_video_buffer), std::end(m_video_buffer), 0);
    }

    void screen_display::render_frame() const noexcept
    {
        SDL_UpdateTexture(m_texture.get(), nullptr, std::data(m_video_buffer), PITCH);
        SDL_RenderCopy(m_renderer.get(), m_texture.get(), nullptr, &m_render_target);
    }

    u32 &screen_display::pixel(u64 pos) noexcept
    {
        return m_video_buffer[pos];
    }
}