### 解题思路
Union Find思路求解等效序列问题，重要在于Union的时候保证字典序，要求字典序靠前面的做根节点。

### 代码

```c
int UnionMap[27];

void init() {
    int i = 0;
    for (i = 0; i < 27 ; i++) {
        UnionMap[i] = i;
    }
}

int findroot(int a) {
    while(UnionMap[a] != a) {
        a = UnionMap[a];
    }
    return a;
}
void Union(char a, char b) {
    int aindex = a - 'a';
    int bindex = b - 'a';
    int aroot = findroot(aindex);
    int broot = findroot(bindex);
    if (aroot != broot) {
        if (aroot <= broot) {
            UnionMap[broot] = aroot;
        } else {
            UnionMap[aroot] = broot;
        }
    }
}
char * smallestEquivalentString(char * A, char * B, char * S){
    init();
    int len = strlen(A);
    int i = 0;
    for (i = 0; i < len; i++) {
        Union(A[i], B[i]);
    }
    int slen = strlen(S);
    char *ret = malloc(sizeof(char) * (slen + 1));
    for (i = 0; i < slen; i++) {
        ret[i] = (char)(findroot(S[i] - 'a') + 'a');
    }
    ret[i] = 0;
    return ret;
}
```