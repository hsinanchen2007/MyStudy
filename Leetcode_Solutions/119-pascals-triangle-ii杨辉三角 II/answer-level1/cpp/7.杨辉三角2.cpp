### 解题思路
迭代的思路是真的很妙

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int i=0;i<rowIndex+1;i++){
            ans.push_back(1);//先把这行填满1
            for(int j=i-1;j>0;j--){//第一个和最后一个1不用迭代
                ans[j]+=ans[j-1];
            }
        }
        return ans;
    }
};
```