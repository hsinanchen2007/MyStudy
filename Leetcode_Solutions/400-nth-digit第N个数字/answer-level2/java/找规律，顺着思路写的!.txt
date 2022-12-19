### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public int findNthDigit(int n) {
		long loc = 1;// 当前在哪个区间
		long count = 9;// 当前区间及之前区间的总位数之和【1，9】，【10，99】，【100，999】
		long preCount = 0;// 当前区间之前所有区间位数总和，不包括当前区间
		while (true) {
			if (count >= n) {
				break;
			}
			loc++;
			preCount = count;
			count = count + loc * 9 * (long) Math.pow(10, loc - 1);
		}
		if (loc == 1) {
			return n;
		} else {
			long remainCount = n - preCount - 1;//落在当前区间还剩余的位数和
			long div = remainCount / loc;
			long mod = remainCount % loc;
			long locStart = (long) Math.pow(10, loc - 1);//当前区间的其实number，【1，10，100，100.。。】
			long targetVal = locStart + div;//具体到当前区间的哪个Number
			return String.valueOf(targetVal).charAt((int) mod) - '0';
		}
	}
}
```