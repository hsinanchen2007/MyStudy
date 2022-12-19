### 解题思路
滑动窗口的应用，第一次见感觉很负责，b站看看视频再做几道题就慢慢熟悉了。

### 代码

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<int> se;    // 保存当前窗口的字串的组成集合，如 se=set(['a', 'b'])
        int i=0;        // i是较大的数，如果窗口从左往右下标增加，则i在窗口最右方
        int j=0;        // j在窗口最左方
        int maxlen=0;   // 字串最大长度

        while (i<s.length() && j < s.length()){
            if(se.find(s[i]) != se.end()){  // 如果最新元素s[i]已经在上一个字串中
                se.erase(s[j]);             // 把窗口左端j的元素去掉，并右移窗口，窗口肯定变小了
                j++;                        // 右移左边窗口
            }
            else{
                maxlen = max(maxlen, i-j+1);// 算出当前的窗口长度，+1因为比如i=0,j=2,字串长为3
                se.insert(s[i]);            // 把新元素加入集合
                i++;                        // 右移右边窗口
            }
        }

        return maxlen;
    }
};
```