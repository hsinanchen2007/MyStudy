
区间法：
1、先算出起始位置需要加的数
2、接着算出结束位置后一个，再减去对应的数据
3、从前累加都结尾

执行用时 :112 ms, 在所有 c 提交中击败了83.15%的用户
内存消耗 :19.5 MB, 在所有 c 提交中击败了100.00%的用户

int* getModifiedArray(int length, int** updates, int updatesSize, int* updatesColSize, int* returnSize){
    int* ret;
    ret = (int*)malloc((length + 1) * sizeof(int));//防止溢出
    memset(ret, 0, (length +1) * sizeof(int));
    for(int i = 0; i < updatesSize; i++){
        int start = updates[i][0] > length - 1 ? length -1 : updates[i][0];
        int stop = updates[i][1] > length - 1 ? length -1 : updates[i][1];
        ret[start] += updates[i][2];
        ret[stop + 1] -= updates[i][2];
    }
    for(int i = 1; i < length; i++){
        ret[i] += ret[i - 1];
    }
    *returnSize = length;

    return ret;
}