### 解题思路
直接看代码注释即可， 双100.00%方法

### 代码

```java
class Solution {
    public String compressString(String S) {
        //如果传来字符串为空或者长度小于3则直接返回字符串
        //小于3因为   aaa >> a3返回a3     aa >> a2 返回 aa
        if (S == null || S.length() < 3) {
            return S;
        }
        //将字符串转换为char数组
        char[] chars = S.toCharArray();
        StringBuilder builder = new StringBuilder();
        int count = 1;
        for (int i = 0,len = chars.length; i < len; i++) {
            //判断当前的是否与后一位相等，相等数量加1，i加1
            while (i < len - 1 && chars[i] == chars[i+1]) {
                count++;
                i++;
            }
            //循环跳出则添加在字符串中
            builder.append(chars[i]).append(count);
            count = 1;
        }

        return S.length() > builder.length() ? builder.toString() : S;
    }
}
```