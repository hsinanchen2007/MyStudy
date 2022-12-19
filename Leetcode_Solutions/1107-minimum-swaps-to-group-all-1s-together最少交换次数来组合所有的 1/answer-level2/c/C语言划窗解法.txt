![image.png](https://pic.leetcode-cn.com/61ac2f8b15681d405d68dc2ba556e339674a21f01541eb27f705e0360b3285df-image.png)
```
int minSwaps(int* data, int dataSize){
    int num = 0;
    int rst = 0;
    for (int i = 0; i < dataSize; i++) {
        if (data[i] == 1) num++;
    }
    if (num <= 1) return rst;
    int onecnt = 0;
    for (int i = 0; i < num; i++) onecnt += data[i];
    int left = 0;
    int right = num -1;
    rst = onecnt;
    while (right < dataSize -1) {
        onecnt -= data[left++];
        onecnt += data[++right];
        rst = rst > onecnt ? rst : onecnt;
    }
    return num - rst;
}
```
