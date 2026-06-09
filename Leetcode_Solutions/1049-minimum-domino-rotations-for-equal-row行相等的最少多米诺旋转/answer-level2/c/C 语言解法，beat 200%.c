### 解题思路

# ***哈希表简单粗暴***
![image.png](https://pic.leetcode-cn.com/6afb94cf06d6ad15d7fe924c570c899831f264ec2e15272d393f1b61b8fbed0a-image.png)

### 代码

```c
int minDominoRotations(int* A, int ASize, int* B, int BSize){
    int hash[7] = {0};
    for(int i=0; i<ASize; i++){
        hash[ A[i] ] ++;
        hash[ B[i] ] ++;
    }

    int max = INT_MIN,target=0;
    for(int i=1;i<=6;i++){
        if(hash[i]>max){
            max = hash[i]; //出现的次数
            target = i; //记录是哪一个数字
        }
    }
    printf("target=%d",target);
    if(max<ASize) return -1; 
    //若出现的次数小于数组的大小的话，则不可能做到

    // 开始翻转
    int cnt1=0;
    for(int i=0;i<ASize;i++){//假设 A 数组可以实现
        if(A[i] == target) continue;
        if(B[i] != target) return -1;
        else cnt1++;//统计需要翻转的次数
    }
    int cnt2=0;
    for(int i=0;i<BSize;i++){//假设 B 数组可以实现
        if(B[i] == target) continue;
        if(A[i] != target) return -1;
        else cnt2++;//统计需要翻转的次数
    }
    return cnt1<cnt2?cnt1:cnt2;//返回较小者

}
```