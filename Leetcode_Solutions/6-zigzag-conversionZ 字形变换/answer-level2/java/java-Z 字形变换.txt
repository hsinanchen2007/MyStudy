### 解题思路
按照这个图进行
![image.png](https://pic.leetcode-cn.com/8ef5a8139625d52c903320fdd164cb83be53d6403c7f4c87c3535b401263da2c-image.png)

step1:入参校验，如果numRows等于1，那直接输出字符串。
      若不为1，建立一个字符串List，长度和入参numRows一样
step2:开始扫描字符串，方向是按照先右下角，再右上角，再右下角，再右上角。。。
      即遇到边就改方向。将每一行需要输出的字符串放到List<String>中。
step3:依次输出每一行要输出的字符串。

注：
1、方向的控制
2、List<String>初始化时虽然可以通过“List<String> result = new ArrayList<String>(numRows);”指定长度，但并不能直接取值，因此要先对List<String> 进行初始化。
3、取子字符串，string1.substring(2,5),取第2，3，4个字符





### 代码

```java
class Solution {
  public static String convert(String s, int numRows) {
        if (numRows == 1){
            return s;
        }
        List<String> strList = new ArrayList<String>();
        List<String> result = new ArrayList<String>(numRows);
        for (int i = 0; i < numRows; i++) {
            strList.add(s);
            result.add("");
        }
        int direction = 1;
        int x = 0;

        for (int i = 0; i < s.length(); i++) {
            String temp = result.get(x) + strList.get(x).substring(i, i + 1);
            result.set(x, temp);
            if (x + direction > numRows - 1 || x + direction < 0) {
                direction = direction * (-1);
            }
            x = x + direction;
        }
        String res = "";
        for (String str : result) {
            res = res + str;
        }
        return res;

    }
}
```