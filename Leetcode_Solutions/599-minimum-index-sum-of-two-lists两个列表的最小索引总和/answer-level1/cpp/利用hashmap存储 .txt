### 解题思路
先将一个vector装进map里面 key为string value为int  
再利用一个for循环遍历同时利用find函数判断是否找到相同的string

### 代码

```cpp
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int l1size=list1.size();
        int l2size=list2.size();
        unordered_map<string,int>mp;
        vector<string> vc;
        int minn=INT_MAX;
        for(int i=0;i<l1size;i++){
            mp[list1[i]]=i;
        }
        for(int j=0;j<l2size;j++){
            if(mp.find(list2[j])!=mp.end()){
                mp[list2[j]]+=j;
                if(mp[list2[j]]<minn){
                    minn=mp[list2[j]];
                    vc.clear();
                    vc.push_back(list2[j]);
                }else if(mp[list2[j]]==minn){
                    vc.push_back(list2[j]);
                }
            }
        }
        return vc;
    }
};
```