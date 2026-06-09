```
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */
struct MyNode {
    int val;
    int index;
    UT_hash_handle hh;
};

struct MyNode *hash;

void HashAdd(int val, int index)
{
    struct MyNode *s = malloc(sizeof(*s));
    s->val = val;
    s->index = index;
    HASH_ADD_INT(hash, val, s);
}

struct MyNode *HashFind(int val)
{
    struct MyNode *s;
    HASH_FIND_INT(hash, &val, s);
    return s;
}

struct Node *ns;
int cnt;

struct Node *Process(struct Node *root)
{
    struct Node *node = &ns[cnt++];
    node->val = root->val;
    node->numNeighbors = root->numNeighbors;
    node->neighbors = malloc(sizeof(struct Node *) * node->numNeighbors);
    HashAdd(root->val, cnt - 1);

    //printf("val %d ,cnt %d\n", node->val, node->numNeighbors);
    for (int i = 0; i < root->numNeighbors; i++) {
        struct MyNode *s = HashFind(root->neighbors[i]->val);
        if (s != NULL) {
            node->neighbors[i] = &ns[s->index];
        } else {
            node->neighbors[i] = Process(root->neighbors[i]);
        }
       // printf("%d nei val %d\n", node->val, node->neighbors[i]->val);
    }

    return node;
}

struct Node *cloneGraph(struct Node *s) 
{
    if (s == NULL) {
        return NULL;
    }

    hash = NULL;
    ns = malloc(sizeof(*ns) * 100);
    cnt = 0;
    return Process(s);
}
```
