### 解题思路
字符出现偶数次构成回文串，每个字符都出现偶数次，有一个字符出现一次也可以构成字符串

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        //统计每个字符出现的次数
        if(s==null || s.length()==0)
        return 0;
        int[] count=new int[256];
        for(int i=0;i<s.length();i++)
        {
            count[s.charAt(i)]++;
        }
        int len=0;
        for(int cnt:count)
        {
            len+=cnt/2*2;
        }
        if(len<s.length())
        len++;
        return len;
    }
}
```
### 复杂度
- 时间复杂度：O(n)
- 空间复杂度：O(n)，开辟了一个数组