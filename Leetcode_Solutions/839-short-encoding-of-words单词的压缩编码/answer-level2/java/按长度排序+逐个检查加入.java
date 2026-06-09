### 解题思路
思路很单纯直接
遍历单词数组，查找是否已经存在 单词+"#" 存在，没有则加上，有则跳过
前面按照单词长度排序一下，防止被"me","time"这样的顺序坑了，
这就是第一次实现

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, new Comparator<String>() {

			@Override
			public int compare(String a, String b) {
				return b.length() - a.length();
			}
		});
		
		System.out.println(Arrays.toString(words));
		StringBuilder sb = new StringBuilder();
		for(String w : words) {
			if(sb.indexOf(w+"#") == -1) {
				sb.append(w+"#");
			}
		}
		return sb.length();
    }
}
```