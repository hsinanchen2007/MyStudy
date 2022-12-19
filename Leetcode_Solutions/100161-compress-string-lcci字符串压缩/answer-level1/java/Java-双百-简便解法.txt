### 解题思路
字符串拆成数组，遍历整个数组，遇到重复计数器加1,遇到不等的，则将当前字符和次数加入字符串中；最后比较遍历完的数组的长度，如果长度没有减少返回原字符串。

### 代码

```java
class Solution {
    public String compressString(String S) {
        char[] ss = S.toCharArray();
        int times = 1;
        StringBuilder stringBuilder = new StringBuilder();
        for(int i = 0; i < ss.length; i++) {
            if(i == ss.length-1){
                stringBuilder.append(ss[i]);
                stringBuilder.append(times);
                break;
            }
            if(ss[i] == ss[i+1]){
                times++;
            }else{
                stringBuilder.append(ss[i]);
                stringBuilder.append(times);
                times = 1;
            }
        }
        String S1 = stringBuilder.toString();
        if(S.length() > S1.length()){
            return S1;
        }else{
            return S;
        }
    }
}
```