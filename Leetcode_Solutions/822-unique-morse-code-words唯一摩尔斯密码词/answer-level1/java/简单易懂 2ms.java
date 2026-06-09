### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> set = new HashSet();
        StringBuilder temp;
        String[] table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<words.length;i++){
            temp = new StringBuilder();
            for(int j=0;j<words[i].length();j++){
                char ch = words[i].charAt(j);
                int index = ch - 'a';
                temp.append(table[index]);
            }
            set.add(temp.toString());
        }
        return set.size();
    }
}
```