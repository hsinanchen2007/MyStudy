给出一个表达式，计算结果，就是一个计算器类型的问题，也是栈的经典应用。
栈：添加和删除元素都在队尾进行，先进后出，后进先出，类比于子***，入栈和出栈。

思路：
1. 将表达式（中缀）转化为后缀
2. 将后缀计算出结果

具体规则为：
1.中缀转后缀：
    - 数字直接输出到后缀表达式
    - 栈为空时，遇到运算符，直接入栈
    - 遇到运算符，弹出所有优先级大于或等于该运算符的栈顶元素，并将该运算符入栈
    - 将栈中元素依次出栈
    

例如：表达式：3+2 * 2
遇到3，直接输出到后缀表达式中，栈中元素为空，结果为：     栈： 空；     后缀表达式：3
遇到符号“+”，入栈，结果为：     栈：+ ；    后缀表达式：3
遇到2，直接输出，结果为：   栈：+；     后缀表达式： 3  2
遇到乘号*，入栈，结果为： 栈： * + ；后缀表达式：3 2
遇到2，直接输出，结果为： 栈： * + ；后缀表达式：3 2 2
最后，将元素出栈：结果为：后缀表达式：3 2 2 * +


2.计算后缀：
    - 遇到数字，入栈
    - 遇到运算符，弹出栈顶两个元素，做运算，并将结果入栈
    - 重复上述步骤，直到表达式最右端

例如上述得到的后缀表达式为 3 2 2 * +
3 2 2 都是数字，入栈，结果为：栈：2 2 3
遇到* 号， 2 2 出栈，并计算，2*2 = 4, 4入栈，结果为：栈：4 3 ，表达式还剩一个加号
遇到+ 号，栈顶两个元素出栈并运算，4 3 做加法，4+3 =7
后缀表达式空了，计算完毕，输出结果：7 


【代码分享】：
```
import java.util.LinkedList;
import java.util.Stack;

 public class Solution{
 public int calculate(String exp) {
		return calRst(backTempExp(exp));
	}
// 计算后缀表达式
	public static LinkedList<String> backTempExp(String exp) {

		Stack<String> stkEles = new Stack<String>();
		LinkedList<String> tempBackExp = new LinkedList<String>();
		for (int i = 0; i < exp.length(); i++) {
			// 1.遇到了数字
			if (Character.isDigit(exp.charAt(i))) {
				// 注意多位数的获取
				int k = i + 1;
				for (; k < exp.length() && Character.isDigit(exp.charAt(k)); k++) {

				}
				tempBackExp.add(exp.substring(i, k));
				i = k - 1;// 更新 i
				continue;
			}
			// 2.遇到了乘除运算符
			if (exp.charAt(i) == '/' || exp.charAt(i) == '*') {

				while (!stkEles.isEmpty() && (stkEles.lastElement().equals("/") || stkEles.lastElement().equals("*"))) {
					tempBackExp.add(stkEles.pop()); // 弹出优先级相同或以上的栈内运算符
				}
				stkEles.add(String.valueOf(exp.charAt(i))); // 运算符入栈
				continue;
			}
			// 3.遇到了加减运算符
			if (exp.charAt(i) == '+' || exp.charAt(i) == '-') {
				while (!stkEles.isEmpty() && !isNumeric(stkEles.lastElement())) {
					tempBackExp.add(stkEles.pop()); // 弹出优先级相同或以上的栈内运算符
				}
				stkEles.add(String.valueOf(exp.charAt(i))); // 运算符入栈
				continue;
			}
		}
		// 4.最后弹出栈内所有元素到表达式
		while (stkEles.size() > 0) {
			tempBackExp.add(stkEles.pop());
		}
		return tempBackExp;
	}

	// 计算最终的结果
	public static int calRst(LinkedList<String> tempBackExp) {
		Stack<Integer> calStk = new Stack<Integer>();
		for (String c : tempBackExp) {
			// 1.数字，入栈
			if (isNumeric(c)) {
				calStk.push(Integer.valueOf(c)); // string to int
				continue;
			}
			// 2.非数字，则为符号，出栈两个元素计算出结果然后再入栈该计算值
			else {
				int a = calStk.pop();
				int b = calStk.pop();
				switch (c.toCharArray()[0]) {
				// 注意减法和除法时，注意出栈的顺序与原表达式是相反的

				case '+':
					calStk.push(b + a);
					continue;
				case '-':
					calStk.push(b - a);
					continue;
				case '*':
					calStk.push(b * a);
					continue;
				case '/':
					calStk.push(b / a);
					continue;
				}
			}
		}
		return calStk.pop();
	}

	public static boolean isNumeric(String str) {
		for (int i = 0; i < str.length(); i++) {
			if (!Character.isDigit(str.charAt(i))) {
				return false;
			}
		}
		return true;
	}
	
}
```
