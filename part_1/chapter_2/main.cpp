#include <iostream>
#include <vector>
#include <limits>

class Sphere {
  public:
    int radius;
    std::vector<int> centre;
    std::vector<int> colour;

    Sphere() : radius(0) {}

    Sphere(const Sphere& other) {
      radius = other.radius;
      centre = other.centre;
      colour = other.colour;
    };

    Sphere(
      int x, int y, int z,
      int _radius,
      int r, int g, int b
    ) {
      radius = _radius;
      centre = std::vector<int> {x, y, z};
      colour = std::vector<int> {r, g, b};
    }
};

class Scene {
  public:
    std::vector<Sphere> spheres;
};

std::ostream& operator<<(std::ostream &s, const Sphere &sphere) {
  return s << "Radius:\t" << sphere.radius << "\n" <<
    "Colour:\t" << sphere.colour[0] <<
    ", " << sphere.colour[1] <<
    ", " << sphere.colour[2] << "\n";
}

const int Cw = 960;
const int Ch = 540;

const int Vw = 1;
const int Vh = 1;

const int d = 1;

Scene scene;

void initialize_scene() {
  Sphere my_sphere = Sphere(
    0, -1, 3,
    1,
    255, 0, 0
  );
  scene.spheres.push_back(my_sphere);
}

std::vector<int> CanvasToViewport(int x, int y) {
  std::vector<int> D = {x * Vw / Cw, y * Vh / Ch, d};
  return D;
}

int TraceRay(std::vector<int> origin, std::vector<int> D, int t_min, int t_max) {
  int closest_t = INT_MAX;
  Sphere closest_sphere;
  for (const auto sphere : scene.spheres) {
  }
  return 0;
}


int main() {
  initialize_scene();
  for (const auto sphere : scene.spheres) {
    std::cout << sphere << std::endl;
  }

  const std::vector<int> origin(3, 0);
  for (int x = -Cw / 2; x < Cw / 2; x++)
    for (int y = -Ch / 2; y < Ch / 2; y++) {
      auto D = CanvasToViewport(x, y);
      auto colour = TraceRay(origin, D, 1, INT_MAX);
    }
}
