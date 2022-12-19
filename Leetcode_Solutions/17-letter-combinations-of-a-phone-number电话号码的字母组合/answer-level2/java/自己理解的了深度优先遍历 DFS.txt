### 解题思路
dfs深度优先

充分运用代码debug调试功能，能清楚明白代码的执行和流程
![image.png](https://pic.leetcode-cn.com/e7a83a9490850b3ff1f8e93fea5ceed44bebe8c2fa4c05359cf82710686c9226-image.png)


### 代码

```java
class Solution {
   public List<String> letterCombinations(String digits) {
		List<String> result = new ArrayList<String>();
		
		if(digits.length() == 0)
			return result;
		
		String[] letterStr = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		StringBuilder sb = new StringBuilder();
		dfs(digits, result, letterStr,  0, sb);
		
		return result;
	}

	private void dfs(String digits,List<String> result, String[] letterStr, int start, StringBuilder letter) {
		if(start >= digits.length()) {
			result.add(letter.toString());
			return ;
		}
		
		//第一次 start==0
		char ch = digits.charAt(start); //第一次获得digits的第一个字符数字
		int index = ch - '0'; //得到letterStr数组中的下标
		for(int i = 0;i < letterStr[index].length(); i ++) { 
			dfs(digits, result, letterStr, start + 1,letter.append(letterStr[index].charAt(i)));
        letter.deleteCharAt(letter.length()-1);
		}
	}
}
```
![image.png](https://pic.leetcode-cn.com/c6599933a35f8157f4395b4722e977394279d2e5f1adc9fdcb642a8a49756bf0-image.png)

![image.png](https://pic.leetcode-cn.com/918d4216d6bfc9ce74eebb9d0d0c67a1d1393c61b4fcab6a5386c3c708ec415d-image.png)
