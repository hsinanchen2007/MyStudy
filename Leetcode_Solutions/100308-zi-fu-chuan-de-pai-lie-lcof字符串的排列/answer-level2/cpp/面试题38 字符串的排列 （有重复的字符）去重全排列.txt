### 解题思路
**全排列 去重**
和没有重复元素的全排列类似 
但这个要考虑去重（用set 最后再转成vector）
同时 用used来表示是否使用过 （如aab这种情况）


### 代码

```cpp
class Solution {
public:
    vector<string> permutation(string s) {
        set<string> res1;
        string temp="";
        vector<bool> used(s.size(),false);
        fun(res1,used,temp,s,0);
        vector<string> res(res1.begin(),res1.end());
        return res;
    }
    void fun(set<string> &res,vector<bool> &used, string temp, string &s, int k){
        if(temp.size()==s.size()){
            res.insert(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(used[i]==true)
                continue;
            used[i]=true;
            //temp= temp+s[i];
            fun(res,used,temp+s[i],s,k+1);
            used[i]=false;
        }
    }
};
```