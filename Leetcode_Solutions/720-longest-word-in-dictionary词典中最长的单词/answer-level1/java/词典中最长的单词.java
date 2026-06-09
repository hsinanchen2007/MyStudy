### 解题思路
利用哈希集合以及排序来做

### 代码

```java
class Solution {
    public String longestWord(String[] words) {
        //对数组排序，在利用Set对字母存储，小的单词一定包含在大的单词里面。
        //对单词排序后，第一个单词一定是公有的，后面的只需在此基础上添加。
        Arrays.sort(words);
        Set<String> set=new HashSet<>();  //哈希集合中存储的是字符串
        String res="";
        for(String s:words)
        {
            //如果单词只有一个字母，那一定是共有的
            if(s.length()==1||set.contains(s.substring(0,s.length()-1)))
                {
                    res=s.length()>res.length()? s:res;
                    set.add(s);
                }
        }
        return res;
    }
}
```