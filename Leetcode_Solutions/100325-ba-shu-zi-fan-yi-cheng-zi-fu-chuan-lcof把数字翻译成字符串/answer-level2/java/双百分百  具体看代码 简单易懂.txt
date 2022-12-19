### 解题思路
双百分百  具体看代码 简单易懂
![image.png](https://pic.leetcode-cn.com/af0de75f027191b969331c629e3405033b9f2160e0dbd968bfbc22f554f9aa2d-image.png)

### 代码

```java
class Solution {
    private int count=0;
    public int translateNum(int num) {
        String s=String.valueOf(num);
        helper(s);
        return count;
    }
    public void helper(String s){
        if(s.length()==0){
            count++;
            return ;
        }
        int num1=-1;
        if(s.length()>0){
            num1=Integer.valueOf(s.substring(0,1)).intValue();   
        }
        int num2=-1;
        if(s.length()>1&&s.charAt(0)!='0'){
            num2=Integer.valueOf(s.substring(0,2)).intValue();
            // return ;
        }
        // int num2=Integer.valueOf(s.substring(0,2)).intValue();
        if(num1>=0&&num1<=25){
            helper(s.substring(1));
        }
        
        if(num2>=0&&num2<=25){
            helper(s.substring(2));
        }
    }
}
```