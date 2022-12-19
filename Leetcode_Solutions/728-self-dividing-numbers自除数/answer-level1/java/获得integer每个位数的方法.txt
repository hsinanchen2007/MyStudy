### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
        for (int i = left; i <= right; i++) {
            if (isSelf(i)) {
                list.add(i);
            }
        }
        return list;
    }

    private boolean isSelf(int i) {
        String string = String.valueOf(i);
        char[] chars = string.toCharArray();
        for (Character character : chars) {
            if (character == '0' || i % (character - '0') != 0) {
                return false;
            }
        }
        return true;
    }
}
```