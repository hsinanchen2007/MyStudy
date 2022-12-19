### 解题思路


### 代码

```java
class Solution {
    public String[] findOcurrences(String text, String first, String second) {
        String[] strings = text.split(" ");
        String target = first + " " + second;
        List<String> results = new ArrayList<>();
        for (int i = 0; i < strings.length - 2; i++) {
            if ((strings[i] + " " + strings[i + 1]).equals(target)) {
                results.add(strings[i + 2]);
            }
        }

        String[] reals = new String[results.size()];
        for (int i = 0; i < results.size(); i++) {
            reals[i] = results.get(i);
        }
        return reals;
    }
}
```