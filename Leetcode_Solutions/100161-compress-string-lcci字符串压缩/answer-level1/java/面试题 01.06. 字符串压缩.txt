### 解题思路
快慢指针  i是慢指针，j是快指针

### 代码

```java
class Solution {
    public String compressString(String S) {
       int length = S.length();
     if (S==null || length==0) return S;
        int i=0,j=0;
        int sum=0;
        StringBuilder NewString=new StringBuilder();
        while (j<length)
        {
            if (S.charAt(i)==S.charAt(j))
            {
                j++;
            }else {
                NewString.append(S.charAt(i)).append(j-i);
                i=j;
            }
        }
        NewString.append(S.charAt(i)).append(j-i);
        if (NewString.length()>=length) return S;
        return String.valueOf(NewString);
    }
}
```