### 解题思路
循环一次字符串，用2个变量记录当前字符和计数，进行循环判断拼接，注意最后一次循环后字符还差一次拼接

### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S == null || S.length() == 0){
            return "";
        }
        //拼接后的字符串
        String S1 = "";
        //当前循环的字符
        char tmp = S.charAt(0);
        //当前字符出现计数
        int count =1;
        for(int i=1; i<S.length(); i++){
            if(S.charAt(i)==tmp){
                count++;
            }else{
                S1 = S1 + tmp + count;
                tmp = S.charAt(i);
                count = 1;
            }
        }
        //注意：最后一次循环后字符串还差一次拼接
        S1 = S1 + tmp + count;
        return S1.length() < S.length() ? S1 : S;

    }
}
```