### 解题思路
挨个比较就是了，第一个跟第二个比较，得到这两个的最长公共前缀，然后用这个结果跟第三个比较，依次进行，直到最后一个。

算法复杂度: 两个字符串比较M次， M最坏为当前比较的字符串一样，长度都是M， 遍历strs N次， 最坏所有字符串都一样，则为
O(N*M)

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = "";
        int i = 1; 
        res = strs[0];
        while(i < strs.size()) {
            res = getCommonStr(res, strs[i]);
            i++;
        }
        return res;
    }


    //找到两个字符串的最长公共前缀
    string getCommonStr(string s1, string s2) {
        string res = "";
        int i = 0;
        int j = 0;
        while(i < s1.size() && j < s2.size()) {
            if(s1[i] == s2[j]) {
                res += s1[i];
                i++;
                j++;
            }
            else {
                break;
            }
        }
        return res;
    }
};
```