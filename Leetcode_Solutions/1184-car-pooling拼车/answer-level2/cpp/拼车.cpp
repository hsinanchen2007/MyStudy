## 解题思路

本题主要要考的就是计算同时在车上的人数，判断这个人数是否超过了阀值。

题目假设顺风车是 **先下后上**，因此在计算同时在车上的人数时也需要按照这个规则。为了更好的体现先下后上的规则，首先便得将所有的行程按照从小到大进行排序，排序结束之后便依次计算 i 时刻的下车人数和上车人数。

## 代码


```cpp
// 自定义排序
bool cmp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // 对trips进行排序
        sort(trips.begin(),trips.end(),cmp);
        int passages = trips[0][0];
        int n = trips.size();
        for(int i =1;i<n;i++){
            // 下人
            for(int j=0;j<i;j++){
                if(trips[i][1]>=trips[j][2]){
                    passages -= trips[j][0];
                    // 已经下车的不再进行计算
                    trips[j][0] = 0;
                    if(passages<0) passages = 0;
                }
            }
            // 上人
            passages += trips[i][0];
            // 判断是否超员
            if(passages>capacity) return false;
        }
        return true;
    }
};
```