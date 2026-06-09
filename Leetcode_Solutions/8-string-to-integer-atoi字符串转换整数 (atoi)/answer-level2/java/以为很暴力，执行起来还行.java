
一位一位的处理，判断边界，快乐。。晚上研究研究自动机

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        str = str.trim();
		if (str.length() == 0) {
			return 0;
		}
		char[] chars = str.toCharArray();
		int min = -2147483648;
		int max = 2147483647;

		int flag = 0;
		int sum = 0;
		if ((int) chars[0] == 45) {
			flag = 1;
		} else if ((int) chars[0] == 43) {
			flag = 0;
		} else if ((int) chars[0] < 48 || (int) chars[0] > 57) {
			return 0;
		} else {
			sum = (int) chars[0] - (int) ('0');
		}

		for (int i = 1; i < chars.length; i++) {
			if ((int) chars[i] < 48 || (int) chars[i] > 57) {
				break;
			}

			int num = (int) chars[i] - (int) ('0');

			if (flag == 0 && sum > max / 10) {
				return max;
			}

			if (flag == 1 && -sum < min / 10) {
				return min;
			}
			sum = sum * 10;

			if (flag == 0 && sum > max - num) {
				return max;
			}

			if (flag == 1 && -sum < min + num) {
				return min;
			}

			sum = sum + num;

		}

		if (flag == 1) {
			return -sum;
		}

		return sum;
    }
}
```