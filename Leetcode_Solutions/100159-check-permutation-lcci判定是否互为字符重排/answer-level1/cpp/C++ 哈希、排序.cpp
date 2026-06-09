### 解题思路


### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
         //排序
         sort(s1.begin(),s1.end());
         sort(s2.begin(),s2.end());
         if(s1.size()==s2.size()){
             for(int i=0;i<s1.size();i++){
                 if(s1[i]!=s2[i])return false;
             }
             return true;
         }
         return false;

        //哈希表
        unordered_map<char,int>mp;
        for(auto i : s1){
            mp[i]++;
        }
        for(auto i : s2){
            mp[i]--;
            if(mp[i]<0)return false;
        }
        return true;
    }
};
```