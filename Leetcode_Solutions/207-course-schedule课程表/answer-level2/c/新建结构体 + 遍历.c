

执行结果：通过

执行用时 :56 ms, 在所有 c 提交中击败了60.98%的用户
内存消耗 :8.1 MB, 在所有 c 提交中击败了100.00%的用户


```
struct node {
    int inNode;
    bool visited;
};
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {

    if (!prerequisites || !prerequisitesColSize) {
        return true;
    }

    struct node nodes[2048] = {0};
    int i = 0, j = 0, total = 0;

    // 初始化入度
    for (i = 0; i < prerequisitesSize; i++) {
        nodes[prerequisites[i][1]].inNode += 1;
    }

    // 找一个 入度 为0的节点
    for (i = 0; i < numCourses; i++) {
        if (!nodes[i].inNode && !nodes[i].visited) {
            nodes[i].visited = true;
            // 更新节点
            for (j = 0; j < prerequisitesSize; j++) {
                if (prerequisites[j][0] == i) {
                    nodes[prerequisites[j][1]].inNode -= 1;
                } 
            }
            total += 1;
            i = -1;
            continue;
        }
    }
    if (total == numCourses) {
        return true;
    } else {
        return false;
    }
}

```
