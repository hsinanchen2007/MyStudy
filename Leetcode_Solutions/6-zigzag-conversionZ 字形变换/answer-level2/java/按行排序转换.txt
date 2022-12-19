### 解题思路

见代码注释

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
        //按行排序
        if(numRows == 1 || s.length() < numRows) {
            return s;
        }
        List<StringBuilder> list = new ArrayList<>();
        for(int i = 0; i < numRows; i++) {
            list.add(new StringBuilder()); //创建行字符储存对象
        }
        int curRow = 0; //当前行对象
        boolean goingDown = false; //当前方向
        for(char c : s.toCharArray()) {
            list.get(curRow).append(c);
            if(curRow == 0 || curRow == numRows - 1) {
                //首尾转换方向
                goingDown = !goingDown;
            }
            curRow += goingDown ? 1 : -1; //根据当前方向增减行数，确保添加字符无误
        }
        StringBuilder res = new StringBuilder();
        for(StringBuilder sb : list) {
            res.append(sb); //将整理好的字符串添加到一行中
        }
        return res.toString();
    }
}
```