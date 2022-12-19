稍微有点取巧的做法，reverse函数也可以用双指针实现。
```
class Solution 
{
    public String reverseWords(String s) 
    {
        String[] sp=s.split(" ");
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<=sp.length-1;i++)
        {
            StringBuilder t=new StringBuilder();
            t.append(sp[i]);
            sb.append(t.reverse().toString()).append(" ");
        }
        return sb.substring(0,sb.length()-1);
    }
}
```
