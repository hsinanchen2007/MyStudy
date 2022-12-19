### 解题思路
先将字符串转换为字符数组，再声明一个数组ascii，里面的元素存放的是字符出现的次数。
这样当你遍历字符数组的时候，每次循环就计算当前字符的ascii码值，当作那个ascii数组的下标，并且记录次数+1，这样一遍遍历之后，就能知道那个字符串每一个字符出现的次数。
接着最后遍历一次原字符串，如果字符的asicc码值对应的数组元素（即ascii数组元素）为1，那么就取出来。

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {
        char[] chars = s.toCharArray();
        int[] ascii = new int[128];
        for (int i = 0;i<chars.length;i++){
            int index = Integer.valueOf(chars[i]);//计算每一个字符的ascii码，当作下标
            ascii[index]++;//java int数组初始化默认元素为0
        }
       for (int i = 0;i<chars.length;i++){
           if (ascii[Integer.valueOf(chars[i])]==1){
               return chars[i];
           }
       }
        return ' ';
    }
}
```