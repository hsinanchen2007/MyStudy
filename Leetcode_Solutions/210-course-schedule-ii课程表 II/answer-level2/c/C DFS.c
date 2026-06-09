/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int g_ansIndex = 0; 
int* g_ans = NULL;
bool* g_pru = NULL;
bool* g_vis = NULL;

bool Dfs(int** courses, int row, int course)
{
    int i = 0;
    
    if (g_pru[course] == true) {
        return true;
    }

    if (g_vis[course] == true) {
        return false;
    }

    for (; i < row; i++) {
        if (courses[i][0] == course) {
            g_vis[course] = true;
            if (Dfs(courses, row, courses[i][1]) == false) {
                return false;
            }
        } 
    }

    if (i == row) {
        g_ans[g_ansIndex++] = course;
        g_pru[course] = true;
    }

    return true;
}

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){

    g_ans = (int*)calloc(numCourses, sizeof(int));
    g_pru = (bool *)calloc(numCourses, sizeof(bool));
    g_vis = (bool *)calloc(numCourses, sizeof(bool));

    g_ansIndex = 0;
    for (int i = 0; i < numCourses; i++) {
        if (Dfs(prerequisites, prerequisitesSize, i) == false) {
            break;
        }
    }    

    if (g_ansIndex != numCourses) {
        *returnSize = 0;
        return NULL;
    }

    *returnSize = numCourses;
    free(g_pru);
    return g_ans;
}
