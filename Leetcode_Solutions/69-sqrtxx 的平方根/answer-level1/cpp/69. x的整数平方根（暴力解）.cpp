### 解题思路
平方根的平方不大于x。
记i的平方s,当平方s大于x时，返回i-1。
用long long类型来防止溢出。


执行用时 :24 ms, 在所有 C++ 提交中击败了14.38%的用户
内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
class Solution {
public:
    int mySqrt(int x) {
        long long i=0;
        long long   s=0;
        while(s <= x){
            i++;
            s=i*i ;
            
        }
         return i-1;
    }
};
```
### 解题思路
用除法x/i 代替乘法防止溢出。但是时间消耗更长。

执行用时 :112 ms, 在所有 C++ 提交中击败了5.29%的用户
内存消耗 :5.8 MB, 在所有 C++ 提交中击败了100.00%的用户

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int i=1; 

        while(x/i >= i)
            i++;   

    return i-1;
    }
};
```