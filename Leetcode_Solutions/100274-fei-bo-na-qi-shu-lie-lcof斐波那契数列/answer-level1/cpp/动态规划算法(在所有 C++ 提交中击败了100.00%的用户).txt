### 解题思路
此处撰写解题思路
/*解题思路：将计算结果保留下来，下次直接拿来用，不用再重复计算*/

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.8 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
    /*解题思路：将计算结果保留下来，下次直接拿来用，不用再重复计算了*/
public:
    int fib(int n) {
        vector<int> result(n+1,-1);
        return  fibFunc(n,result);
    }
    int fibFunc(int n,vector<int> &result) {
        if(n == 0 || n == 1) {
            return result[n] = n;
        }
        if(result[n]!= -1){
            return result[n];
        }
        return result[n] = (fibFunc(n-1,result) + fibFunc(n-2,result))%1000000007;
    }
};
```