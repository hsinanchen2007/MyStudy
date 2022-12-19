```
int Find(int root, int *pos)
{
    int son = root;
    int tmp;
    while (root != pos[root]) {
        root = pos[root];
    }
    while (son != root) {
        tmp = pos[son];
        pos[son] = root;
        son = tmp;
    }
    return root;
}
void Merge(int root1, int root2, int *pos)
{
    int par1 = Find(root1, pos);
    int par2 = Find(root2, pos);
    if (par1 == par2) {
        return;
    }
    pos[par1] = par2;
    return;
}
bool canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int *pos = (int *)calloc(roomsSize, sizeof(int));
    for (int i = 0; i < roomsSize; ++i) {
        pos[i] = i;
    }
    for (int i = 0; i < roomsSize; ++i) {
        for (int j = 0; j < roomsColSize[i]; ++j) {
            int par = Find(rooms[i][j], pos);
            if (par == 0) {
                continue;
            }
            Merge(rooms[i][j], i, pos);
        }
    }
    for (int i = 0; i < roomsSize; ++i) {
        int par = Find(i, pos);
       // printf("i %d, par %d\n", i, par);
        if (Find(i, pos) != 0) {  
            free(pos);
            return false;
        }
    }
    free(pos);
    return true;
}
```
