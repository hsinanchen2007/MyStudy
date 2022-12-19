### 解题思路
此处撰写解题思路

### 代码

```java
class WordsFrequency {
     
     HashMap<String, Integer> hm;
    public WordsFrequency(String[] book) {
    	hm=new HashMap<String, Integer>();
    	for(String str:book){
    		hm.put(str, hm.getOrDefault(str, 0)+1);
    	}

    }
    
    public int get(String word) {
      if(hm.containsKey(word)){
    	  return hm.get(word);
      }
      return 0;
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency obj = new WordsFrequency(book);
 * int param_1 = obj.get(word);
 */
```