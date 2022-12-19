### 解题思路
在每行后面补一个零，然后倒序计算当前行，第j行第1个元素是1，其他元素是j-1行当前位置元素和前一个元素的和。
        1 0
        1 1 0
        1 2 1 0
        1 3 3 1


### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        
        if(rowIndex == 0){
            return ans;
        }

        for(int i=1; i<=rowIndex; i++){
            ans.push_back(0);
            for(int j=i; j>=1; j--){
                ans[j] = ans[j-1] + ans[j];
            }
        }
        return ans;
    }
};
```