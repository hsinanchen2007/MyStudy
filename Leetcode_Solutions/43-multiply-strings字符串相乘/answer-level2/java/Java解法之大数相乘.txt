模拟数字相乘的运算过程，时间复杂度为O(M*N) M N分别为两个字符串的长度，空间复杂度是O(M+N)
值得一提的是：data数组是倒着进行赋值的，完全类似于乘法运算
其次，边界条件“0”是容易忽略的。
```
public String multiply(String num1, String num2) {
        if(num1==null || num2 == null) return null;
        if(num1.equals("0") || num2.equals("0")) return "0";
        int len = num1.length()+num2.length(),flag = 0;
        int[] data = new int[len];
        StringBuilder res = new StringBuilder();
        for (int i = num1.length()-1; i >=0 ; i--) {
            for (int j = num2.length()-1; j >=0 ; j--) {
                data[i+j+1] += (num1.charAt(i) -'0')*(num2.charAt(j)-'0');
                if(data[i+j+1]>=10){ 
                    int tmp = data[i+j+1];
                    data[i+j+1] = tmp%10;
                    data[i+j] += tmp/10; 
                }
            }

        }
        int k = 0;
        for (; k < len; k++) {
            if (data[k] != 0) break;
        }
        while(k<len) res.append(data[k++]);
        return res.toString();
    }
```
