### 解题思路
标准回溯法，直接套就行。剪枝条件也很简单，具体实现见代码。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ans;
        vector<int> tem;
        backtrace(ans, tem, k, n, 1);
        return ans;
    }
    void backtrace(vector<vector<int>>& ans, vector<int>& tem, int k, int n, int level){
        if(tem.size() == k){
            if(n == 0){
                ans.push_back(tem);
            }
                return;// 当临时数组的大小等于k时必然返回
        }
        for(int i = level; i <= 9; i++){
            tem.push_back(i);
            backtrace(ans, tem, k, n-i, i+1);
            tem.pop_back();
            if(tem.size() == k-1 && n-i < 0) break;//如果加上i已经超过了n，就没必要进行下去了
        }
    }
};
```