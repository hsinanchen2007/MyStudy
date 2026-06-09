### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int n=words.size();
        if(!n)
            return 0;
        unordered_map<string,vector<int>> ma;
        for(int i=0;i<n;i++){
            ma[words[i]].push_back(i);              
        }
        vector<int> v1=ma[word1],v2=ma[word2];
        int len1=v1.size(),len2=v2.size();
        int l=0,r=0,res=INT_MAX;
        while(l<len1&&r<len2){
            int t=v1[l]-v2[r];
            res=min(res,abs(t));
            if(t>0)
                r++;
            else if(t<0)
                l++;
            else
                return 0;
        }
        return res;
    }
};
//map<string,vector<int>>根据索引找到对应位置，然后两个指针滑动，寻找绝对值最小的差值
```