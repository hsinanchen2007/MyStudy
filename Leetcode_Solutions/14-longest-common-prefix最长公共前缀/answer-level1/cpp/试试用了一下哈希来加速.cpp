### 解题思路
两个字符串比较前缀，先截等长，再用哈希值表示两个字符串（用101作底），缩短一个字符只需两边同时整除一下底数，直到两个值相等（或都变0），根据缩短了多少次返回剩下的字符串（公共前缀），公共前缀再跟下一个比，一旦公共变空字符串就结束。题目有点坑人，样例居然有空集合，WA了几次。该方法速度挺快的。

### 代码

```cpp
class Solution {
public:
    long long hash(string str){
        int base = 101;
        long long result = 0;
        for(int i=0;i<str.length();i++){
            result = base * result + (str[i] - 'a');
        }
        return result;
    }

    string lcp(string str1, string str2){
        int len1 = str1.length(), len2 = str2.length();
        int minlen = min(len1, len2);
        long long hash1 = hash(str1.substr(0, minlen)), hash2 = hash(str2.substr(0, minlen));
        while(hash1 != hash2 && minlen != 0){
            hash1 = hash1 / 101;
            hash2 = hash2 / 101;
            minlen--;
        }
        return str1.substr(0, minlen);
        
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)return "";
        string result = strs[0];
        for(int i=1;i<strs.size();i++){
            result = lcp(result, strs[i]);
            if(result.length() == 0)return "";
        }
        return result;
    }
};
```