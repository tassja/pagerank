#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "graph.h"
#include "queue.h"
#include "set.h"


int main(int argc, char const *argv[]) {

    Graph webGraph = newGraph(999);
    Queue todo = newQueue();
    Set seen = newSet();


     FILE *fp = fopen("Sample1/collection.txt", "r");

     int array[99];
    // int array2[99];
     int i = 0;

        fscanf(fp,"\n");
        while (fscanf(fp,"url%d " , &array[i]) != EOF) {
            //printf("%d\n", array[i]);
            i++;
        }

        fclose(fp);
        //printf("i is %d\n", i);
        int size = i-1;
        int j = 0;
        char arr3[999][999];
        int k = 0;
        while (j <= size) {
            char num[3];
            sprintf(num,"%d",array[j]);

            char * strA = "Sample1/url.txt", strC[50];
            int x = 11;
            strncpy(strC,strA,x); //goo.gl/rXuFz3
            strC[x] = '\0';
            strcat(strC,num);
            strcat(strC,strA+x);
            printf("%s\n",strC);

            char c;

            FILE *f2 = fopen(strC, "r"); //open specified array
            enterQueue(todo, arr3[k]);
            insertInto(seen, arr3[k]);
            c = getc(f2);
            c = getc(f2);

            while (c != '#' && c != EOF) {
                if (c == 'l') {
                    c = getc(f2);
                    int u = 0;
                    while (c != ' ') {
                        arr3[k][u] = c;
                        u++;
                        c = getc(f2);
                        arr3[k][u] = '\0';
                    }
                    //fscanf(f2," %s", arr3[k]);
                    //printf("num: %s\n", num);
                    //printf("arr3[k]: %s\n", arr3[k]);

                    //if(!isElem(seen, arr3[k])){
                      insertInto(seen, arr3[k]);
                      enterQueue(todo, arr3[k]);
                     // printf("curr num is:%s\n", num);
                      addEdge(webGraph,num,arr3[k]);
                      printf("inserting edge between %s and %s\n", num, arr3[k]);
                    //}

                    // if (isElem(seen, arr3[k])) {
                    //  addEdge(webGraph,num,arr3[k]);
                     //}

                //int g = atoi(arr3[k]);
                //printf("%d\n", g);
                 }
                 c = getc(f2);
            }
            k++;
            fclose(f2);
            j++;
        }

        //int numofpages = k;

        showGraph(webGraph, 0);
        showGraph(webGraph, 1);


    return 0;
}
