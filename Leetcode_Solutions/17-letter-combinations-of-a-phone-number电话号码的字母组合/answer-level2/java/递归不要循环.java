```java
class Solution {
    List<String> list = new ArrayList<String>();

	public List<String> letterCombinations(String digits) {
		
		if (digits.length() != 0)
			pin(0,digits,"");
		return list;
    }
	
	public void pin(int index, String digits, String str) {
		if(index == digits.length()) {
			list.add(str);
			return;
		}
		
		switch(digits.charAt(index)) {
			case '2' :
				pin(index+1,digits,str+"a");
				pin(index+1,digits,str+"b");
				pin(index+1,digits,str+"c");
				break;
			case '3' :
				pin(index+1,digits,str+"d");
				pin(index+1,digits,str+"e");
				pin(index+1,digits,str+"f");
				break;
			case '4' :
				pin(index+1,digits,str+"g");
				pin(index+1,digits,str+"h");
				pin(index+1,digits,str+"i");
				break;
			case '5' :
				pin(index+1,digits,str+"j");
				pin(index+1,digits,str+"k");
				pin(index+1,digits,str+"l");
				break;
			case '6' :
				pin(index+1,digits,str+"m");
				pin(index+1,digits,str+"n");
				pin(index+1,digits,str+"o");
				break;
			case '7' :
				pin(index+1,digits,str+"p");
				pin(index+1,digits,str+"q");
				pin(index+1,digits,str+"r");
				pin(index+1,digits,str+"s");
				break;
			case '8' :
				pin(index+1,digits,str+"t");
				pin(index+1,digits,str+"u");
				pin(index+1,digits,str+"v");
				break;
			case '9' :
				pin(index+1,digits,str+"w");
				pin(index+1,digits,str+"x");
				pin(index+1,digits,str+"y");
				pin(index+1,digits,str+"z");
				break;
		}
	}
}

```

先说一下有关java基础的问题

静态方法只能调用静态方法，静态变量，不然你创建了别人还没创建。

#而我在本地做的时候将cf所有方法都设置成了静态，关键是将list也设置成了静态，除了第一个测试案例之后的所有案例都有第一个案例的结果，因为list是静态的

正文：

创建一个方法`pin`用来拼接字符串，在`letterCombinations`方法中只做非空判断和初始化

在`pin`方法中每次添加一位，switch case来进行递归，看着比较笨，其实ctrl+c，ctrl+v就可以了

最后就能得到正确答案

![](https://pic.leetcode-cn.com/00376f133140791ca40c37329e4fcca6790760e94de51a226d0793202586d8da-image.png)


