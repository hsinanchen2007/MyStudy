```
bool isneighbor(char *stra, char *strb, int len) {
    int diff = 0;
    while (*stra) {
        if (*stra++ != *strb++) {
            diff++;
            if (diff > 2) {
                return false;
            }
        }
    }
    return true;
}

struct MyNode {
    int index;
    int father;
};

struct MyNode *ns;
int FindHead(int index) {
    if (ns[index].father == index) {
        return index;
    }    
    ns[index].father = FindHead(ns[index].father);
    return ns[index].father;
}

void Union(int indexa, int indexb) {
    int heada = FindHead(indexa);
    int headb = FindHead(indexb);
    ns[heada].father = headb;
}

int numSimilarGroups(char ** A, int ASize)
{
    int len = strlen(A[0]);
    ns = malloc(sizeof(struct MyNode) * ASize);
    for (int i = 0; i < ASize; i++) {
        ns[i].index = i;
        ns[i].father= i;
    }

    for (int i = 1; i < ASize; i++) {
        for (int j = 0; j < i; j++) {
            if (isneighbor(A[i], A[j], len)) {
                Union(i, j);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < ASize; i++) {
        if (ns[i].father == i) {
            res++;
        }
    }

    free(ns);
    return res;
}
```
