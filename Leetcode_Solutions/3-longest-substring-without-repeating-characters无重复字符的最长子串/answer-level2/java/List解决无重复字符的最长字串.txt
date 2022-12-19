一个简单好理解的解法，list来装字符，重复直接break，不重复就装进去，每轮循环最后比较一下res和list.size()的大小
```
import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] c=s.toCharArray();
        int res=0;
        for(int i=0;i<c.length;i++)
        {
            List<Character> list = new ArrayList<Character>();
            for(int j=i;j<c.length;j++)
            {
                if(list.contains(c[j]))
                {
                    break;
                }
                else
                {
                    list.add(c[j]);
                }
            }
            res=Math.max(res,list.size());
        }
        return res;
    }
}
```
