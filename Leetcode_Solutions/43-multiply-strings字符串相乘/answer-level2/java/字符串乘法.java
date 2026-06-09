# 我的代码
```java []
public String multiply(String num1, String num2) {
    int L1=num1.length(),L2=num2.length();
    int flag=0;
    int tmp,add;
    String res = new String();
    String[] result = new String[L1+L2];
    Arrays.fill(result,"0");
    int i;
    for(i=L2-1;i>=0;i--){
        flag=0;
        for(int j=L1-1;j>=0;j--){
            tmp=(num2.charAt(i)-'0')*(num1.charAt(j)-'0')+flag;
            add=tmp%10;
            if(Integer.valueOf(result[i+j+1])+add>=10){
                result[i+j+1]=String.valueOf(Integer.valueOf(result[i+j+1])+add-10);
                flag=tmp/10+1;
            }
            else{
                result[i+j+1]=String.valueOf(Integer.valueOf(result[i+j+1])+add);
                flag=tmp/10;
            }
            result[i]=String.valueOf(flag);
        }
    }
    for(i=0; i<L1+L2; i++){
        if(Integer.valueOf(result[i])!=0) break;
    }
    for(;i<L1+L2;i++)
        res+=result[i];
    return res;
}
```

# 题解代码
注意学习StringBuilder...
```java []
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int[] res = new int[num1.length() + num2.length()];
        for (int i = num1.length() - 1; i >= 0; i--) {
            int n1 = num1.charAt(i) - '0';
            for (int j = num2.length() - 1; j >= 0; j--) {
                int n2 = num2.charAt(j) - '0';
                int sum = (res[i + j + 1] + n1 * n2);
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < res.length; i++) {
            if (i == 0 && res[i] == 0) continue;
            result.append(res[i]);
        }
        return result.toString();
    }
}

```

