### 解题思路
这道题主要分两步：
第一步，解决乘法的问题
第二步，解决加法的问题
运算方面主要用的是ASCLL码表

### 代码

```java
class Solution {
    
    public String multiply(String num1, String num2) {
       String ans = "0",temp = "";
       if(num1.equals(ans)||num2.equals(ans)){
           return ans;
       }
       char[] n1 = num1.toCharArray(),n2 = num2.toCharArray();
       int len1 = n1.length,len2 = n2.length;
        //是否进位
        int carry = 0;
       for(int i=len1-1;i>=0;i--){
           //初始化
            temp = "";
            carry = 0;
           for(int j=len2-1;j>=0;j--){
                int result = (n1[i]-48)*(n2[j]-48)+carry;               
                temp = result%10 + temp;
                carry = result/10;
                
           }
           if(carry!=0){
               temp = carry + temp;
           }
           for(int j=len1-1;j>i;j--){
               temp += "0";
           }
           ans = add(temp,ans);
       }
       return ans;
    }

    private String add(String num1, String num2) {
        String ans = "";
        char[] n1 = num1.toCharArray(),n2 = num2.toCharArray();
        int len1 = n1.length,len2 = n2.length;
        //判断是否进位
        int carry = 0;
        while (len1!=0){
            if(len2>0){
                int result = (n1[len1-1]-48)+(n2[len2-1]-48) + carry;
                ans = result%10 + ans;
                carry = result/10;
                len1--;
                len2--;
            }else {
                int result = (n1[len1-1]-48) + carry;
                ans = result%10 + ans;
                carry = result/10;
                len1--;
            }

        }
        if(carry!=0){
            ans = carry + ans;
        }
        return ans;
    }

}
```