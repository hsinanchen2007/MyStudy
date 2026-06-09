### 解题思路
dfs结合sb,三行代码

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
