### 解题思路
如果s是t的异位词，则两个字符串使用的字母应该完全一样，即每个字母两个字符串都使用了相同的次数。于是可以运用散列的思想，用一个int[]数组作散列表，记录字母剩余使用次数，若两个字符串是异位词，则最后散列表中所有字母的剩余使用次数应该均为0。数组大小为26。具体操作：扫描两个字符串，对第一个字符串使用的每个字母，剩余使用次数加一；对第二个字符串使用的每个字母，剩余使用次数减一，字母a用下标0表示，以此类推。最终判断每个字母的剩余使用次数是否均为0。如果两个字符串连长度都不相等，则一定不是异位词，直接返回false。
时间复杂度：O(n)。因为必须遍历一遍散列表。
空间复杂度：O(1)。散列表的大小不会因字符串的长度而改变。

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        if(s.length()!=t.length())
            return false;
        int[] counter=new int[26];
        for(int i=0;i<s.length();i++)
        {
            counter[s.charAt(i)-'a']++;
            counter[t.charAt(i)-'a']--;
        }
        for(int i=0;i<26;i++)
            if(counter[i]!=0)
                return false;
        return true;
    }
}
```