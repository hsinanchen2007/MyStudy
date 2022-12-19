### 解题思路
- 从最低位开始，每次将当前位转为1
- 由于前面已生成序列保证了隔位之差为1bit，当前位之后的数字只需要变化为已生成数列的逆序即可

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        int tmp;
        for(int i=0;i<n;++i){
            tmp = pow(2,i);
            for(int j=tmp-1;j>=0;--j){
                ans.push_back(ans[j]+tmp);
            }
        }
        return ans;
    }
};
```