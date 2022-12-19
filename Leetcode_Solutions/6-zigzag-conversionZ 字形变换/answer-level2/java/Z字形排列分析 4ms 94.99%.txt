### 解题思路
此题需要先分析数字规律
Z型排列的特点：上下对称分布，每行间隔周期性变化：一种近相邻，一种远相邻，相邻状态相对的，可以认为前半部分先远后近，下半部分先近后远
上半部分的 近相邻间隔数公式：(k-1)2-1=2k-1 k为当前行数 远相邻间隔公式：（numrows-1)*2-1
每次循环将i跳跃算出来间隔数，取出i处的i字符加入res中。
对于下半部分 由于对称性，只需将上述公式中的k转化为numrows-k-1即可
最后再注意一下特殊情况就可以了

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
		char[] temp = s.toCharArray();
		char[] res = new char[s.length()];
		int m=0;
		{// 第一行单独考虑
			int i = 0;
			while (i < s.length()) {
				res[m++] = temp[i];
				if(numRows>1) {
				  i += (numRows - 0 - 1) * 2 ;
				}
				else {
					i++;
				}
			}
		}
		for (int k = 1; k < numRows-1; k++) {// 从第二行开始
			if (k < (numRows + 1) / 2) {// 前一半 第二行k等于1 先远后近
				int i = k;
				int c = 1;
				while (i < s.length()) {
					res[m++] = temp[i];
					if (c == 1) {// 远
						i += (numRows - (k + 1)) * 2 ;
					} else {//近
						i += ((k + 1) - 1) * 2 ;
					}
					c*=-1;
				}
			} else {//后一半，先近后远 同前部分对称
				int i = k;
				int c = 1;
				while (i < s.length()) {
					res[m++] = temp[i];
					if (c == -1) {// 远
						i += (numRows - (numRows-k-1 + 1)) * 2 ;
					} else {//近
						i += ((numRows-k-1 + 1) - 1) * 2 ;
					}
					c*=-1;
				}
			}
		}
		if(numRows>1){// 最后一行单独考虑
			int i = numRows-1;
			while (i < s.length()) {
				res[m++] = temp[i];
				i += (numRows - 0 - 1) * 2 ;
			}
		}
		return new String(res);

	}
}
```