### 写在前面：
如果您觉得写得还可以，那就来关注在下的微信公众号吧“张氏文画”，不光有新鲜的 LeetCode 题解（多种思路，包教包会，开拓思维），还有经典的文章及短视频和大家分享，谢谢大家的关注！！！
![qrcode_for_gh_671e52fa1e78_258.jpg](https://pic.leetcode-cn.com/fa6a229fc23d58fb656a375382f96feecd9b6bc043183f36ee0d9ea9ffa3a12e-qrcode_for_gh_671e52fa1e78_258.jpg)

### 思路：

注意边界条件处理即可。没有那么多花里胡哨！！！

### 代码：

时间复杂度O(n)，空间复杂度O(1)

```java
class Solution {
    public int myAtoi(String str) {
    
    // 1、字符串为空或字符串仅包含空白字符时
    if (str == null || str.length() == 0 || str.trim().length() == 0) {
      return 0;
    }
    int sign = 1;
    int res = 0;
    
    // 2、找到第一个非空字符
    int startIndex = 0;
    for (char c : str.toCharArray()) {
      if(c == ' ') {
        startIndex++;
      } else {
        break;
      }
    }
    str = str.substring(startIndex);

    // 3、第一个非空格字符不是一个有效整数字符
    if ((str.charAt(0) < '0' || str.charAt(0) > '9') && str.charAt(0) != '-' && str.charAt(0) != '+') {
      return 0;
    }

    sign = str.charAt(0) == '-'? -1 : 1;
    if (sign == -1 || str.charAt(0) == '+') {
      startIndex = 1;
    } else {
      startIndex = 0;
    }
    
    for (; startIndex < str.length(); startIndex++) {
      int c = str.charAt(startIndex) - '0';
      if (c >= 0 && c <= 9) {
        if (res > Integer.MAX_VALUE / 10 || (c > Integer.MAX_VALUE % 10 && res == Integer.MAX_VALUE / 10)) {
          return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
        }
        res = res * 10 + c;
      } else {
        break;
      }
    }
    // System.out.println("res = " + res * sign);
    // 4、溢出处理
    return res * sign;
    }
}
```

```java
class Solution {
    public int myAtoi(String str) {
        int result = 0, i = 0, sign = 1;
		// 处理空字符串
		if (str.isEmpty())
			return 0;
		// 找到第一个非空格字符
		while (i < str.length() && str.charAt(i) == ' ')
			i++;
		// 处理全空白符字符串
		if (i == str.length())
			return 0;
		// 处理正负号
		if (str.charAt(i) == '+' || str.charAt(i) == '-') {
			sign = str.charAt(i) == '+' ? 1 : -1;
			i++;
		}
		// 将字符串转换为数字
		while (i < str.length()) {
			int value = str.charAt(i) - '0';
			// 检查是否有效数字
			if (value > 9 || value < 0)
				break;
			// 检查是否溢出
			if (result > Integer.MAX_VALUE / 10
					|| value > Integer.MAX_VALUE % 10
					&& result == Integer.MAX_VALUE / 10) {
				return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
			}
			result = result * 10 + value;
			i++;
		}
		return result * sign;
    }
}
```

### Result：

Runtime：2ms

Your runtime beats 96.91% of java submissions.