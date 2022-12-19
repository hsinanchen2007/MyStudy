### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        String[] ss=s.trim().split(" +");//" +"表示可能有多个空格.
        int len=ss.length;
        StringBuffer sb=new StringBuffer();
        for(int i=len-1;i>0;i--){
            sb.append(ss[i]+" ");
        }
        sb.append(ss[0]);
        return sb.toString();
    }
}
```