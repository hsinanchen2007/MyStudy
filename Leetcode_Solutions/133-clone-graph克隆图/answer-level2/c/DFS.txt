### 解题思路
深度优先。
遍历过的节点，打上标记。第二次遍历到的的时候直接返回。

### 代码

```c
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct Node** vector;
struct Node* dfs(struct Node *s){
    if(s == NULL) return s;
    if(vector[s->val]) return vector[s->val];
    struct Node* ret = malloc(sizeof(struct Node));
    ret->val = s->val;
    ret->numNeighbors = s->numNeighbors;
    ret->neighbors = malloc(sizeof(struct Node*)*s->numNeighbors);
    vector[s->val] = ret;
    for(int i=0;i<s->numNeighbors;i++){
        ret->neighbors[i] = dfs(s->neighbors[i]);
    }

    return ret;
}
struct Node *cloneGraph(struct Node *s) {
    vector = (struct Node **) calloc(101, sizeof(struct Node*));

    return dfs(s);

}
```