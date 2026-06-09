### 解题思路
此处撰写解题思路

### 代码

```c
int mySqrt(int x){
    int low=0,high=x,mid;
    //if(x==0) return 0;
    while(low<high){
        mid=(low+high)/2+(low+high)%2;
        if(mid>x/mid) high=mid-1;
        else if(mid==x/mid) return mid;
        else low=mid;
    }
    return low;
}
```