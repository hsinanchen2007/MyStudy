### 解题思路
1.字符串转为字符数组
2.使用数组排序
3.字符数组转回字符串
4.比较

### 代码

```java
import java.util.Arrays;
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        //从新排序
        boolean flag ;
        char[] char1 = s1.toCharArray();
        char[] char2 = s2.toCharArray();
        Arrays.sort(char1);
        Arrays.sort(char2);
        s1 = String.valueOf(char1);
        s2 = String.valueOf(char2);
        if(s1.equals(s2)){
            flag = true;
        }else{
            flag = false;
        }
        return flag;
    }
}
```