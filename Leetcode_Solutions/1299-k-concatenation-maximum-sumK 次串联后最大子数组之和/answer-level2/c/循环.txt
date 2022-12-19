### 解题思路
此处撰写解题思路

### 代码

```c
int kConcatenationMaxSum(int* arr, int arrSize, int k){
//如果arr全为正数
//如果arr全为负数 
//如果arr有正有负  ？？？和>0
    int i,n=0;
    long long s=0,cur=0,max=0;//s为总和，n为负数个数
    for(i=0;i<arrSize;i++){
        cur=(cur+arr[i]>arr[i])?cur+arr[i]:arr[i];
        max=max>cur?max:cur;
        s+=arr[i];
        if(arr[i]<0) n++;
        max=max%(1000000007);
        s=s%(1000000007);
        cur=cur%(1000000007);
    }
    if(s>0&&k==0) return s*k%(1000000007);
    else if(n==arrSize) return 0;
    else if(k==1) return max%(1000000007);
    if(s>0)
        max=(max+(k-1)*s)%(1000000007);
    else if(s<=0){
        for(i=0;i<arrSize;i++){
            cur=(cur+arr[i]>arr[i])?cur+arr[i]:arr[i];
            max=max>cur?max:cur;
            max=max%(1000000007);
            cur=cur%(1000000007);
        }
    }
    return max;
}
```