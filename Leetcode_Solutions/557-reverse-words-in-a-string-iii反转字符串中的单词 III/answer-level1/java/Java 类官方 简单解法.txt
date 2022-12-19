### 解题思路

第一种方法非常简单，我们将输入字符串中按照空白字符串分开，然后把所有单词放到一个字符串列表中，然后我们逐一遍历每一个字符串并把反转结果连接起来。最后，我们将删除了额外空白字符的字符串返回。



### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String Words[] = s.split(" ");
		StringBuilder sb = new StringBuilder();
		for(String word:Words) {
			sb.append(new StringBuilder(word).reverse().toString()+" ");
		}
		return sb.toString().trim();
    }
}
```