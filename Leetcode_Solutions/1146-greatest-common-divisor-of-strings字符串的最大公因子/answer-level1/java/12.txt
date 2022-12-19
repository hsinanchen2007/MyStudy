### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String[] chars1=str1.split("");
        String[] chars2=str2.split("");
        if(!chars1[0].equals(chars2[0]))
        {
            return "";
        }
        // 先寻找最大公约数
        int m=chars1.length;
        int n=chars2.length;
        int x=0;int y=0;
        while(x<(m>n?m:n))
        {
            if(!(m>n?chars1[x]:chars2[x]).equals(n>m?chars1[y%m]:chars2[y%n]))
            {
                return "";
            }
            x++;
            y++;
        }
        while(m%n!=0)
        {
            int temp=n;
            n=m%n;
            m=temp;
        }
        int i=0;
        System.out.print(n);
        String res="";
        while(i<n&&i<n&&chars1[i].equals(chars2[i]))
        {
            res=res+chars1[i];
            i++;
        }
        return res;

    }
}
```