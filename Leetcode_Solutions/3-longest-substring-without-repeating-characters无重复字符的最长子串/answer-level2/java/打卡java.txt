### 解题思路
- 主要思想采用滑动窗口记录当前最长子串。
- 使用两个变量来记录窗口的起点和终点。
- 终点不需要控制，自增就可以。
- 如果遇到当前遍历字符已经存在于窗口中，则需要改变start。
- 窗口中被重复的字符及其之前字符全部作废。新的start为被重复字符的下标+1.

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
      if (s==null){
            return 0;
        }
        if (s.length()<2){
            return s.length();
        }
        int max=-1;
       
        int start=0,end=0;
        while(end<s.length()){
            //在窗口内
           int tempt=s.indexOf(s.charAt(end),start);
            if (tempt!=end){
                start=tempt+1;
            }
            if (max<end-start+1){
                max=end-start+1;
            }
            end++;
        }
        return max;
    }
}
```
  
```java
/*
        利用map对字符串的每一个字符和其下标进行存储。
        采用滑动窗口的形式。利用两个变量分别记录窗口的起点和终点。
        当前窗口为当前最长子串。
        每遍历到一个字符需要进行：
            1. 判断该字符是否在map中，如果不在则执行map.put。
            2. 如果该字符已经在map中，则需要进一步判断该字符是否在滑动窗口中。
            3. 如果map中当前字符的下标比start小，则不在窗口中。
            4. 如果map中的当前字符下标比start大，则新的start为map中的当前字符下标+1；
    */
    public static int lengthOfLongestSubstring2(String s) {
        if (s==null){
            return 0;
        }
        if (s.length()<2){
            return s.length();
        }
        int max=-1;
        int n=-1;
        //记录当前最长子串的第一个元素和最后一个元素下标
        int start=0;
        //遍历String的每一个char，然后存入map中
        Map<Character, Integer> map=new LinkedHashMap<>();
        for (int end=0;end<s.length();end++){
            //当前字符已经存在于map中
            if (map.containsKey(s.charAt(end))){
                //如果当前字符的在窗口内，需要改变start值
                if (map.get(s.charAt(end))>=start){
                    //已经存在于map中的当前字符及其之前的字符都要移除窗口
                    start=map.get(s.charAt(end))+1;
                }
                //当前字符在窗口外，则加入到当前窗口
            }
            map.put(s.charAt(end),end);
            //记录当前最长子串长度
            if (max<end-start+1){
                max=end-start+1;
            }
        }
        return max;
    }
```  

```java
    /*
        利用map对字符串的每一个字符和其下标进行存储。遇到重复的就将map中该重复字符及其之前的字符全部删除。
        因为涉及到对map的修改，需要用到迭代器进行遍历，开销比较大。
    */
    public static int lengthOfLongestSubstring1(String s) {
        if (s==null){
            return 0;
        }
        if (s.length()<2){
            return s.length();
        }
        int max=-1;
        int n=-1;
        //遍历String的每一个char，然后存入map中
        Map<Character, Integer> map=new LinkedHashMap<>();
        for (int i=0;i<s.length();i++){
            if (map.containsKey(s.charAt(i))){
                //新字符串起点n，新起点为重复字符下一个开始
                n=map.get(s.charAt(i))+1;
                //linkedhashmap开头开始遍历，删除map中重复元素以及该元素之前的所有元素，遍历到value为n时跳出循环
                Set<Map.Entry<Character, Integer>> set = map.entrySet();
                Iterator<Map.Entry<Character, Integer>> it = set.iterator();
                while(it.hasNext()){
                    Map.Entry<Character, Integer> entry = it.next();
                    //使用Entry对象中的方法getKey()和getValue()获取键与值
                    Character key = entry.getKey();
                    Integer value = entry.getValue();
                    //迭代器中删除只能用迭代器方法remove
                    if (value<n){
                        it.remove();
                        continue;
                    }
                    if (value==n){
                        break;
                    }
                }
                map.put(s.charAt(i),i);
            }else {
                map.put(s.charAt(i),i);
            }
            if (max<map.size()){
                max=map.size();
            }
        }
        return max;
    }

```