#include <iostream>

#include "Org.h"
#include "emp/base/vector.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "World.h"

// This is the main function for the NATIVE version of this project.


int main(int argc, char* argv[])
{

  emp::Random random(5);
  OrgWorld world(random);


  Organism* new_org = new Organism(&random);
  world.Inject(*new_org);

  world.Resize(10,10);

  for(int update=0; update<40; update++){
    world.Update();
    std::cout << world.GetNumOrgs() << std::endl;

    std::cout << world.size() << std::endl;

  }

}
