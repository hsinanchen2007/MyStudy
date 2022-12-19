

void permutations(char *tiles, int nextPos, int cnt, int *rst);
void swap(char *tiles, int nextPos, int i);
bool isDupl(char *tiles, int nextPos, int i);

int numTilePossibilities(char * tiles){
    int cnt = 0, sum = 0;
    //计算总共多少个字符
    for(int i = 0; i < strlen(tiles); i++) {
        if(tiles[i] >= 'A' && tiles[i] <= 'Z') {
            cnt++;
        }
    }

    permutations(tiles, 0, cnt, &sum);

    return sum;
}

void permutations(char *tiles, int nextPos, int cnt, int *rst) {
    //注意这里不能含有等于0情况，等于0相当于第一次进来无论如何都要+1
    if(nextPos > 0 && nextPos <= cnt) { 
        (*rst)++; //结果收集必须放到这里，递归到算一次有效路径，#3步骤一次搜索完成
    }
    if(nextPos >= cnt) { // 这里有等于是因为nextpos从0开始
        return;
    }
    // 根据选择列表做选择
    for(int i = nextPos; i < cnt; i++){
        //去重判断
        if(isDupl(tiles, nextPos, i)) {
            continue;
        }
        //#1 进行选择
        // 0 1 2
        // A B C
        // A C B 
        // 固定位置 0（0层树）... 遍历剩余选择列表
        // 固定位置 1（1层树）... 通过交换 1 2 位置上的字符进行一次排列
        // 固定位置 2（2层树）... 遍历剩余选择列表
        swap(tiles, nextPos, i);
        //#2 回溯
        permutations(tiles, nextPos+1, cnt, rst);
        //#3 取消选择
        swap(tiles, nextPos, i);
    }
}

void swap(char *tiles, int nextPos, int i){
    char tmp;
    tmp = tiles[nextPos];
    tiles[nextPos] = tiles[i];
    tiles[i] = tmp;
}

bool isDupl(char *tiles, int nextPos, int i){
    char tmp = tiles[i];
    for(int j = nextPos; j < i; j++){
        if(tmp == tiles[j]){
            return true;
        }
    }
    return false;
}