### 解题思路
总的来说，就是定义一个数组存放每一位上的数字相乘结果，每次相乘只保留个位数，十位数往前进，在纸上算一算123*456就明白了。

### 代码

```java
class Solution {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0")) return "0";
        StringBuilder s = new StringBuilder();
        int[] res = new int[num1.length()+num2.length()];
        char[] n1 = num1.toCharArray();
        char[] n2 = num2.toCharArray();
        int a, b;
        for (int i=num1.length()-1;i>=0;i--){
            a = n1[i] - '0';
            for (int j=num2.length()-1;j>=0;j--){
                //每一次运算都要加上当前位置已有的结果
                b = (n2[j] - '0') * a + res[i+j+1];
                if(b>9) {
                    //相乘结果超过10的只保留个位数
                    res[i+j+1] = b%10;
                    //十位数往前进 跟已有的数相加
                    res[i+j] += b/10;
                } else {
                    res[i+j+1] = b;
                }
            }
        }
        int index = 0;
        while(res[index]==0) index++;
        for(int i=index,len=res.length;i<len;i++){
            s.append(res[i]);
        }
        return s.toString();
    }
}
```