### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
         // 1、判断特殊情况
        if (s == null || s.length() == 0 || numRows <=1 ) return s;

        // 2、使用StringBuffer数组和方向dir进行拼接
        StringBuffer[] arr = new StringBuffer[numRows];  // 初始化数组
        for (int i = 0; i < numRows; i++) {
            arr[i] = new StringBuffer();
        }

        int index = 0;
        int dir = 1;
        for (char c : s.toCharArray()) {
            arr[index].append(c);
            index+=dir;
            if (index == 0 || index == numRows - 1) dir = -dir; // 方向改变
        
        }

        // 3、拼接所有的stringbuffer数组，输出结果
        StringBuffer res = new StringBuffer();
        for (int i = 0; i < arr.length; i++) {
            res.append(arr[i]);
        }
        return res.toString();

    }
}
```