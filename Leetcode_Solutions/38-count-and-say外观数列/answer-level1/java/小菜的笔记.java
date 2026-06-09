### 解题思路
此处撰写解题思路
注意递归的使用。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if(n>1){
            return frequency(countAndSay(n-1));
        }
        else return "1";

    }
    private String frequency(String s){
        StringBuilder sb=new StringBuilder();
        char s1=s.charAt(0);
        int count=1;
        for(int i=1;i<s.length();i++){
            char num=s.charAt(i);
            if(s1==num){
                count++;
            }
            else{
                sb.append(count);
                sb.append(s1);
                s1=num;
                count=1;
            }
        }
        sb.append(count);
        sb.append(s1);
        return sb.toString();

    }
}
```