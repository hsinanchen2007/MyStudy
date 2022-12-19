### 解题思路


### 代码

```c
int mySqrt(int x){

    int max=x,min=0;
    int temp,mid;

    if(x==1|| x==0)
        return x;

    while (max >= min) {
        mid = min + (max-min)/2;
        temp = x/mid;
          
        if(temp == mid)
            return mid;
        else if(temp < mid)
            max = mid - 1;
        else
            min = mid + 1;
    }
    //根据循环条件，最终的结果一定是min>max, 
    //并且 max的平方小于x，min的平方大于x（直接返回mid的情况除外）
    return max;
}
```