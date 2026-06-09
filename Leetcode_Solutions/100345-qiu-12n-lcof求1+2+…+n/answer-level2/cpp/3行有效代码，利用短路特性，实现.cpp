```
class Solution {
public:
    int sumNums(int n) {
        int ans = n;
        ans && (ans += sumNums(n-1));
        return ans;    //短路特性，&&前面为假，后面不计算
    }
};
```
