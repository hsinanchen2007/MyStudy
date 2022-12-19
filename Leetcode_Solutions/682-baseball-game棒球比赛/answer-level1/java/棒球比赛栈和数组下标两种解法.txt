```
class Solution {
    public int calPoints(String[] ops) {
		int sum = 0;
		Stack<String> stack = new Stack<>();//记录每一轮有效分数
		stack.add("0");//防止出现越界
		for (int i = 0; i < ops.length; i++) {
			if (ops[i].equals("C")) {
				sum -= Integer.valueOf(stack.peek());//先将sum回退
				stack.pop();//将上一轮有效分数出栈，即让其失效
			} else if (ops[i].equals("D")) {
				sum += Integer.valueOf(stack.peek()) * 2;
				String cur_grade = Integer.valueOf(stack.peek()) * 2 + "";
				stack.add(cur_grade);
			} else if (ops[i].equals("+")) {
				int f1 = Integer.valueOf(stack.elementAt(stack.size() - 1))+ Integer.valueOf(stack.elementAt(stack.size() - 2));
				sum += f1;
				stack.add(f1 + "");
			} else {
				sum += Integer.valueOf(ops[i]);
				stack.add(ops[i]);
			}
		}
		return sum;
	}
}
```
```
class Solution {
   	public int calPoints(String[] ops) {
		int sum = 0, index = 0;
		int every_points[] = new int[ops.length+1];//记录每一轮有效分数
		every_points[0] = 0;//防止出现越界
		for (int i = 0; i < ops.length; i++) {
			if (ops[i].equals("C"))
                //先将总和回退，再将记录有效分数的数组下标回退，相当于上一轮的有效分数失效
				sum -= Integer.valueOf(every_points[index--]);
			else if (ops[i].equals("D")) {
				every_points[++index] = every_points[index - 1] * 2;
				sum += every_points[index];
			} else if (ops[i].equals("+")) {
				every_points[++index] = every_points[index - 1] + every_points[index - 2];
				sum += every_points[index];
			} else {
				sum += Integer.valueOf(ops[i]);
				every_points[++index] = Integer.valueOf(ops[i]);
			}
		}
		return sum;
	}
}
```

