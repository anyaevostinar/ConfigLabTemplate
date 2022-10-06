#ifndef WORLD_H
#define WORLD_H

#include "emp/Evolve/World.hpp"
#include "emp/math/random_utils.hpp"
#include "emp/math/Random.hpp"

#include "Org.h"

class OrgWorld : public emp::World<Organism> {

    emp::Random &random;
    emp::Ptr<emp::Random> random_ptr;

    public:

    OrgWorld(emp::Random &_random) : emp::World<Organism>(_random), random(_random) {
        random_ptr.New(_random);
    }

    ~OrgWorld() {
    }

  void Update() {
      emp::World<Organism>::Update();

      emp::vector<size_t> schedule = emp::GetPermutation(random, GetSize());
      std::cout << "Updating!" << std::endl;
      for(int i : schedule) {
        if(!IsOccupied(i)) {continue;}
        pop[i]->Process(100);
      }

      schedule = emp::GetPermutation(random, GetSize());
      for(int i : schedule) {
        if(!IsOccupied(i)) {continue;}
        emp::Ptr<Organism> offspring = pop[i]->CheckReproduction();
        if(offspring) {
            DoBirth(*offspring, i);
        }
      }
      
  }

};
#endif