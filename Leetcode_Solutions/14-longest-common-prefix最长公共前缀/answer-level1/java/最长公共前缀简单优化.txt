# 简单优化
![image.png](https://pic.leetcode-cn.com/2d689f5c68bde112c2b77913cd6f7c8898c7427beb30a51d7bafd30614fcf4a3-image.png)
***
- **优化思路有两处**
> 减少循环次数；
> 找到给定字符串集合中的最短字符串长度，这样再每次循环时我们只需检查`j`是否大于当前串的长度
> 添加循环跳出判断，如果出现任意一个字符串与参考串的公共前缀为`0`那么整个给定字符集的公共前缀肯定为`0`可以直接跳出循环
***
 **代码中通过注释解释部分问题**

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs==null||strs.length<=0)
        return "";
        if(strs.length==1)
        return strs[0];
        return findCommStr(strs);
    }
    private String findCommStr(String[] strs)
    {
        //初始化参考串；参考串可以是第一个strs[0]；也可以时最后一个strs[strs.length-1]；
        //需要注意的是如果参考串是最后一个那么下面循环判入条件为strs.length-1；初始化i=0;
        String  ans=strs[0];
        //整个给定字符集中最短字符长度
         int minLen=ans.length();
        for(int i=1;i<strs.length;i++)
        {
           if(strs[i].length()<minLen) minLen=strs[i].length();
        }
        //假设当前公共前缀长度最小为min
        int min=ans.length();       
       for(int i=1;i<strs.length;i++)
       {
           int j=0;
           for(;j<minLen;j++)
           {
               if(strs[i].charAt(j)!=ans.charAt(j))
               break;
           }
        //如果发现存在一个比min还小的公共长度那么对min进行更新，在循环内部尽量不要执行substring()这样的耗时操作
        //我们拿到最长公共串的长度后再返回时进行substring();
         if(j<min) min=j; 
        //如果出现任意一个字符串与参考串的公共前缀为`0`那么整个给定字符集的公共前缀肯定为`0`可以直接跳出循环
         if(min==0)
         {
            return ""; 
         }       
       }
     return  ans.substring(0,min);
    }
}
```