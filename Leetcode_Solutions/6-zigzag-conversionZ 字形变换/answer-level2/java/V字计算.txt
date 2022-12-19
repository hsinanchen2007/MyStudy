### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        int vSize = 2 * numRows - 2;
        if (s.length() <= numRows || vSize == 0) {
            return s;
        }
        List<String> vList = new ArrayList<>();
        for (int i = 0; i < s.length(); i = i + vSize) {
            if (i + vSize > s.length()) {
                vList.add(s.substring(i));
            } else {
                vList.add(s.substring(i, i + vSize));
            }

        }
        StringBuilder result = new StringBuilder();
        int row = 0;
        for (; row < numRows; row++) {
            for (String item : vList) {
                if (!item.isEmpty()) {
                    char[] itemChar = item.toCharArray();
                    if (row < itemChar.length) {
                        result.append(itemChar[row]);
                    }
                    int vIndex = vSize - row;
                    if (row > 0 && row < numRows - 1 && vIndex > 0 && vIndex < itemChar.length) {
                        result.append(itemChar[vIndex]);
                    }
                }
            }
        }
        return result.toString();
    }
}
```