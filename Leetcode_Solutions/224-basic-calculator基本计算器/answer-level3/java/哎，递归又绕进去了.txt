### 解题思路
我怎么就这么喜欢写这种代码呢？？
s = String.join("", s.trim().split(" "));
这题没有乘除，所以
1. 遇到数字，换算成整数
2. 遇到+-，整数压栈，符号压栈
3. 遇到(，递归，返回的是当前空间栈所有数运算结果

### 代码

```java
class Solution {
    public int calculate(String s) {
		if(s == null || s.length() == 0) return 0;
        s = String.join("", s.trim().split(" "));
		return value(s.toCharArray(), 0)[0];
	}
	public int[] value(char[] arrs, int i){
		LinkedList<String> que = new LinkedList<>();
		int pre = 0;
		int[] bra = null;
		while(i < arrs.length && arrs[i] != ')'){
			if(arrs[i] >= '0' && arrs[i] <= '9') pre = pre * 10 + arrs[i++] - '0';
			else if(arrs[i] != '('){
				que.addLast(String.valueOf(pre));
				que.addLast(String.valueOf(arrs[i++]));
				pre = 0;
			}else{
				bra = value(arrs, i + 1);
				pre = bra[0];
				i = bra[1] + 1;
			}
		}
		que.addLast(String.valueOf(pre));
		return new int[]{getNum(que), i};
	}
	public int getNum(LinkedList<String> que){
		boolean flag = true;
		int cur = 0;
		int sum = 0;
		String s = "";
		while (!que.isEmpty()){
			s = que.pollFirst();
			if("+".equals(s)) flag = true;
			else if("-".equals(s)) flag = false;
			else {
				cur = Integer.valueOf(s);
				sum += flag ? cur : -cur;
			}
		}
		return sum;
	}
}