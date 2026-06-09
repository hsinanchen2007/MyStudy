### 解题思路
使用哈希表，记录单词的数目

### 代码

```java
class WordsFrequency {

    Map<String, Integer> map;
	
	public WordsFrequency(String[] book) {
		map = new HashMap<String, Integer>();
		for(String word : book) {
			if(map.containsKey(word)) {
				map.put(word, map.get(word)+1);
			}else {
				map.put(word, 1);
			}
		}
    }
    
    public int get(String word) {
    	if(map.containsKey(word)) {
    		return map.get(word);
    	}else {
    		return 0;
    	}
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency obj = new WordsFrequency(book);
 * int param_1 = obj.get(word);
 */
```