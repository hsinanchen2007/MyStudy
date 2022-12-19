### 解题思路
首先看到这个题干，只有大小写字母，想到了可以使用哈希表来储存字母和出现的个数
首先根据规律我们知道，如果字母出现的次数是偶数的话，那么可以直接成为回文串
的字串，可以直接将其次数加到结果中；如果是奇数的话，只有一组（一个）奇数可以出现在最后的回文串中，因为左右对称。那么我们就可以找第一组出现的奇数，将出现个数全部加到结果中，接下来出现的奇数，我们需要将其-1，变为偶数，这样就不会出现“孤立个体”，从而将其-1后的结果加到结果里面。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        if(s.empty()) return 0;
        int maxCount=0;
        unordered_map<int,int> hashtable;
        for(auto i=0;i<s.size();++i){
            hashtable[s[i]]++;
        }
        bool first=true;
        for(auto iter=hashtable.begin();iter!=hashtable.end();++iter){
            if(iter->second%2==0) maxCount+=iter->second;
            else{
                if(first){
                    maxCount +=iter->second;
                    first=false;
                } 
                else maxCount+=iter->second-1;
            }
        }
        return maxCount;
    }
};
```