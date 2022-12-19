### 解题思路
找规律解法：
行数等于一，直接输出字符串；大于一则
第一行和最后一行相邻字符串位置差2*(numRows-1);
中间行的相邻字符串位置差分别是2*(numRows-1)-2*row(row代表第几行)、2*row相交替
依次添加字符就可以了。

### 代码

```java
class Solution {
    public String convert(String s, int numRows) {
    if(s==null||s.length()==0||numRows==1)
    {
        return s;
    }
    StringBuilder a=new StringBuilder(s.length());
    int row=0;
    int dis=2*(numRows-1);
    while(row<numRows)
    {
     int first=dis-row*2;
     int last=row*2;
      boolean tai=true;
    if(row==0||row==numRows-1){
      for(int i=row;i<s.length();i=i+dis)
      {
          a.append(s.charAt(i));
      }
    }else{
     for(int i=row;i<s.length();)
     {
      a.append(s.charAt(i));
      if(tai)
      {
      i=i+first;
      tai=false;
      }else{
          i=i+last;
          tai=true;
      }
     }
    }
     row++;
    }
    return a.toString();
    }
}
```