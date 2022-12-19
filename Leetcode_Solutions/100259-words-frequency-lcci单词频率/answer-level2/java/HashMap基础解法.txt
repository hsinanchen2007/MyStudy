### 解题思路
1. 字符数组传入HahMap
2. 若Map中无此字符，先进行初始化，次数置1
3. 若有此字符，则修改对应键的值，对次数加1

### 代码

```java
class WordsFrequency {
    HashMap<String,Integer> map = new HashMap<>();
    public WordsFrequency(String[] book) {
        for(String bo:book){
            if (!map.containsKey(bo)){
                map.put(bo, 1);
            } else {
                map.put(bo,map.get(bo) + 1);
            }
        }
    }
    public int get(String word) {
        return (map.get(word) == null) ? 0 : map.get(word);
    }
}

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency obj = new WordsFrequency(book);
 * int param_1 = obj.get(word);
 */
```