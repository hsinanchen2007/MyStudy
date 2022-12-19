### 解题思路
此处撰写解题思路
思路 还没有完全清晰，在做练习
### 代码

```java
class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<String>();
		
		if(digits.length() == 0)
			return result;
		
		String[] letterStr = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
		
		dfs(digits, result, letterStr,  0, "");
		
		return result;
    }

    private void dfs(String digits,List<String> result, String[] letterStr, int start, String letter) {
		if(start >= digits.length()) {
			result.add(letter);
			return ;
		}
		
		//第一次 start==0
		char ch = digits.charAt(start); //第一次获得digits的第一个字符数字
		int index = ch - '0'; //得到letterStr数组中的下标
		for(int i = 0;i < letterStr[index].length(); i ++) { 
			dfs(digits, result, letterStr, start + 1,letter + letterStr[index].charAt(i));
		}
	}
}
```
![image.png](https://pic.leetcode-cn.com/a4bda331ee46d9d121e7268c8f47144a0b06962550bb43bb6d81bb51fd885652-image.png)
