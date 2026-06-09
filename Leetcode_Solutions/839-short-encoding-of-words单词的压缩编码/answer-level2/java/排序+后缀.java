### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Arrays.sort(words, (o1, o2) -> o2.length() - o1.length());

        StringBuilder result = new StringBuilder();
        result.append(words[0] + "#");
        int total = words[0].length() + 1;
        for(int i = 1; i < words.length; i++) {
            if(result.indexOf(words[i] + "#") < 0) {
                result.append(words[i] + "#");
                total += words[i].length() + 1;
            }
        }
        return total;
    }
}
```