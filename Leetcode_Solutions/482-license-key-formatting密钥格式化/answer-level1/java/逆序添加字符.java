### 解题思路
先把字符串转换成大写，然后逆序遍历，每添加一个，count计数，判断count是否能整除K，最后注意一下可能会出现多添加一个'-'字符，删除即可。

### 代码

```java
class Solution {
    public String licenseKeyFormatting(String S, int K) {
        String str = S.toUpperCase();
        StringBuilder sb = new StringBuilder();
        int count = 0;
        for(int i = str.length()-1;i >= 0;i--){
            if(str.charAt(i) != '-'){
                sb.insert(0,str.charAt(i));
                count++;
                if(count % K == 0){
                    sb.insert(0,'-');
                }
            }
        }
        if(sb.length() > 0 && sb.charAt(0) == '-'){
            sb.delete(0,1);
        }
        return sb.toString();
    }
}
```