由高中知识可得，杨辉三角每一行均为组合数，而组合数存在递归公式：

C(n,k+1) = C(n,k) * (n-k) / (k+1)

由上述公式，前一半数值可通过递归得到，而后一半与前一半对称，直接赋值即可

不过，要小心爆int范围的bug，最好用long long存储中间变量

代码：
```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1);
        ans[0] = 1;
        if(rowIndex) {
            ans[1] = rowIndex;
            for(int i = 1 ; i <= (rowIndex >> 1) ; i++) {
                long long temp = (long long)(ans[i - 1]) * (rowIndex + 1 - i);
                ans[i] = temp / i;
            }
            for(int i = (rowIndex >> 1) + 1 ; i <= rowIndex ; i++)
                ans[i] = ans[rowIndex - i];
        }
        return ans;
    }
};
```
