### 解题思路

```java
class Solution {
    public String toLowerCase(String str) {
         char[] chars = str.toCharArray();
        StringBuilder sb= new StringBuilder();
        for (char ch : chars) {
            if (ch >=65 &&  ch <= 90){
                sb.append((char) (ch + 32));
            }else {
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}
```