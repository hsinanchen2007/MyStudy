### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int result = 0;
        char[] chs = s.toCharArray();
        List<Character> list = new LinkedList<>();
        for (int i = 0; i < chs.length; i++) {
            list.add(chs[i]);
            if (list.size() > 0 && list.size() % 2 == 0) {
                if (isBalanced(list)) {
                    result++;
                    list.clear();
                }
            }
        }
        return result;
    }

    boolean isBalanced(List<Character> list) {
        long lCount = list.stream().filter(c -> c == 'L').count();
        long rCount = list.stream().filter(c -> c == 'R').count();
        return lCount == rCount;
    }
}
```