### 解题思路
这题比224要简单点，介绍下两个方法的含义。
addNum()就是负责将栈中只存放操作数以及+-，负责三个方面：
1. 栈空，说明第一次存放，直接存放操作数
2. 栈顶元素为+-，不动
3. 栈顶元素*\，运算后压栈

getNum()就是计算栈中全部运算结果，因为只有+-操作，所以就很简单啦。

### 代码

```java
class Solution {
    public int calculate(String s) {
		if(s == null || s.length() == 0);
		s = String.join("", s.trim().split(" "));
		return value(s.toCharArray(), 0);
	}
	public int value(char[] arrs, int i){
		int pre = 0;
		String s = null;
		LinkedList<String> que = new LinkedList<>();
		while(i < arrs.length){
			if(arrs[i] >= '0' && arrs[i] <= '9') pre = pre * 10 + arrs[i++] - '0';
			else {
				addNum(que, pre);
				que.addLast(String.valueOf(arrs[i++]));
				pre = 0;
			}
		}
        addNum(que, pre);
		return getNum(que);
	}
	public void addNum(LinkedList<String> que, int num){
		if(!que.isEmpty()){
			int cur = 0;
			String s = que.pollLast();
			if("+".equals(s) || "-".equals(s)) que.addLast(s);
			else {
				cur = Integer.valueOf(que.pollLast());
				num = "*".equals(s) ? num*cur :cur/num;
			}
		}
		que.addLast(String.valueOf(num));
	}
	public int getNum(LinkedList<String> que){
		int cur = 0;
		int sum = 0;
		boolean flag = true;
		String s = null;
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