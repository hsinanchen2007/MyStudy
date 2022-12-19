### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
		//回溯思想，需要加强练习
		List<String> result = new ArrayList<>();
		generateOneByOne("",result,n,n);//最开始是空字符串，还剩n个左右括号
		return result;
    }
	/**
	 * 其实就是给你2n个格子，问你有效括号的组合数，第几层递归，就是处理第几个格子上的括号，判断放左还是放右
	 * @param sublist
	 * @param result  结果集
	 * @param left  还剩多少左括号
	 * @param right  还剩多少右括号
	 */
	public static void generateOneByOne(String sublist ,List<String> result, int left,int right) {
		if (left == 0 && right == 0) {   // 括号都用完了，sublist组装完毕
			result.add(sublist);
			return ;
		}
		//每一层的递归，需要判断
		if (left > 0) {//还有剩余的左括号，那这个格子就可以放左括号
			generateOneByOne(sublist + "(", result, left-1, right);
		}
		if (right > left) {//只有剩余的右括号多于左括号时，这个格子才可以放右括号
			//比如()()_ _，那第五层递归就不能放右括号，因为剩余的左右括号相等
			generateOneByOne(sublist + ")", result, left, right-1);
		}
	}
}
```