#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct 
{
    uint16_t x;
    uint16_t y;
} Vec2;

int main()
{
FILE *input = fopen("wire_reading.txt", "r");

uint32_t edge_length = 30000;
uint32_t grid_size = edge_length * edge_length;
uint32_t *map_one = malloc(sizeof(uint16_t) * grid_size);
uint32_t *map_two = malloc(sizeof(uint16_t) * grid_size);
uint32_t starting = edge_length/2;
Vec2 pos_one = 
{
    .x = starting, 
    .y = starting
};
Vec2 pos_two = 
{
    .x = starting, 
    .y = starting
};

uint16_t debug = 1;
uint16_t steps = 0;
uint8_t map = 1;
char read, direction;
memset(map_one,0,sizeof(uint32_t) * grid_size);
memset(map_two,0,sizeof(uint32_t) * grid_size);
uint8_t check = 0;
// printf("GOOD\n");                       // testing
while((read = fgetc(input)) != EOF)
{
    if(read == 'U' || read == 'D' || read == 'R' || read == 'L'){direction = read;}
    else if(read == ',' || read == '\n')
    {
        if(read == '\n') {map++;}

        printf("Steps: %c%d\n", direction,steps);
        if(map == 2 && check == 0){
            printf("SECOND LINE\n");
            check++;
        }
    //    printf("STEPS: %d\n", steps);       // testing
        switch(map)
        {
            case 1:
            if(direction == 'U')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = ((pos_one.y + i) * edge_length) + pos_one.x;
                    map_one[index] = 1;
                }
                pos_one.y += steps;
            }
            if(direction == 'D')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = ((pos_one.y - i) * edge_length) + pos_one.x;
                    map_one[index] = 1;
                }
                pos_one.y -= steps;
            }
            if(direction == 'R')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = (pos_one.y * edge_length) + (pos_one.x + i);
                    map_one[index] = 1;
                }
                pos_one.x += steps;
            }
            if(direction == 'L')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = (pos_one.y * edge_length) + (pos_one.x - i);
                    map_one[index] = 1;
                }
                pos_one.x -= steps;
            }
            steps = 0;
            // printf("Loop %d\n",debug++);            // testing
            break;

            case 2:
            if(direction == 'U')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = ((pos_two.y + i) * edge_length) + pos_two.x;
                    map_two[index] = 1;
                }
                pos_two.y += steps;
            }
            if(direction == 'D')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = ((pos_two.y - i) * edge_length) + pos_two.x;
                    map_two[index] = 1;
                }
                pos_two.y -= steps;
            }
            if(direction == 'R')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = (pos_two.y * edge_length) + (pos_two.x + i);
                    map_two[index] = 1;
                }
                pos_two.x += steps;
            }
            if(direction == 'L')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = (pos_two.y * edge_length) + (pos_two.x - i);
                    map_two[index] = 1;
                }
                pos_two.x -= steps;
            }
            steps = 0;
            break;

            default:
            printf("ERROR");
            break;
        } 
    }
    else
    {
        steps *= 10;
        steps += read - '0';
    }
}

printf("Steps: %c%d\n", direction,steps);
if(direction == 'U')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = ((pos_two.y + i) * edge_length) + pos_two.x;
                    map_two[index] = 1;
                }
                pos_two.y += steps;
            }
            if(direction == 'D')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = ((pos_two.y - i) * edge_length) + pos_two.x;
                    map_two[index] = 1;
                }
                pos_two.y -= steps;
            }
            if(direction == 'R')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = (pos_two.y * edge_length) + (pos_two.x + i);
                    map_two[index] = 1;
                }
                pos_two.x += steps;
            }
            if(direction == 'L')
            {
                for(int i = 1; i <= steps; i++)
                {
                    size_t index = (pos_two.y * edge_length) + (pos_two.x - i);
                    map_two[index] = 1;
                }
                pos_two.x -= steps;
            }
            steps = 0;

fclose(input);
printf("Read and mapped");
// done reading and mapping

// now finding closest intersection 
uint32_t index
int16_t distance = 0;
int8_t loop = 1;

while(loop != 0)
{
    distance++;
    for(int i = 0; i < distance; i++)
    {
        index = ((starting + distance - i) * edge_length) + (starting + i);
        if(map_one[index] == 1 && map_two[index] == 1)
        {
            loop = 0;
        }
    }

    for(int i = 0; i < distance; i++)
    {
        index = ((starting + i) * edge_length) + (starting + distance - i);
        if(map_one[index] == 1 && map_two[index] == 1)
        {
            loop = 0;
        }        
    }

    for(int i = 0; i < distance; i++)
    {
        index = ((starting - distance + i) * edge_length) + (starting - i);
        if(map_one[index] == 1 && map_two[index] == 1)
        {
            loop = 0;
        }        
    }

    for(int i = 0; i < distance; i++)
    {
        index = ((starting - i) * edge_length) + (starting - distance + i);
        if(map_one[index] == 1 && map_two[index] == 1)
        {
            loop = 0;
        }        
    }

}

free(map_one);
free(map_two);
printf("\nDistance: %d\n", distance);
}