#include <stdio.h>
#include <stdint.h>

uint64_t fuelforfuel(uint64_t fuel);

int main(){
    FILE *input = fopen("mass_input.txt", "r");

    char string[10];
    uint64_t total_fuel = 0;
    uint32_t read_mass = 0;

    while(fgets(string, 10, input)!= NULL){
        uint8_t i = 0;
        read_mass = 0;
        while(string[i] != 0){
            read_mass = read_mass*10;
            read_mass += (string[i] - 48);
            // uint8_t num = string[i] - '0';
           // printf("%d ", num);             //testing
            i++;
        }
        read_mass /= 10;
        read_mass += 4;
        total_fuel += fuelforfuel((read_mass/3) - 2);
        //printf("\n");                     //testing
        //printf("%d\n", read_mass);        // testing
    }
    total_fuel -= fuelforfuel((read_mass/3) - 2);
    read_mass -= 4;
    read_mass *= 10;
    total_fuel += fuelforfuel((read_mass/3) - 2);
    //printf("\n%d\n", read_mass);           // testing
             
    printf("Total Fuel: %ld\n", total_fuel);    //answer part 2
    fclose(input);
    return 0;

}

// method for finding the fuel required for the fuel!
uint64_t fuelforfuel(uint64_t fuel){
    if(fuel <= 8) return fuel;
    else return fuel + fuelforfuel((fuel/3) - 2);
}