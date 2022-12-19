### 解题思路
总结，在创建HashMap的时候put的创建思路并不是按照顺序来的，后面可以去钻研一下
第二，在对比两个HashMap值的情况下，不要忘记了可以用Map的get方法，由key得到值，但是如果是想由值得到Key就只能用entry遍历了

### 代码

```java
import java.util.HashMap;
import java.util.Map;
//用HashMap 统计字母表中每个字母的个数，同时统计单词表中每个单词的字母的个数，如果该单词和字母表中的单词字母个数对比
//比较少的话就说明该单词可以由字母表表示，
public class Solution {
    private Map<Character,Integer> countChars(String chars){ //Character是对单个字符进行操作的类
        Map<Character,Integer> counts = new HashMap<Character,Integer>();
        for(int i=0;i<chars.length();i++ ){
            if(!counts.containsKey(chars.charAt(i))){
                counts.put(chars.charAt(i),1);
            }
            else{
                counts.put(chars.charAt(i),counts.get(chars.charAt(i))+1);//实际上hashMap的put算法有点复杂，它并不是按照顺序来的，这个有兴趣后面再分析
            }
        }
        return counts;
    }
    public int countCharacters(String[] words,String chars){
        int sum=0;
        boolean it = false;
        if(words.length==0||chars.length()==0) return sum;
        Map<Character,Integer> charsCount=countChars(chars);
        for(String word:words){
            Map<Character,Integer> wordCount=countChars(word);
            for(Map.Entry<Character,Integer> entry:wordCount.entrySet()){
                //System.out.println( entry.getKey()+":"+ charsCount.get(entry.getKey()));
                if(charsCount.get(entry.getKey())==null) {it=false; break;}
                if(charsCount.get(entry.getKey())>=entry.getValue()) {it =true;}
                else {it=false;break;}
            }
            if(it){
                sum+=word.length();
                it=false;
            }

        }
        return sum;
    }
}
```