### 解题思路
#### 1.首先明确不用计算的边界条件
```
1.有一个字符串为空或者是空字符串，返回0
2.有一个字符串为一个单独的0时，返回0
```
#### 2.采用竖式的方式进行求解，整个步骤分为3个
1.计算每一个num2的字符和num1的结果字符串
2.对于需要补零的进行补零
3.将算得的所有字符串进行相加，得到了最后的结果

### 代码

```java
class Solution {
    public String multiply(String num1, String num2) {
        if (num1 != null && !num1.equals("") && num2 != null && !num2.equals("")){
            if (!num1.equals("0") && !num2.equals("0")){
                //1.计算num2的每一位和num1的乘积
                StringBuilder[] sbs = new StringBuilder[num2.length()];
                for (int i = 0;i < num2.length();i++){
                    String res = multiplyCharWithString(num1,num2.charAt(i));
                    sbs[i] = new StringBuilder(res.length() + num2.length() - i);
                    sbs[i].append(res);
                    //2.补零
                    for (int k = i;k < num2.length() - 1;k++){
                        sbs[i].append("0");
                    }
                }
                //3.将结果两两相加,返回最终的结果
                String finalRes = sbs[0].toString();
                for (int j = 1;j < sbs.length;j++){
                    finalRes = addTwoString(finalRes,sbs[j].toString());
                }
                return finalRes;
            }else {
                return "0";
            }
        }else {
            return "0";
        }
    }

    private String multiplyCharWithString(String num,char c){
        int[] res = new int[num.length() + 1];
        int in = 0;
        for (int i = num.length() - 1;i >= 0;i--){
            res[i + 1] = (charToInt(num.charAt(i)) * charToInt(c) + in) % 10;
            in = (charToInt(num.charAt(i)) * charToInt(c) + in) / 10;
        }
        if (in > 0){
            res[0] = in;
        }
        StringBuilder sb = new StringBuilder(res.length);
        for (int i = 0;i < res.length;i++){
            if (i == 0){
                if (res[i] != 0) {
                    sb.append(res[i]);
                }
            }else {
                sb.append(res[i]);
            }
        }
        return sb.toString();
    }

    private String addTwoString(String str1,String str2){
        String big = str1.length() > str2.length() ? str1 : str2;
        String small = str1.length() > str2.length() ? str2 : str1;
        int[] res = new int[big.length() + 1];
        int in = 0;
        for (int i = 0;i < big.length();i++){
            if (i < small.length()){
                int addRes = (charToInt(big.charAt(big.length() - 1 - i)) + charToInt(small.charAt(small.length() - 1 - i))) + in;
                res[big.length() - i] = addRes % 10;
                in = addRes / 10;
            }else {
                int addRes = charToInt(big.charAt(big.length() - 1 - i)) + in;
                res[big.length() - i] = addRes % 10;
                in = addRes / 10;
            }
        }
        if (in > 0){
            res[0] = in;
        }
        StringBuilder sb = new StringBuilder(res.length);
        for (int i = 0;i < res.length;i++){
            if (i == 0){
                if (res[i] != 0) {
                    sb.append(res[i]);
                }
            }else {
                sb.append(res[i]);
            }
        }
        return sb.toString();
    }

    private int charToInt(char a){
        return a - 48;
    }
}
```