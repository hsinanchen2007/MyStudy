### 解题思路
字符串用“ ”分割得到字符串数组
反向遍历 这时数组里有""判断下，不为空时拼接该字符串再加一个空格
最后会多一个空格 用trim去掉

### 代码

```java
class Solution {
    public String reverseWords(String s) {
		String[] sArr = s.split(" ");
		StringBuilder sb = new StringBuilder();
		for(int i=sArr.length-1;i>=0;i--) {
			sb=sArr[i].length()==0?sb:sb.append(sArr[i]).append(" ");
		}
		return sb.toString().trim();
    }
}
```