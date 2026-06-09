  字符串相乘

思路就是用数组去存两个乘数的每一位，然后按照**竖式乘法**相乘，就是一个**双层循环**。
 123
x456
即计算123x6（3x6, 2x6, 1x6）
     123x5（3x5, 2x5, 1x5）
     123x4（3x4, 2x4, 1x5）
**在每一次计算个位数乘个位数的时候，把乘积累加到对应数位，如果需要进位，则把extra加到更高的一个数位。**
```
class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int[] arr1 = new int[num1.length()];
        int[] arr2 = new int[num2.length()];
        
        // 初始化两个乘数数组
        for (int i=0; i<arr1.length; i++) {   
            arr1[i] = num1.charAt(i)-'0';
        }
        for (int i=0; i<arr2.length; i++) {
            arr2[i] = num2.charAt(i)-'0';
        }

        int maxLen = num1.length() + num2.length() + 1;
        int[] res = new int[maxLen]; // 用来存放相乘的结果，低数位放在前面
        int temp = 0;
        int extra = 0;
        int m = 0;
        
        // 逐位相乘，如果需要进位，则进位
        for (int j=arr2.length-1; j>=0; j--){
            for (int i=arr1.length-1; i>=0; i--) {
                temp = arr1[i]*arr2[j];
                m = (arr1.length-1-i) + (arr2.length-1-j);     // m标记当前数位                
                res[m] += temp;
                while(res[m]>=10) {   // 循环判断进位，累加至不需要进位
                    extra = res[m]/10;
                    res[m] = res[m]%10;
                    m++;
                    res[m] += extra;
                }
            }
        }
  
        // 构造结果字符串
        StringBuffer resString = new StringBuffer("");
        for (int i=m; i>=0; i--) {
            resString.append(Integer.toString(res[i]));
        }
        return resString.toString();
    }
}
```
