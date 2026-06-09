### 解题思路
滑动窗口法解决该问题

### 代码

```java
class Solution {
    public boolean checkInclusion(String s1, String s2) {
        //Java语言滑动窗口法，统计字母出现的次数
        if(s2.length()<s1.length())
            return false;
        int [] book=new int[26];
        for(int i=0;i<s1.length();i++)
            book[s1.charAt(i)-'a']++;

        int [] book1=new int[26];
        for(int i=0;i<s1.length();i++)
            book1[s2.charAt(i)-'a']++;
        
        if(check(book,book1))
            return true;
        int left=0,right=s1.length();
        while(right<s2.length())
        {
            book1[s2.charAt(left)-'a']--;
            left++;
            book1[s2.charAt(right)-'a']++;
            right++;
            if(check(book,book1))
                return true;
        }
        return false;
    }

    private boolean check(int []book,int []book1)
    {
        for(int i=0;i<26;i++)
        {
            if(book[i]!=book1[i])
                return false;
        }
        return true;
    }
}
```