滑动窗口一般用于解决找出查找满足一定条件的**连续区间**的性质（长度等）的问题。对应的题型常常是找“子串”。
一般右指针自然向右滑动，找到滑动条件非常关键，找到即可以得到题解。

```
int max(int a,int b){
    return (a>b)?a:b;
}

int longestOnes(int* A, int ASize, int K){
    int right = 0;
    int left = 0;
    int change = 0;
    int ret = 0;

    while (right < ASize){
        if (A[right] == 0){
            change++;
        }
        right++;
        while(change > K){
            if (A[left] == 0){
                change--;
            }
            left++;
        }
        ret = max(ret, right - left);
    }
    return ret;
}
```
