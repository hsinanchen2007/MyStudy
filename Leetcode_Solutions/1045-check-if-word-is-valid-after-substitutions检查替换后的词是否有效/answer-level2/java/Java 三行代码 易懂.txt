### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isValid(String S) {
        while (S.contains("abc"))
            S = S.replace("abc", "");
        return S.equals("");
    }
}

//另一种解法：
    // public boolean isValid(String S) {
    //     StringBuffer sb=new StringBuffer(S);
    //     while(sb.toString().contains("abc")){
    //     	sb.delete(sb.indexOf("abc"), sb.indexOf("abc")+3);
    //     }
    //     return sb.length()==0;
    // }
```