![360截图20200218121958164.jpg](https://pic.leetcode-cn.com/aa112c59742fc1df8a8722fee975ffb414637e9542668f0edbb26380a812e8f6-360%E6%88%AA%E5%9B%BE20200218121958164.jpg)
# **方法一**
  创建一个长度为255的数组，对应所有的字符的ASCII码，并遍历字符串的每一个字符，把相应的计数次数+1。
```
class Solution 
{
    public boolean isUnique(String astr) 
    {
        int[] cnt=new int[255];
        char[] ch=astr.toCharArray();
        for(char c:ch)
        {
            cnt[(int)c]++;
            if(cnt[(int)c]>1)return false;
        }
        return true;
    }
}

```
# **方法二**
  对于字符串中的每一个字符，用indexOf(astr.charAt(i),i+1)确定该位置是否与后面的部分有重复，若有重复(返回值!=-1)，则直接return false;否则一直未找到则return true。
```
class Solution 
{
    public boolean isUnique(String astr) 
    {
        for(int i=0;i<=astr.length()-1;i++)
        {
            if(astr.indexOf(astr.charAt(i),i+1)!=-1)return false;
        }
        return true;
    }
}
```
