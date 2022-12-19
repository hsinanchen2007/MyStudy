### 解题思路
 模拟下接近平方根时的过程：
假设x的平方根是n:
程序走到：left=n, mid=n, right=n+1,有mid * mid<x,则：left = n+1,
判断left=right,继续：left=n+1, mid=n+1, right=n+1,有mid * mid>x,则：right=n,
判断left>right,结束循环。
此时：left=n+1, mid=n+1, right=n。
所以有判断条件：
```
    if(right * right < x && left * left > x){
        return right;
    }
```
### 代码

```c
int mySqrt(int x){
    long int left = 0;
    long int right = x;
    long long mid = left + (right - left) / 2;
    while(left <= right){
        if(mid * mid < x){
            left = mid + 1;
        }else if(mid * mid > x){
            right = mid - 1;
        }else{
            return mid;
        }
        mid = left + (right - left) / 2;
        //printf("left = %d, mid = %d, right = %d\n", left, mid, right);
    }    
    //printf("for 结束后：left = %d, mid = %d, right = %d\n", left, mid, right);
    if(right * right < x && left * left > x){
        return right;
    }
    return -1;
}

```