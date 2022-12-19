### 解题思路
    学会一个新的 StringBuilder的用法

### 代码

```java
class Solution {
    public String defangIPaddr(String address) {
    //Java包中的replace函数没有暴力解法效率高
        StringBuilder s=new StringBuilder();
        for(int i=0;i<address.length();i++)  
        {
            if(address.charAt(i)=='.')
            {
                s.append("[.]");
                continue;
            }
            s.append(address.charAt(i));
        }
        return s.toString();
    }
}
```