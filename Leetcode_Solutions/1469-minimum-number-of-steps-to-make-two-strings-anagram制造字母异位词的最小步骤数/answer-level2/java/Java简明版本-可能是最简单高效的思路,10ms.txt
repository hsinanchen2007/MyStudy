![360截图20200211115328473.jpg](https://pic.leetcode-cn.com/df080fecde19072cfb7af2976a51f7ef94af30b44c4ddc5dd9ea3d7ebe8b34cf-360%E6%88%AA%E5%9B%BE20200211115328473.jpg)

**题目**：给你两个长度相等的字符串 s 和 t。每一个步骤中，你可以选择将 t 中的 任一字符 替换为 另一个字符。
返回使 t 成为 s 的字母异位词的最小步骤数。（s 和 t 只包含小写英文字母）

显然，我们需要求的就是s与t两个字符串中，t与s不同的字符数。而且字符都是小写字母。
那么一个很直接的想法就是：现将s中所有的字符进行计数，用一个数组进行储存，再将t中的每一个字符在s对应的字符数仍可满足(即>0)时进行--(减1)，若已经减到0就不再操作，那么自然最后这个数组中剩余的数的总和也就是s与t中需转换的不同字符的总数。

代码如下：
```
class Solution 
{
    public int minSteps(String s, String t) 
    {
        int sum=0;
        int[] a=new int[26];
        char[] ch1=s.toCharArray();
        char[] ch2=t.toCharArray();
        for(char c:ch1)a[c-'a']++;
        for(char c:ch2)if(a[c-'a']>0)a[c-'a']--;
        for(int n:a)sum+=n;
        return sum;
    }
}
```
