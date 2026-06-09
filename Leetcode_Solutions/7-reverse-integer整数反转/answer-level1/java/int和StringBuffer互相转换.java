### 解题思路
此处撰写解题思路
StringBuffer有个reverse函数，因此可以把int转成StringBuffer，然后逆转后再转换回int。但是第一次编译时出现了java.lang.NumberFormatException。因此要加try-catch
### 代码

```java
class Solution {
    public int reverse(int x) {
        
        if(x<0){
            int temp=Math.abs(x);
            int count=reverseNum(temp);
            return 0-count;
        }
        return reverseNum(x);
        
    }
    public int reverseNum(int x){
        StringBuffer sb=new StringBuffer(x+"");
        int a=0;
        try {
            a = Integer.parseInt(sb.reverse().toString());
        } catch (NumberFormatException e) {
            e.printStackTrace();
        }
        return a;
    }
}
```