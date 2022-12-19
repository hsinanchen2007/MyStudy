### 解题思路

贼蠢，没想到length - 2！

### 代码

```java
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
    String[] temp;
        List<String> result = new ArrayList<>();
        temp = text.split(" ");
        for (int i = 0; i < temp.length; i++) {
            if (i + 2 >= temp.length) break;
            if (temp[i].equals(first)  && temp[i + 1].equals(second)) {
                result.add(temp[i + 2]);
            }
        }
        return result.toArray(new String[result.size()]);
    }
}
```