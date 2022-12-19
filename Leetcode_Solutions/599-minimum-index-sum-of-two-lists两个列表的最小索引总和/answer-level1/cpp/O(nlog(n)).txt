### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
       map<string,int> mp;
       for(int i=0;i<list1.size();i++){
           mp[list1[i]]=i;
       }
       vector<string> ans;
       int min1=2001;
       for(int i=0;i<list2.size();i++){
           if(mp.count(list2[i])!=0){
               int min2=min(min1,mp[list2[i]]+i);
               if(mp[list2[i]]+i==min1){
                   ans.push_back(list2[i]);
               }
               if(min2<min1){
                   ans.clear();
                   ans.push_back(list2[i]);
               }
               min1=min2;
           }
       }
       return ans;
    }
};
```