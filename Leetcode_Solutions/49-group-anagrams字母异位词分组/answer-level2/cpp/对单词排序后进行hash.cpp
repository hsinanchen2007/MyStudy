### 解题思路
1. 将当前的str排序后的结果作为map的key，假如该map中含有key，则将单词假如对应key的value-1下标的vector中
2. 否则在map中初始化该key对应的value，然后将该单词加入

### 代码

```cpp
class Solution {
public:
    map<string,int> mp;
    vector<vector<string>> result;
    int group_num = 1;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto str:strs){
            string key = str;
            sort(key.begin(), key.end());
            if(mp[key] == 0){
                mp[key] = group_num++;
                if(mp[key]-1 == result.size()) result.emplace_back();
                result[mp[key]-1].push_back(str);
            }
            else{
                result[mp[key]-1].push_back(str);
            }
        }
        return result;
    }
};
```