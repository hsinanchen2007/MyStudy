### 解题思路
建立哈希映射，Key为字符串中的字母按照字母表顺序重新排列所得的anagram，value为List,包含所有key的异位词。
1. 首先，遍历字符串数组，对每个字符串s，调用sortChars(s)，得到哈希映射里的key
2. 将该字符串s加入Key所映射到的List中
3. 最后，遍历哈希映射的关键字集合，将得到的List<>依次加入要返回的结果数组List<List<>>中

### 代码

```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> map=new HashMap<>();
        for(String s:strs){
            String key=sortChars(s);
            List<String> tmp=map.getOrDefault(key,new ArrayList<>());
            tmp.add(s);
            map.put(key,tmp);
        }
        List<List<String>> ret=new ArrayList<>();
        for(String key:map.keySet()){
            List<String> list=map.get(key);
            ret.add(list);
        }
        return ret;
    }
    private String sortChars(String s){
        char[] content=s.toCharArray();
        Arrays.sort(content);
        return new String(content);
    }
}
```