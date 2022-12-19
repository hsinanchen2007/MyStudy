### 解题思路
此处撰写解题思路
方法一
就是一个最简单的思路，以当前位置字符为结尾的无重复字符子串的长度怎么确定呢？从当前位置往前搜索，找到就停止，长度为i-j；
方法二
只是我的一种练习，尝试使用hash表，每次都更新hash表，整个字符串中出现相同的字符，首先确定前面已经出现的重复字符是否在我考虑的无重复子串当中，不在的话就直接在dp[i-1]的基础上+1，如果存在，dp[i]=i-重复字符的索引，然后每次到一个位置都要更新一下hash表中的值，key是字符，value是到目前为止发现给字符出现靠后的位置索引。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s){
        int n=s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int maxLen=1, start=-1;;
        for(int i=1; i<n; i++){
            for(int j=i-1; j>=start+1; j--){
                if(s[i]==s[j]){
                    start=j;
                    break;
                }
            }
            maxLen = max(maxLen, i-start);
        }
        /*int dp[n];
        dp[0]=1;
        int maxLen=dp[0];
        map<char, int> hash;
        hash[s[0]] = 0;
        for(int i=1; i<n; i++){
            if(hash.find(s[i])!=hash.end()){
                if(hash[s[i]]>=i-dp[i-1]) dp[i]=i-hash[s[i]];
                else dp[i]=dp[i-1]+1;
            }
            else dp[i]=dp[i-1]+1;
            hash[s[i]]=i;
            maxLen=max(maxLen, dp[i]);
        }*/
        return maxLen;
    }
};
```