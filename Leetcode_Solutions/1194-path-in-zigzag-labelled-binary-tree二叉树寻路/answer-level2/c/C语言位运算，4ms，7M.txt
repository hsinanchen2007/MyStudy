思路在评论中看到大神的位运算，发现好巧妙自己试了一下。
```
int* pathInZigZagTree(int label, int* returnSize){
    int count = 0;
    int tmp = label;
    //确认returnSize
    while (tmp != 0){
        tmp >>= 1;
        count++;
    }
    *returnSize = count;
    int *ret = (int *)malloc(sizeof(int)*count);
    //从末置位开始写入
    for( int i = count - 1; i > -1;i--){
        ret[i]=label;
        //将label的值右移一位，层数下降
        label >>= 1;
        //异或操作，实现题目中的反转顺序，如果没有交叉顺序的话不需要这一步操作就可以得到其父节点。
        label ^= (int )pow(2,i-1)-1;
    }
    return ret;
}
```
