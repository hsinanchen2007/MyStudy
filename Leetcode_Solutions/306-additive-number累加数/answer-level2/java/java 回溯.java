### 解题思路
### 代码

```java
class Solution {
    public boolean isAdditiveNumber(String num) {
        for(int i=1;i<num.length()-1;i++)//遍历前两个数所有的可能
         for(int j=i+1;j<num.length();j++)
           {
               if(backtrack(num,0,i,j))
                return true;
           }
        return false;
    }
    boolean backtrack(String num,int i,int j ,int k){//ijk为第1,2,3个数的起始位置
     String first=new String(),second=new String();
     String sum;
     for(int l=i;l<j;l++)
     {
         first+=String.valueOf(num.charAt(l));
     }
     for(int l=j;l<k;l++)
     {
         second+=String.valueOf(num.charAt(l));
     }
     if((first.charAt(0)=='0'&&(first.length()!=1)||(second.charAt(0)=='0'&&second.length()!=1)))//单独的零是可以存在的，其他情况第一位不能为零
     return false;
     sum =String.valueOf(Long.valueOf(first)+Long.valueOf(second));//sum为前两位数字相加
     if(k+sum.length()>num.length())//第三位长度不够，返回false
      return false;
     for(int l =k,p=0;p<sum.length();l++,p++)//第三位数匹配
     {
         if(num.charAt(l)!=sum.charAt(p))
          return false;
     }
     if(k+sum.length()==num.length())//刚好到最后一位，返回true
      return true;
     else return backtrack(num,j,k,k+sum.length());
    }
}
```