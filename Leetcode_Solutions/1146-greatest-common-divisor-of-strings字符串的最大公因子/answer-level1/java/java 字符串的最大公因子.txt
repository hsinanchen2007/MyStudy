### 解题思路
先看看能不能除尽，能除尽就求最小公因数
求最小公因数：两个字符串中都有最小的公因数，所以只用求出公因数的长度，再用substring(0,b)；截取一下就可以。
求最小公因数长度：用b=str1.length()%str2.length()==0，a=b;一直循环，知道b为0，返回a

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2){
        char[] array=new char[str1.length()];
        int length=str2.length();
        array=str1.toCharArray();
        //用余数来判断
        for(int i=0;i<str1.length();i++)
        {
            int index=i%length;
            //判断能否除尽
            if(str2.charAt(index)!=array[i])
            {
                return "";
            }
        }
        //求公因数
        return str1.substring(0,getIndex(str1.length(),length));
    }
    //得到公因数的个数
    public int getIndex(int a,int b)
    {
        //注意：getIndex(b,a%b)中，是b
        return b==0? a:getIndex(b,a%b);
    }
}
```