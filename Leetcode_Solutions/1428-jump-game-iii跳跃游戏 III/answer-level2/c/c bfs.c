### 解题思路
bfs 

### 代码

```c
int visited[50000];
bool canReach(int* arr, int arrSize, int start){
    int stack[50000];
    int top = 1;
    int tmp, em1, em2;
    stack[top] = start;
    memset(visited, 0, sizeof(visited));
    while (top > 0) {
        tmp = stack[top];
        top--;
        visited[tmp] = 1;
        if (arr[tmp] != 0) {
            em1 = tmp + arr[tmp];
            em2 = tmp - arr[tmp];
            if (em1 < arrSize && em1 >= 0 && visited[em1] == 0) {
                stack[++top] = em1;
            }
            if (em2 < arrSize && em2 >= 0 && visited[em2] == 0) {
                stack[++top] = em2;
            }
        } else {
            return 1;
        }
    }
    return 0;
}
```