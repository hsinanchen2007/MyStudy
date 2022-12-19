### 解题思路
思路：一共有三种状态，全为大写字母，开头为大写字母其后为小写字母，全为小写字母；
全为大写字母或全为小写字母要求大写/小写字母的出现次数与字符长度相等；开头为大写
字母其后为小写字母要求大写字母只出现一次，且与小写字母出现次数相加等于字符串长
度并且字符串开头为大写 。

### 代码

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
    	int wLen = word.size();
    	int bCnt = 0, lCnt = 0;
    	// 统计某个单词的大小写字母个数 
        for (int i = 0; i < wLen; i++) {
        	if (word[i] <= 'Z' && word[i] >= 'A') bCnt++;
        	else if (word[i] <= 'z' && word[i] >= 'a') lCnt++;
		}
		// 如果全为大写字母
		if (bCnt == wLen) return true;
		// 如果全为小写字母
		if (lCnt == wLen) return true;
		// 如果开头为大写字母其余为小写字母
		if ((bCnt == 1 && lCnt != 0) && (bCnt + lCnt == wLen) && (word[0] <= 'Z' && word[0] >= 'A')) return true;
		// 否则为不合法字符
		return false; 
    }
}; 
```