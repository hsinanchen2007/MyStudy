### 动态规划
### 时间/空间复杂度
时间复杂度：O（n）
空间复杂度：O (n)
### 代码
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz=s.size();
        if(s.empty()) return 0;
        map<char,int>lastIndexs;//index
        vector<int> dp(sz,0);
        int res=0;
        for(int i=0;i<sz;++i){
            if(i==0){
                lastIndexs[s[i]]=i;
                dp[i]=1;
            }else if(i-1>=0&&lastIndexs.find(s[i])==lastIndexs.end()){
                dp[i]=dp[i-1]+1;
                lastIndexs[s[i]]=i;
            }else if(i-1>=0&&lastIndexs.find(s[i])!=lastIndexs.end()){
                int d=i-lastIndexs[s[i]];
                lastIndexs[s[i]]=i;
                if(d<=dp[i-1]) dp[i]=d;
                else dp[i]=dp[i-1]+1;
            }
            res=max(res,dp[i]);
        }
        return res;
    }
};
```
```cpp
//改进动态规划，不用dp数组
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        if(s.size()==1) return 1;
        vector<int> lastLoc(128,-1);//char,last index
        int res=0;
        int len=0;
        for(int i=0;i<s.size();++i){
            int curch=s[i]-' ';
            if(i==0){
                res++;
                lastLoc[curch]=i;
            }else if(lastLoc[curch]==-1){
                res++;
                lastLoc[curch]=i;
            }else if(lastLoc[curch]!=-1){
                res=(i-lastLoc[curch])>res ? res+1:(i-lastLoc[curch]);
                lastLoc[curch]=i;
            }
            len=max(res,len);
        }
        return len;
    }
};
```
### Map法
使用一个map记录字符和它所对应的下标，遍历整个字符串，如果map中没有出现过当前这个字符就将该字符和其下表存入map中。如果出现过，说明有重复了
，则找到map中存在的当前字符和它的下标，从下标开始到当前字符全部重新存到set里面，并更新最后的结果。
### 时间/空间复杂度
时间复杂度：O（nlogn）
空间复杂度：O（n）
### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int res=0;
        unordered_map<char,int> M;//char,index
        int count=0;
        for(int i=0;i<s.size();++i){
            auto cur=M.find(s[i]);
            if(cur==M.end()){
                M[s[i]]=i;
                count++;
            }else{
                int beg=cur->second+1;
                M.clear();
                for(int j=beg;j<=i;++j){
                    M[s[j]]=j;
                }
                count=M.size();
            }
            res=max(res,count);
        }
        return res;
    }
};
```