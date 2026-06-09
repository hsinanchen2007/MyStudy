二进制小数部分计算：0+2^(-1)+2^(-2)+2^(-3)+....
不停的乘2取整数部分，有可能得到的新的数永远不等于 0
![image.png](https://pic.leetcode-cn.com/0b841ef4063b7c16fe012177b62b7c543ebdf2bb40532bef4e6ac2ba71090d6e-image.png)

就按照规则计算33次，用stringbuilder存储，若是中间能得到0就返回stringbuilder。
若是计算了33次，就返回ERROR
```
public String printBin(double num) {
		StringBuilder sb = new StringBuilder();
		sb.append("0.");
		for (int i = 0; i < 33; i++) {
			if (num == 0) return sb.toString();
			num *= 2;
			if (num >= 1) {
				sb.append("1");
				num -= 1;
			} else {
				sb.append("0");
			}
		}
		return "ERROR";
	}
```
