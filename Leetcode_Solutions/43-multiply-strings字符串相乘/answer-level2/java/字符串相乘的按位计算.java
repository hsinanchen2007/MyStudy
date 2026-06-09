从低到高的按位运算，结果去除前面的0
```
class Solution {
    public String multiply(String num1, String num2) {
        int[] res = new int[num1.length() + num2.length()];
        int temp = 0;
        for (int i = num1.length() - 1; i >= 0; i--)
            for (int j = num2.length() - 1; j >= 0; j--) {
                temp = (num1.charAt(i) - '0') * (num2.charAt(j) - '0') + res[i + j + 1];
                res[i + j] += temp / 10;
                res[i + j + 1] = temp % 10;
            }
        StringBuilder sb=new StringBuilder();
            int index=0;
         while (index<res.length&&res[index]==0){
             index++;
         }
         for (int i=index;i<res.length;i++)
             sb.append(res[i]);
         return sb.length()==0?"0":sb.toString();
    }
}
```