### 解题思路

### 代码

```java
class Solution {
    public List<String> commonChars(String[] A) {
        //本题可以理解为求每个字符串之间字符数量的交集,考虑到效率，我们可以使用数组优化哈希表的代码，用数组res的下标i分清是哪个字符，用res[i]表示字符出现的次数。（类似哈希表的思想）
        List<String> list =new ArrayList<>();
        int []res=new int[26];
        for(char c:A[0].toCharArray())  //统计列表中第一个字符串中每个字母的个数
        {
            res[c-'a']++;
        }

        for(int i=1;i<A.length;i++)
        {
            int []temp=new int[26];
            for(char c:A[i].toCharArray())
                temp[c-'a']++;
            for(int j=0;j<26;j++)
                res[j]=Math.min(res[j],temp[j]);
        }

        for(int i=0;i<res.length;i++)
        {
            if(res[i]>0)
                for(int j=0;j<res[i];j++)
                    list.add(((char) ('a'+i)+""));
        }
        return list;   
    }
}
```