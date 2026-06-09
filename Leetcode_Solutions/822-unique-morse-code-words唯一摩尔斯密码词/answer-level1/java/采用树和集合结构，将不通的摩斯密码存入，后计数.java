### 解题思路
将26个字母的摩斯密码写入一个String数组中，
声明一个集合树，
遍历传入的单词数组，将每一个字母都转换为摩斯密码，后拼接
在集合中进行去重，
最后返回长度

### 代码

```java
// import java.util.TreeSet;

class Solution {
    public int uniqueMorseRepresentations(String[] words) {

         String[] codes={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
         TreeSet<String> set=new TreeSet();
         for (String word:words){
             StringBuilder res=new StringBuilder();
             for (int i = 0; i <word.length() ; i++) {
                   res.append(codes[word.charAt(i)-'a']);
             }
             set.add(res.toString());//重复的话，忽略该行
         }
         return set.size();
    }
}
```