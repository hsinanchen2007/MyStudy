> 时间复杂度O(n),空间复杂度O(1)
``` 
        a               e               i
    null    b       d       f       h       j       l
null            c               g               k 
```

大体思路就是将Z字形变成山峰型，从峰封顶向下一级级遍历。
可以得到如下规律
1. 每个山峰间距离`step= numRows * 2-2`,当然，numRows=1时，`step=1`;
2. 每行的数据`data=峰值±当前行数`，如，`e±2=c g`，`i±1=h j`;
3. 封顶和谷底只能记一次，这个不用解释吧，这里选择在 `data=峰值+行数` 时记录;
4. 如上所示，假如只到字母L，我们通过`峰值<s.length`做跳出循环条件，就会漏掉L，所以选择`峰值<s.length+step`

``` java
public static String convert(String s, int numRows) {
		int len= s.length();
		StringBuilder sb=new StringBuilder();
		int step = 2 * numRows - 2;

		for (int j = 0; j < numRows; j++) {
			for (int i = 0; i < len + step; i += step > 0 ? step : 1) {
				// because i< len+step, so maybe exists i-j>=len;
				if (i - j < len) {
					if (j == 0) {
						sb.append(s.charAt(i));
						// first row and last row only one number per i++.
					} else if (j == numRows - 1) {
						if (i + j < len) {
							sb.append(s.charAt(i + j));
						}
					} else {
						// for first round,i-j<0
						if (i - j >= 0) {
							sb.append(s.charAt(i - j));
						}
						if (i + j < len) {
							sb.append(s.charAt(i + j));
						}
					}
				}


			}
		}
		return sb.toString();

	}
```