### 解题思路
使用sort函数对所有string进行排序，相等的就是符合要求的，存到一个vector里，然后遍历一下哈希表

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //保存排序好的数组，空间复杂度是O(n)
        vector<string> sorted(strs);
        vector<vector<string>> re;
        unordered_map<string, vector<int>> mp;
        //由于使用了sort(), O(nlogn)复杂度
        for (int i=0; i<sorted.size(); i++) {
            sort(sorted[i].begin(), sorted[i].end());
            mp[sorted[i]];
            mp.at(sorted[i]).push_back(i);
        }
        //两层循环，但其实是O(n)复杂度
        for (unordered_map<string, vector<int>>::iterator i = mp.begin(); i != mp.end(); i++) {
            vector<string> temp;            
            for (int j=0; j<i->second.size(); j++) {
                temp.push_back(strs[i->second[j]]);
            }
            re.push_back(temp);
        }
        return re;
    }
};
```