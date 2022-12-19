执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.2 MB, 在所有 C++ 提交中击败了100.00%的用户

```
class Solution {
public:
    int tribonacci(int n) {
        
        //使用动态规划，把到Tn为止所有的中间答案都保存下来
        int ans[38];
        
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 1;
        
        for(int i=3; i<=n; i++){
            
            ans[i] = ans[i-3] + ans[i-2] + ans[i-1];
        }
        
        return ans[n];
    }
};
```
