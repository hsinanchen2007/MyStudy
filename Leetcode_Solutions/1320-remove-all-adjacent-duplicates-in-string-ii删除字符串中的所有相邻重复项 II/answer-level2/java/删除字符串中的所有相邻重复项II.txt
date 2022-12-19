### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //删除字符串中的相邻重复项，II
    public String removeDuplicates(String s, int k) {
        return helper(s,k);
    }

    private String helper(String s,int k)
    {
        if(k>s.length())
            return s;
        char [] chars=s.toCharArray();
        char key=chars[0];
        int count=1;
        for(int i=1;i<chars.length;i++)
        {
            if(chars[i]==key)
            {
                if(++count==k)
                    return helper(s.substring(0,i-k+1)+s.substring(i+1),k);
            }
            else
            {
                key=chars[i];
                count=1;
            }
        }
        return s;
    }
}
```