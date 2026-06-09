英文LeetCode不少是无向图节点，现在成Node节点了，不少纯C代码不能用了
而我也没看到几个用纯C写的，就献丑写了一份
注意vectors每次使用前要初始化

```c []
struct Node ** vectors;

struct Node * dfs(struct Node* s) {
    if (vectors[s->val]) return vectors[s->val];
    vectors[s->val] = (struct Node *) malloc(sizeof(struct Node));
    vectors[s->val]->val = s->val;
    vectors[s->val]->numNeighbors = s->numNeighbors;
    vectors[s->val]->neighbors = (struct Node **) malloc(sizeof(struct Node*) * (s->numNeighbors));
    for (int i = 0; i < s->numNeighbors; ++i) 
        vectors[s->val]->neighbors[i] = dfs(s->neighbors[i]);
    return vectors[s->val];
}

struct Node *cloneGraph(struct Node *s) {
    if (!s) return 0;
    vectors = (struct Node **) calloc(101, sizeof(struct Node*));
    return dfs(s);
}
```
