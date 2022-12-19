### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/4242641855f34cbe918d6c79649674907b7ca9dcbdc75900ee335f934bdd7d7a-image.png)
题目脑筋急转弯
分析：删除回文子序列，而不是回文子字符串，因为给出字符串只有a和b，所以一共
只有三种情况，1.为空，删除0次，2.自身为回文，删除1次，3.自身不为回文，删除2次

### 代码

```cpp
class Solution {
public:
	bool isHuiwen(string s) {
		int left = 0, right = s.size() - 1;
		while (left < right) {
			if (s[left++] != s[right--]) return false;
		}
		return true;
	}
    int removePalindromeSub(string s) {
        if (s.empty() || s.size() <= 0) return 0;
        if (isHuiwen(s)) return 1;
        return 2;
    }
}; 
```