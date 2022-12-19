### 解题思路
其他代码写多了，真的不知道char和string，stringbuilder都咋运算了。

### 代码

```java
class Solution {
    public String compressString(String S) {
        int length=S.length();
        if(length==0){
            return "";
        }
        char[] chars=S.toCharArray();
        StringBuilder sb=new StringBuilder();
        char temp=chars[0];
        int cnt=1;
        for(int i=1;i<length;i++){
            if(temp==chars[i]){
                cnt++;
            } else {
                sb.append(temp);
                sb.append(cnt);
                temp=chars[i];
                cnt=1;
            }
        }
        sb.append(temp);
        sb.append(cnt);

        if(sb.length()>=length){
            return S;
        } else {
            return sb.toString();
        }
    }
}
```