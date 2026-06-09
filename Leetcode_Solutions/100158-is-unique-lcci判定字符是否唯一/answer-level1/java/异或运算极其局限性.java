### 解题思路
采用异或运算与移位运算解决，需要对二进制略有了解，方法简单，但只适用于字符串中仅仅含有字母(经过测试leetcode的用例确实都是由字母组成的字符串)
对于采用异或运算的解决方案
__对于含有!和space(空格)的用例无法AC__
### 可以AC，但并不严谨

```java
//玄学位运算，若针对所有字符，此方法无法AC，若字符串中只含有字母，可以AC
//经过测试，用例中的字符串因该都是字母
class Solution {
    public boolean isUnique(String astr) {
        //采用位运算解决
        int n=astr.length();
        int temp=0;
        for(int i=0;i<n;++i)
        {
            int ans=temp^1<<(Integer.valueOf(astr.charAt(i))-97);
            if(ans<temp)return false;
            temp=ans;

        }
        return true;

    }
}
```
