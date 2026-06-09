### 解题思路
主要是HashSet的应用。

### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
		String[]morse = new String[]{".-","-...","-.-.","-..",".","..-.","--.",
            "....","..",".---","-.-",".-..","--","-.",
            "---",".--.","--.-",".-.","...","-","..-",
            "...-",".--","-..-","-.--","--.."};
		Set<String>seen= new HashSet();     //创建Hashset类型的字符串集合
		for (String word : words) {            
			StringBuilder code = new StringBuilder();  //创建StringBuilder用于构造code
			for (char c : word.toCharArray()) {
				code.append(morse[c-'a']);            //构造code
			}
			seen.add(code.toString());               //加入Hashset集合
		}
		return seen.size();                         //Hashset无重复元素
    }
}
```