### 解题思路一：
采用递归暴力法
### 代码
```cpp
class Solution {
public:
    int min = 0x7fffffff;
    void f(long n, int count){
        if(n == 1){
            min = count < min ? count : min;
        }else{
            if(n % 2 == 0){
                f(n/2, count+1);
            }else{
                f(n+1, count+1);
                f(n-1, count+1);
            }
        }
    }
    int integerReplacement(int n) {
        f(n, 0);
        return min;
    }
};
```

### 解题思路二：
首先要明白两个知识点
1. 偶数的最低位一定为0，奇数最低位一定为1
2. 对于偶数的情况，除以二相当于右移一位。

那么有了以上两点知识，当我们遇到奇数后，**是+1还是-1就要看哪一种能够带来更多的0**，因为只要最低位是0就可以直接右移，0越多就能够更多的执行右移运算。更接近与最后的目标1

在奇数的情况有两种：**XX01和XX11，对于前者-1更适合，对于后者+1更适合**

### 代码
```cpp
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 0x7fffffff) return 32;
        int ans = 0;
        while(n != 1){
            if((n&1) == 0){
                n >>= 1;
            }else{
                n += ((n&2) == 0 || n == 3) ? -1 : 1;
            }
            ans++;
        }
        return ans;
    }
};
```