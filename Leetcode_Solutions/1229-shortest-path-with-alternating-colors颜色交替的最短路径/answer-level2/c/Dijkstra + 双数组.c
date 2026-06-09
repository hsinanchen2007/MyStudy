### 解题思路
Dijkstra + 双数组

### 代码

```c
#define RED  0
#define BLUE 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestAlternatingPaths(int n, int** red_edges, int red_edgesSize, int* red_edgesColSize, int** blue_edges, int blue_edgesSize, int* blue_edgesColSize, int* returnSize){
    int i;
    int j;
    int *distance_red = NULL;
    int *distance_blue = NULL;
    char *visited_red = NULL;
    char *visited_blue = NULL;

    if (n == 0) {
        *returnSize = 0;
        return NULL;
    }

    distance_red = (int *)malloc(sizeof(int) * n);
    distance_blue = (int *)malloc(sizeof(int) * n);
    visited_red = (char *)malloc(n);
    visited_blue = (char *)malloc(n);

    for (i = 0; i < n; i++) {
        distance_red[i] = -1;
        distance_blue[i] = -1;
        visited_red[i] = 0;
        visited_blue[i] = 0;
    }

    // init
    distance_red[0] = 0;
    distance_blue[0] = 0;

    for (i = 0; i < red_edgesSize; i++) {
        if ((red_edges[i][0] == 0) && (red_edges[i][1] != 0)) {
            distance_red[red_edges[i][1]] = 1;
        }
    }
    for (i = 0; i < blue_edgesSize; i++) {
        if ((blue_edges[i][0] == 0) && (blue_edges[i][1] != 0)) {
            distance_blue[blue_edges[i][1]] = 1;
        }
    }
    visited_red[0] = 1;
    visited_blue[0] = 1;

    // bfs
    for (i = 0; i < 2 * (n - 1); i++) {
        int min[] = {0x7fffffff, 0x7fffffff};
        int k[] = {-1, -1};

        for (j = 0; j < n; j++) {
            if ((visited_red[j] == 0) && (distance_red[j] >= 0) && (distance_red[j] < min[RED])) {
                min[RED] = distance_red[j];
                k[RED] = j;
            }

            if ((visited_blue[j] == 0) && (distance_blue[j] >= 0) && (distance_blue[j] < min[BLUE])) {
                min[BLUE] = distance_blue[j];
                k[BLUE] = j;
            }
        }
        if (k[RED] < 0 && k[BLUE] < 0)
            break;

        if (k[RED] >= 0) {
            visited_red[k[RED]] = 1;
            for (j = 0; j < blue_edgesSize; j++) {
                if ((blue_edges[j][0] == k[RED]) && ((distance_blue[blue_edges[j][1]] < 0) || ((min[RED] + 1) < distance_blue[blue_edges[j][1]]))) {
                    distance_blue[blue_edges[j][1]] = min[RED] + 1;
                }
            }
        }
        if (k[BLUE] >= 0) {
            visited_blue[k[BLUE]] = 1;
            for (j = 0; j < red_edgesSize; j++) {
                if ((red_edges[j][0] == k[BLUE]) && ((distance_red[red_edges[j][1]] < 0) || ((min[BLUE] + 1) < distance_red[red_edges[j][1]]))) {
                    distance_red[red_edges[j][1]] = min[BLUE] + 1;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (distance_red[i] < 0 && distance_blue[0] < 0)
            continue;
        else if (distance_red[i] < 0)
            distance_red[i] = distance_blue[i];
        else if (distance_blue[i] < 0)
            continue;
        else if (distance_red[i] < distance_blue[i])
            continue;
        else
            distance_red[i] = distance_blue[i];
    }

    free(distance_blue);
    free(visited_red);
    free(visited_blue);

    *returnSize = n;
    return distance_red;
}
```