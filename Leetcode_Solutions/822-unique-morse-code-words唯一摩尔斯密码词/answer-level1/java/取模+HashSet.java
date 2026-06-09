### 解题思路
- 使用一个数组来保存code编码
- 挨个遍历，使用StringBuilder拼接
- 放入HashSet集合
- 返回HashSet的size

### 代码

```java
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> set = new HashSet<>();
        String [] code ={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for (String word : words) {
            StringBuilder sb = new StringBuilder();
            char[] chars = word.toCharArray();
            for (char ch : chars) {
                int tmp = (ch -'a') %26;
                sb.append(code[tmp]);
            }
            set.add(sb.toString());
        }
        return set.size();
    }
}
```