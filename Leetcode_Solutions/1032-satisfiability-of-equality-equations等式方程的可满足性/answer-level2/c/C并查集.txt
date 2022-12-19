### 解题思路
并查集

### 代码

```c
#define MAX_CNT 26
int g_father[MAX_CNT];
void init(void) {
    int i;
    for (i = 0; i < MAX_CNT; i++) {
        g_father[i] = i;
    }
}

int find(int x) {
    while(x != g_father[x]) {
        g_father[x] = g_father[g_father[x]];
        x = g_father[x];
    }
    return x;
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) {
        return;
    }
    g_father[x] = y;
}
bool equationsPossible(char ** equations, int equationsSize){
    int i, j;
    int x, y;
    init();
    for (i = 0; i < equationsSize; i++) {
        if(equations[i][1] == '=') {
            x = equations[i][0]-'a';
            y = equations[i][3]-'a';
            unite(x,y); 
        }
    }
    for (i = 0; i < equationsSize; i++) {
        if(equations[i][1] == '!') {
            x = equations[i][0]-'a';
            y = equations[i][3]-'a';
            if(find(x) == find(y)) {
                return false;;
            } 
        }
    }
    return true;
}
```