### 解题思路
题目的最后一个测试用例告诉我们，不能简单的利用string去保存已经解码的字符串。应该index循环的方式求解。
题目要读清楚，不是求得后面所有数字连起来的10进制数，而是一位一位的翻倍；

首先需要一个遍历到当前为止，前面字符串长度变量currentLength，不管是(asas)或者是(as2)都是有长度的，记录下长度大于K的那个长度，**注意这里变量需要使用long long类型**；
然后在往前回溯，currentLength / num[i]求得i数字之前的长度总和；然后K在对当前的长度取余，看是需要返回哪一个index；最后利用%看K是否能正好能被整除，也即是K是否能正好分完。

### 代码

```cpp
class Solution {
public:
	bool IsDigital(char numChr) 
	{
		if (numChr > '0' && numChr <= '9') {
			return true;
		}
		return false;
	}
    string decodeAtIndex(string S, int K) {
		if (S.empty()) {
			return "";
		}
		long long currentStrLength = 0;
		int index = 0;
		for (; index < S.length(); index++) {
			if (IsDigital(S[index])) {
				currentStrLength *= (S[index] - '0');
			} else {
				currentStrLength++;
			}
			if (currentStrLength >= K) {
				break;
			}
		}
		for (int j = index; j >= 0; j--) {
			if (IsDigital(S[j])) {
				currentStrLength = currentStrLength / (S[j] - '0');
				K = K % currentStrLength;
			} else {
				if (K % currentStrLength == 0) {
					return string(1, S[j]);
				}
				currentStrLength--;
			}
		}
        return "";
    }
};
```