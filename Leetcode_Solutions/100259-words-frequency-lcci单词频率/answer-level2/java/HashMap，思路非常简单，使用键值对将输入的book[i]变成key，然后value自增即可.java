### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.HashMap;
import java.util.Map;

class WordsFrequency {
    private Map<String,Integer> bookCount = new HashMap<>();

    public WordsFrequency(String[] book) {
//        Map<String,Integer> bookCount = new HashMap<>();
        int i = 0;
        while(i < book.length){
            if(bookCount.containsKey(book[i])){
                int tmp = bookCount.get(book[i]);
                bookCount.put(book[i],++tmp);
            }else
                bookCount.put(book[i],1);
            i++;
        }
    }

    public int get(String word) {
        if(bookCount.containsKey(word))
            return bookCount.get(word);
        else
            return 0;
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency obj = new WordsFrequency(book);
 * int param_1 = obj.get(word);
 */
```