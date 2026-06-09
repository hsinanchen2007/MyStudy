### 解题思路
去掉首位空格，使用split根据空格分隔String成String数组，返回String数组最后一位即可。

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        if (s.length() == 0){
            return 0;
        }

        String[] array = s.split(" ");
        return array[array.length - 1].length();
    }
}
```