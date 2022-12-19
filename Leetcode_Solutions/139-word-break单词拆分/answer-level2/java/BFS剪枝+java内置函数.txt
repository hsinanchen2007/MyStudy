对于dp的方法就不说了，很简单，官方题解中也给了一种BFS的思想，然后就是把这个思想换个写法，就出奇的快。
```java
class Solution {
    /*
    学来的一种BFS剪枝方法，利用java内置函数，竟然出奇的快
    */
    String str;
    Set<Integer> cache;
    List<String> list;
    public boolean wordBreak(String s, List<String> wordDict) {
       str=s;
       cache=new HashSet<Integer>();
       list=wordDict;
       return wordBreak(0);
    }
     private boolean wordBreak(int d){
        if(d == str.length()) return true;
        if(cache.contains(d)) return false;//无需再次重复计算，剪枝
        for(String word : list){
            if(str.startsWith(word, d)){//内置函数
                if(wordBreak(d+word.length())) return true;
                cache.add(d+word.length());//已经为false的
            }
        }
        return false;
    }
   
}
```
