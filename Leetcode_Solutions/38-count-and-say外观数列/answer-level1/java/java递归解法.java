### 解题思路


### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if(n==1) return "1";
        String tmp=countAndSay(n-1);
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<tmp.length();i++){
            char ch=tmp.charAt(i);
            int count=0;
            while(i<tmp.length()&&tmp.charAt(i)==ch){
                i++;
                count++;
            }
            if(i<tmp.length()) i--;
            sb.append(count);
            sb.append(ch);
        }
        return sb.toString();
    }
}
```