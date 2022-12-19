### 解题思路
按照Z字形，将字符串S放到每一行表示一个数组里面，也就是把S拆成一个一个字符，放到每一个数组里面，遇到
最下面一行或者最上面一行，就换个方向。

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
         int direct = 1;
        String[] charactor = new String[numRows];
        int length = s.length();
        int charNum = 0;
        int row = 0;
        if(numRows==1){
            return s;
        }
        while (charNum < length) {
            charactor[row] = (charactor[row] == null ? "" : charactor[row]) + s.charAt(charNum);
            row = row + direct;
            if (row == numRows - 1) {
                direct = -1;
            }
            if (row == 0) {
                direct = 1;
            }
            charNum++;
        }
        String result = "";
        for (String str : charactor) {
            result += (str == null ? "" : str);
        }
        return result;
    }
}
```