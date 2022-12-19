### 解题思路
1. 26个莫尔斯码为什么用数组存储而不是hashmap存储，因为如果要用hashmap，需要put很多次，得不偿失，直接用数组存储也比较简单，后面访问也方便
2. 为什么使用哈希集合 HashSet 存储每个单词的摩尔斯码，因为 set 作为集合，add 函数不会添加 set 中已有的元素，之后直接调用 size() 方法返回集合元素个数就是结果了（这个套路 String 类算法中出现很多，都是用 HashSet）

### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] morse = new String[] {".-","-...","-.-.","-..",".","..-.","--.",
        		"....","..",".---","-.-",".-..","--","-.","---",
        		".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    	Set<String> seen = new HashSet<>();
    	for(String word : words) {
    		StringBuilder sBuilder = new StringBuilder();
    		for(char c : word.toCharArray()) {
    			sBuilder.append(morse[c-'a']);
    		}
    		seen.add(sBuilder.toString());
    	}
    	return seen.size();
    }
}
```