### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> printVertically(String s) {

        String[] strs = s.split(" ");
        // System.out.println(Arrays.toString(strs));

        // Java8 Stream API + lambda Expressions 求最长单词长度...
        int maxLength = Arrays.stream(strs) 
                .max((a, b) -> a.length() - b.length())
                .get()
                .length();

        List<StringBuilder> rows = new ArrayList<>(maxLength);
        for (int i = 0; i < maxLength; i++) rows.add(new StringBuilder());

        for (String str : strs)
            for (int i = 0; i < maxLength; i++)
                rows.get(i).append(i >= str.length() ? ' ' : str.charAt(i));

        List<String> ans = new ArrayList<>();
        for (StringBuilder sb : rows)
            ans.add(sb.toString().replaceAll("\\s+$", "")); // replace尾部空格 ... 
        
        return ans;
    }
}
```