### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public String countAndSay(int n) {
        String str = "1";
        for (int i = 2; i <= n; i++) {
            str = doSay(str);
        }
        return n == 1 ? "1":str;
    }

    private String doSay(String str) {
        StringBuilder res = new StringBuilder();
        int count = 1;
        for (int i = 0;i < str.length();i++){
            //如果i到最后一个元素了直接拼接
            while (i < str.length() -1 && str.charAt(i)==str.charAt(i+1) ) {
                count++;
                i++;
            }
            res.append(count).append(str.charAt(i));
            //重新初始化
            count = 1;
        }
        return res.toString();
    }
}
```