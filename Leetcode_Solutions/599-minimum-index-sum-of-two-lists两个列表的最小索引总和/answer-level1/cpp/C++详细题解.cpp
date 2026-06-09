思路都在代码注释里
```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> ans;
        vector<pair<int,string>> No;
        unordered_map<string,int> l1;
        unordered_map<string,int> l2;
        int i = 0;
        int j = 0;
        int count;
        for(auto re1 : list1){ //将餐厅名称与索引映射
            l1[re1] = i;
            ++ i;
        }
        for(auto re2 : list2){
            l2[re2] = j;
            ++ j;
        }
        for(auto name : list2){ //找到两个列表内都出现的餐厅名称，并计算索引和
            int sum = 0;
            if(l1.count(name)){
                sum = l1[name] + l2[name];
                No.push_back({sum,name});
            }
        }
        int target = INT_MAX;
        for(int p = 0; p < No.size(); ++ p){ //找到最小索引和的大小
            target = No[p].first < target ? No[p].first : target;
        }
        for(int f = 0; f < No.size(); ++ f){ //将等于最小索引和的餐厅名放入答案列表
            if(No[f].first == target){
                ans.push_back(No[f].second);
            }
        }
        return ans;
    }
};
```
