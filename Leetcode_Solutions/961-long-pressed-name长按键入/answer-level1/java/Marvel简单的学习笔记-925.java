### 解题思路
双指针思路比较简单。用两个指针i、j分别扫描name、typed两个字符串，每次扫描分类讨论：
- i、j指向的两个字符相等，则继续往后扫描。
- 不等，但j指向的字符等于i-1指向的字符，说明长按了，j单独往后扫描。
- 不等，并且j指向的也不等于i-1指向的字符串，返回false。
- i没扫描完，j却扫描完了，也是返回false。
另外，单独判断两个字符串的第一个字符，若第一个字符就不等，则直接返回false。
时间复杂度：O(n)。
空间复杂度：O(1)。

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i=0,j=0;
        if(name.charAt(0)!=typed.charAt(0)) return false;
        while(i<name.length())
        {
            if(j==typed.length())   return false;
            if(name.charAt(i)!=typed.charAt(j))
            {
                if(typed.charAt(j)==name.charAt(i-1))
                    j++;
                else    return false;
            }
            else    
            {
                i++;
                j++;
            }
        }
        return true;
    }
}
```