### 解题思路
转其他大佬题解
//分治：对于一个字符串来说，如果要求子串最少出现k次，那么如果某些字母出现的次数小于k,
//这些字母一定不会出现在最长的子串中，并且这些字母将整个字符子串分割成小段，这些小段有可能是最长的
//但是由于被分割了，还是要检查这一小段，如果某些字母出现的次数小于k,会将小段继续分割下去,
//比如字符串"aacbbbdc"，要求最少出现2次,我们记录左右闭区间，，
//第一轮[0,7]，处理"aacbbbdc"，d只出现了一次不满足，于是递归解决区间[0,5]、[7,7]
//第二轮[0,5]，处理"aacbbb"，  c只出现了一次不满足，于是递归解决区间[0,1]、[3,4] 
//第二轮[7,7]，处理"c"，       c只出现了一次不满足，不继续递归
//第三轮[0,1]，处理"aa"，      满足出现次数>=2,ret=2
//第三轮[3,4]，处理"bbb"，     满足出现次数>=2 ret=3;

### 代码

```cpp
class Solution {
public:
    int res=0;
    void dfs(string &s,int k,int l,int r){
        if(r-l+1<k) return ;
        map<char,int>mp;
        for(int i=l;i<=r;i++){
            mp[s[i]]++;
        }
        int ll=l;
        for(int i=l;i<=r;i++){
            if(mp[s[i]]<k){
                dfs(s,k,ll,i-1);
                ll=i+1;
            }
        }
        if(ll!=l&&ll!=r) dfs(s,k,ll,r);
        if(ll==l) res=max(res,r-l+1);
        return ;
    }
    int longestSubstring(string s, int k){
        dfs(s,k,0,s.size()-1);
        return res;
    }
};
```