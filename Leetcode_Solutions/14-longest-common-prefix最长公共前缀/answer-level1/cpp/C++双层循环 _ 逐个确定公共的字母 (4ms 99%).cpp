### 解题思路
先遍历一遍找到最短单词长度；
再双层循环：外层循环字母，内层循环单词，逐个确定公共的字母

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 0或1个单词的vector
        if (strs.size()==1) return strs[0];
        if (strs.size()==0) return "";

        // 单词最短长度
        int min_len = INT32_MAX;
        for (int j=0; j<strs.size(); ++j) {
            int len = strs[j].size();
            if (len<min_len) min_len = len;
        }

        string result;
        char flag; 
        for (int i=0; i<min_len; ++i){ //遍历字母
            for (int j=0; j<strs.size()-1; ++j) { //遍历单词：第一个--倒数第二个
                flag = strs[j][i];
                if (flag != strs[j+1][i]) return result;
            }
            result += flag;
        }       
        return result;
    }
};



```