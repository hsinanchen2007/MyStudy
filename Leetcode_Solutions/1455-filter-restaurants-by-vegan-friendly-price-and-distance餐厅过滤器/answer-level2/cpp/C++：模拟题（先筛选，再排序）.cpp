**题解：**
模拟题，按题目意思筛选数据之后再根据rating和id进行排序，最后排序后数组的id添加到ans即可。

**代码如下：**
```cpp
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> res;
        //1、筛选数据
        for(auto &it:restaurants){
            if(veganFriendly==1){
                if(it[2]==1&&it[3]<=maxPrice&&it[4]<=maxDistance){
                    res.push_back(it);
                }
            }
            else{
                if(it[3]<=maxPrice&&it[4]<=maxDistance){
                    res.push_back(it);
                }
            }
        }
        //2、对筛选出来的数据进行排序
        sort(res.begin(),res.end(),[](const auto& a,const auto& b){
            return (a[1]>b[1])||(a[1]==b[1]&&a[0]>b[0]);
        });
        //3、添加id值
        vector<int> ans;
        for(auto& r:res){
            ans.push_back(r[0]);
        }
        return ans;
    }
};
```
