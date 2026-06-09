### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> hash;
        int min_sum=INT_MAX;
        vector<string> res;
        for(int i=0;i<list1.size();i++){
            hash[list1[i]]=i;
        }
        for(int j=0;j<list2.size();j++){
            if(hash.count(list2[j])){
                int sum=hash[list2[j]]+j;
                if(sum<min_sum) {
                    min_sum=sum;
                    res.clear();
                    res.push_back(list2[j]);
                }
                else if(sum==min_sum){
                    res.push_back(list2[j]);
                }
            }
        }
        return res;

    }
};
```