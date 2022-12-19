### 解题思路
这个题明显是一道map题，构建HashMap，第一个字符串每个字符作为key，第二个字符串每个字符对应value。如果有一个key对应两个value的，则不是同构字符串，返回false。由于两个字符串要一一对应，因此一个Value也不能对应两个key。我们先写一个子函数，然后交换参数列表中两个字符串的位置，分别比较。当两种情况都对应上时，此时即为同构字符串。

### 代码

```java
class Solution {
    private boolean isIsomorphicHelper(String s,String t)
    {
        int n=s.length();
        HashMap<Character,Character> map=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            char c1=s.charAt(i);
            char c2=t.charAt(i);
            if(map.containsKey(c1))
            {
                if(map.get(c1)!=c2)
                    return false;
            }
            else
                map.put(c1,c2);
        }
        return true;
    }
    public boolean isIsomorphic(String s, String t) {
       return  isIsomorphicHelper(s,t)&&isIsomorphicHelper(t,s);
        
    }
}
```