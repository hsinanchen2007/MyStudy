### 解题思路

用map记录chars中单词类型及数量，再依次统计words中字母情况。
注意不能每次统计words中字符串时，用map去减它，Java对象是引用传递。

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int clen=chars.length();
        Map<Character, Integer> map = new HashMap<>();
        int result=0;
        for(char c:chars.toCharArray()){
            map.put(c,map.getOrDefault(c,0)+1);
        }
        Map<Character, Integer> temp;
        boolean flag=false;
        for(String s:words){
            flag = false;
            temp=new HashMap<>();
            for(char c:s.toCharArray()){
                
                //System.out.print(c+",");
                temp.put(c,temp.getOrDefault(c,0)+1);
                if(!map.containsKey(c) || temp.get(c)>map.get(c)){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                result +=s.length();
            }
        }
        return result;
    }
}
```