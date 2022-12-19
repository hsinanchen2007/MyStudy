### 解题思路
我比较笨，就遍历就完事了。

### 代码

```java
class Solution {
    String[] moles={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    public int uniqueMorseRepresentations(String[] words) {
        Set<String> s=new HashSet<>();
        for(int i =0;i<words.length;i++){
            StringBuilder sb=new StringBuilder();
            for(int j=0;j<words[i].length();j++){
                char c=words[i].charAt(j);
                sb.append(moles[c-'a']);
            }
            s.add(sb.toString());
        }
        return s.size();

    }
}
```