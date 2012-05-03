#include <cstdint>
#include <cassert>
#include <vector>
#include <utility>

#define CELL_INITIAL_LIFE 100

namespace cellwar
{

typedef uint16_t coord_t;

struct pos_t
{
	const coord_t x_, y_;
};

struct command_t
{
	const enum class cmd_t : uint8_t {move, attack, eat} cmd_;
	const pos_t target_;
};

struct cell_t
{
	uint8_t life_;

	cell_t(uint8_t life = CELL_INITIAL_LIFE):
		life_(life)
	{ }

	inline bool is_alive()
	{
		return life_ > 0;
	}
};

class world_t
{
	private:

	std::vector<cell_t> data_;

	public:

	const coord_t width_, height_;

	world_t(coord_t width, coord_t height):
		data_(width * height, cell_t(0)),
		width_(width),
		height_(height)
	{ }

	inline cell_t &operator()(coord_t x, coord_t y)
	{
		assert(x < width_ && y < height_);

		return data_[width_ * y + x];
	}

	inline const cell_t operator()(coord_t x, coord_t y) const
	{
		assert(x < width_ && y < height_);

		return data_[width_ * y + x];
	}
};

class simulation_t
{
	private:

	world_t world;
	std::vector<std::pair<pos_t, command_t>> command_queue;
	std::vector<pos_t> death_queue;

	public:

	simulation_t(coord_t width, coord_t height):
		world(width, height),
		command_queue(),
		death_queue()
	{ }

	void run()
	{
		// XXX
		// XXX
		// XXX: Hacer implementacion inicial con cells en posiciones
		// XXX  aleatorias yendo todas a (0, 0) con una UI de texto
		// XXX
		// XXX
	}
};

};

int main(int argc, char *argv[])
{
	cellwar::simulation_t sim(100, 200);

	sim.run();

	return 0;
}
