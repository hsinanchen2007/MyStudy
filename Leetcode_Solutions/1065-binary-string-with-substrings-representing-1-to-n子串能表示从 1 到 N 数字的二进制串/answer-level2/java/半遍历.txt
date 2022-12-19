### 解题思路
只需要遍历N/2~N即可，这是因为，只要包含x的二进制表示，一定包含x/2、x/4、x/8、...的二进制表示，换句话说，判断了2a，就不用再判断a，也不用判断a/2...
但是反过来不成立，即包含a不一定包含2a
对于前半段的每一个元素，一定可以通过不断乘2，使得值落在后半段的范围，根据等价性，判断了后半段都存在，前半段不用再判断，一定也存在。
### 代码

```java
class Solution {
    public boolean queryString(String S, int N) {
        for(int i=Math.max(1,N/2);i<=N;i++)
        {
            if(S.indexOf(Integer.toBinaryString(i))==-1)
            return false;
        }
        return true;
    }
}
```