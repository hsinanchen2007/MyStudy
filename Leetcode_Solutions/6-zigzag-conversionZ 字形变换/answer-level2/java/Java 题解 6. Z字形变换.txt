## 思路

1. 找出Z字形排序的规律，我找规律的能力还是不行，没找到2n-2的规律
2. 规律如下，除去坐标0和numRows-1的位置，其他位置都是距离 i 位置 numRows - 1 - i 的两倍，下一次为 i 的两倍，相互交替
3. 表达能力不行，只能看图

![微信截图_20190522111539.png](https://pic.leetcode-cn.com/594f62f64cf1d2354d4e5b85d0dad39776faadb2e7908f19b010daae38bff2f5-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190522111539.png)

## 实现
```
class Solution {
	public String convert(String s, int numRows) {
		if (numRows == 1) {
			return s;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < numRows && i < s.length(); i++) {
			int pos = i;
			sb.append(s.charAt(pos));
			for (int j = 0; ; j++) {
				if (i % (numRows - 1)  == 0) {    //排除0和numRows-1
					pos = pos + (numRows - 1) * 2;
					if (pos > s.length() - 1) {
						break;
					}
				} else {
					pos = pos + (numRows - 1 - i) * 2 * ((j + 1) % 2) + i * 2 * (j % 2);    //交替加两倍的 numRows-1-i 和 i
					if (pos > s.length() - 1) {
						break;
					}
				}
				sb.append(s.charAt(pos));
			}
		}
		return sb.toString();
	}
}
```