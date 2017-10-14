#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "graph.h"
#include "queue.h"
#include "set.h"

typedef struct Ranks{
    char *url;
    int degree;
    double pRank;
} Ranks;

typedef struct RankCollection{
    Ranks *all
    int nurls;
} RankCollection

void calculatePageRank(WebGraph, RankCollection, float, float, int);
void outputRanks(RankCollection);

int main(int argc, char **argv) {
    int i; //iterator

    if(argc != 4) {
        fprintf(stderr, "Usage: %s d diffPR maxIterations\n", argv[0]);
        return 1; //unsuccesful
    }

    //extract information from cmd line
    float d = atof(argv[1]);
    float diffPR = atof(argv[2]);
    float maxIteration = atof(argv[3]);

    // Read "web pages" from the collection in file "collection.txt"
    //       and build a graph structure using Adjacency List Representation
    //
    //       N = number of urls in the collection
    //
    //       For each url pi in the collection
    //
    //       End For
    //
    //       iteration = 0;
    //       diff = diffPR;   // to enter the following loop
    //
    //       While (iteration < maxIteration AND diff >= diffPR)
    //           iteration++;
    //    End While

    //get set from readdata.c and graph

    RankCollection urldata;
    urldata->nurls = nElems(urls);
    urldata->all = malloc(sizeof(Ranks)*urldata->nurls);



    return 0;
}
