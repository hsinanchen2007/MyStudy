### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.*;
class Solution {
    public int countCharacters(String[] words, String chars) {
 Map<Character,Integer> map=new HashMap<>();
        int count=0;
        boolean judge=true;
        for(int a=0;a<chars.length();a++){

            if(map.containsKey(chars.toCharArray()[a])){map.put(chars.toCharArray()[a],map.get(chars.toCharArray()[a])+1);}
            else{
                map.put(chars.toCharArray()[a],1);
            }


        }
        Map<Character,Integer> mapWords=new HashMap<>();

        for(int i=0;i<words.length;i++){
            for(int b=0;b<words[i].length();b++){
                if(mapWords.containsKey(words[i].toCharArray()[b])){
                    mapWords.put(words[i].toCharArray()[b],mapWords.get(words[i].toCharArray()[b])+1);
                }else{
                    mapWords.put(words[i].toCharArray()[b],1);
                }



            }
            for(Map.Entry<Character,Integer> h:mapWords.entrySet()){
                if(map.containsKey(h.getKey())&&h.getValue()<=map.get(h.getKey())){
                    judge=true;
                }else{
                    judge=false;break;
                }

            }

            if(judge){count=words[i].length()+count;}


            mapWords.clear();
        }







        return count;

    }
}
```