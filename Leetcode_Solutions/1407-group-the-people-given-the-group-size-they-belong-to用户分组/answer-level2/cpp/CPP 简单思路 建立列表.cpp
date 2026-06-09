### 解题思路
建立一个一维数组list
list中的每个元素为用户分组号，与res对应，进行约束
如list[0]的值为3，则res[0]中的元素不超过3个，如果超过则建立list[1]与res[1]
每次查找list中是否有当前用户分组的值并对应res中是否满了来确定将当前用户归到哪里

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<int> list;
        vector<vector<int>> res;
        for(int i=0;i<groupSizes.size();i++){
            int now = -1;
            for(int j=0;j<list.size();j++){
                if(list[j]==groupSizes[i]&&res[j].size()!=list[j]){
                    now = j;
                    break;
                }
            }
            if(now==-1){
                list.push_back(groupSizes[i]);
                res.push_back(vector<int>{i});
            }else{
                res[now].push_back(i);
            }
        }
        return res;
    }
};
```