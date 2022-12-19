### 解题思路
1. 自定义排序，如果两个数字的1的数目相同，按照从小到大排序。
2. **看代码能懂**

### 代码

```cpp
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        using PII = pair<int, int>;
        vector<PII> tmp;
        //统计每个数字中，二进制1出现的次数，然后组成pair对
        for(int i = 0; i < arr.size(); i++){
            int cnt = 0;
            for(int j = 0; j < 32; j++){
                if(arr[i] & (1 << j)) cnt++;
            }
            tmp.push_back({arr[i], cnt});
        }
        //自定义排序
        auto comp = [](PII pa, PII pb){
            return pa.second == pb.second ? pa.first < pb.first : pa.second < pb.second;
        };
        sort(tmp.begin(), tmp.end(), comp);
        vector<int> ans; 
        for(auto pr : tmp){
            ans.push_back(pr.first);
        }
        return ans;
    }
};
```