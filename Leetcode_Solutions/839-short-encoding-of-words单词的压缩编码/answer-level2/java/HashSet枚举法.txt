### 解题思路
如下

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
    	Set<String>useful = new HashSet<String>(Arrays.asList(words));    
        //设置一个Hashset存放所有的单词
    	for (int i = 0; i < words.length; i++) {
    		for (int j = 1; j < words[i].length(); j++) {      //最多只有个七个后缀
				useful.remove(words[i].substring(j));   
                //只要集合中出现后缀即删掉，注意substring()是从指定位置到末尾
			}
		}
    	
    	int ans=0;
    	for (String string : useful) {
			ans+=string.length()+1;    //补#号
		}
		return ans;
    }
}
```