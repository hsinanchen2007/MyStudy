### 解题思路
> 刚开始看错题以为是截取出来的数字是不是在Fibonacci数列里 (= =)
> 解释都在注释里了,主要就是判断好边界

### 代码

```java
class Solution {
    List<Integer> ans;

	public List<Integer> splitIntoFibonacci(String S) {

		ans = new ArrayList<>();
		if (dfs(0, S, 0, 0, 0))return ans;

		return new ArrayList<>();
	}
	/**
	* @p : 当前指针指向数组的索引
	* @s : 字符串
	* @pre1 : 前面隔一个的数
	* @pre2 : 前一个数
	* @deep : 当前是第几个数
	**/
	public boolean dfs(int p, String s, int pre1, int pre2, int deep) {
		int length = s.length();
		if (p == length)return deep >= 3;
		
		for (int i = 1; i <= 11; i++) {
			//超出长度或者以0开头直接break;
			if (p + i > length || (s.charAt(p) == '0' && i > 1))break;
			//截取字符串
			String sub = s.substring(p, p + i);
			
			long numL = Long.parseLong(sub);
			//判断是否超出范围,或者deep不是0,1却大于他的前两个数之和
			if (numL > Integer.MAX_VALUE || 
				(deep != 0 && deep != 1 && numL > (pre1 + pre2)))break;
			//转成int
			Integer num = (int) numL;
			//满足条件的数,递归加回溯
			if (deep == 0 || deep == 1 || num.equals(pre1 + pre2)) {
				ans.add(num);
				if (dfs(p + i, s, pre2, num, deep + 1))return true;
				ans.remove(num);
			}
		}
		return false;
	}
}
```