### 解题思路
1.定义set存放每个单词,循环每个截取单词中的字符串判断是否存在set中,存在则删除
2.定义cnt用于叠加set中每个单词的长度后返回

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        HashSet<String> set = new HashSet<String>(Arrays.asList(words));
		for (int i = 0; i < words.length; i++) {
			for (int j = 1; j < words[i].length(); j++) {
				set.remove(words[i].substring(j));
			}
		}
		int cnt = 0;
		for (String str : set) {
			cnt=cnt + str.length()+1;
		}
		
		return cnt;
    }
}
```