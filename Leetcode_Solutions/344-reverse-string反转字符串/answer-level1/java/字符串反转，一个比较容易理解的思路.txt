### 解题思路
1. 计算交换次数是关键
2. 注意节省内存

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        // 获取字符串长度
		int strLength = s.length;
		// 计算交换次数，这个是关键
		int reverseNum = 0;
		if (strLength % 2 == 0) {
			reverseNum = strLength / 2;
		} else {
			reverseNum = (strLength - 1) / 2;
		}
		if (reverseNum != 0) {
			// 记录最大下标，用于交换
			int lastIndex = s.length - 1;
			// 交换过程
			char previousData;
			char suffixData;
			for (int i = 0; i < reverseNum; i++) {
				previousData = s[i];
				suffixData = s[lastIndex];
				s[lastIndex] = previousData;
				s[i] = suffixData;
				lastIndex--;
			}
		}
    }
}
```