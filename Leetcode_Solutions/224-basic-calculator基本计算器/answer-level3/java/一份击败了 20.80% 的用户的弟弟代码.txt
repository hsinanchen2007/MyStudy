### 解题思路
1.将给定的中缀表达式（单个字符串） 转换为逆波兰/后缀表达式（字符串数组）
2.利用栈对后缀表达式求值


### 代码

```java
class Solution {
    public int calculate(String s) {

        return evalRPN(getPolish(s));
    }

    private static String[] getPolish(String s) {
		HashMap<Character, Integer> map = new HashMap<>();
		InitOpMap(map);//初始化存储运算符优先级map
		Stack<Character> charStack = new Stack<>();
		ArrayList<String> PolishArray = new ArrayList<>();
		int temp = -1;
		int length = s.length();
		char c;
		
		for(int i=0;i<length;i++) {
			c = s.charAt(i);
			if(c == ' ') {
				continue;
			}else if(isNum(c)) {
				
				if(temp == -1) {
					temp = c - '0';
				}else {
					temp = temp*10 + c-'0';
				}
			}else {
				if(temp != -1) {
					PolishArray.add(String.valueOf(temp));
					temp = -1;
				}
				if(c == '(') {
					charStack.push(c);
				}else if(c == ')') {
					while(!charStack.empty() &&
							 map.get(charStack.peek()) != 0) {
						 PolishArray.add(String.valueOf(charStack.pop()));
					 }
					 charStack.pop();//pop左括号
				}else {              //c为其他运算符
					 while(!charStack.empty() && 
							 map.get( charStack.peek() )>=map.get(c) ) {
						 PolishArray.add(String.valueOf(charStack.pop()));
						 if(charStack.empty()) {
							 break;
						 }
					 }
					 charStack.push(c);
				}
			}
		}
		if(temp != -1) PolishArray.add(String.valueOf(temp));
		while(!charStack.empty()) {
			PolishArray.add(String.valueOf(charStack.pop()));
		}
		
		// System.out.println(PolishArray.toString());
		int len = PolishArray.size();
		String[] result = new String[len]; //定义存储返回结果的字符串数组
		for(int i = 0;i < len;i++) {
			result[i] = PolishArray.get(i);
		}
		return result;
	}


    private static  int evalRPN(String[] tokens) {

		Stack<Integer> stack = new Stack<>();
		
		int a,b;
		for(String c : tokens) {
			if(c.equals("+")||c.equals("-")
					||c.equals("*")||c.equals("/")) 
			{
				a = stack.pop();
				b = stack.pop();
				switch(c) {
					case "+":
						stack.push(b+a);
						break;
					case "-":
						stack.push(b-a);
						break;
					case "*":
						stack.push(b*a);
						break;
					case "/":
						stack.push(b/a);
						break;
				}				
			}else {
				stack.push(Integer.parseInt(c));
			}
		}
		
		return stack.pop();
    }	 

    private static void InitOpMap(HashMap<Character, Integer> map) {
		 map.put('+', 1);
		 map.put('-', 1);
		 map.put('*', 2);
		 map.put('/', 2);
		 map.put('(', 0);
	}


    private static boolean isNum(char c) {
		return c >='0' && c <= '9';
	}


}
```
思路很简单，但因为初学不熟练代码敲了很久，挫败感也很强，总结下遇到的问题：
1.在中缀转后缀时，使用了stringBuilder 来保存转换中的表达式，由于StringBuilder 输出结果为单个字符串，导致后面又对逆波兰求值的代码进行改造 将遍历单位改成字符 这样又导致只能计算出个位运算的正确结果 在这个问题上困扰了很久，终于想到使用arraylist解决；
2.没有考虑多位数字/字符串为纯数字的情况。 通过设置计数变量temp解决（先将表达式的数字保存在temp中，遇到连续的数位可以*10相加）
3.写到一半思路经常中断&有些Java语法不熟 还是不熟练		  