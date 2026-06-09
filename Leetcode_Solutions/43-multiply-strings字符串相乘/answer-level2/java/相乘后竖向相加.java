```java
package com.skjilygao.test;

/**
 * 大数相乘：
 * <br> 1. 每次相乘的结果，将结果先与上一次结果中的商(如果是第一次则为0)相加后再跟10相除，判断商是否等于0，不等于0则需要进位，将商放入临时变量（与下一次结果相加），模放入二维子数组；等于0则无需进位，模放入二维子数组）
 * <br> 2. 每次循环结束后进行高位补0，主要是讲上一次相乘结果，需要进位的补上
 * <br> 3. 所有相乘的结果后得到的二维数组，打印出来就是竖向结果。接下来就是相加
 * <br> 4. 遍历二维数组，从低位开始相加。
 * 参考：https://leetcode-cn.com/problems/multiply-strings/
 * @since 20191125
 * @author skyjilygao
 *
 */
class MultiplyStrings {
    public String multiply(String num1, String num2) {
        if(null == num1 || "0".equals(num2)){
            return num2;
        }
        if(null == num2 || "0".equals(num1)){
            return num1;
        }
        int len1 = num1.length();
        int len2 = num2.length();
        int strs1len = len1 > len2 ? len1 : len2;
        int strs2len = len1 + len2;
        String[][] strs = new String[strs1len][strs2len];

        int strs1Index = 0;
        for(int i1 = len1 - 1; i1 >= 0; i1--){
            String s1 = num1.substring(i1, i1 + 1);
            int n1 = Integer.valueOf(s1);
            String[] strs2 = new String[strs2len];
            int strs2Index = strs2len - 1 - strs1Index;
            int shang = 0;
            for(int i2 = len2 - 1; i2 >= 0; i2--){
                String s2 = num2.substring(i2, i2 + 1);
                int n2 = Integer.valueOf(s2);
                int ji = n1 * n2 + shang;
                shang = ji / 10;
                int mo = ji % 10;
                strs2[strs2Index] = ""+mo;
                strs2Index--;
            }
            // 补0
            for(int bu = strs2Index; bu >=0 ; bu--){
                if(shang != 0){
                    strs2[bu] = ""+shang;
                    shang = 0;
                }else{
                    strs2[bu] = "0";
                }

            }
            System.out.println("strs1Index="+strs1Index+",->>>> "+printArr(strs2));
            strs[strs1Index] = strs2;
            strs1Index++;
        }
       /* 打印内容，验证每次相乘结果是否正确
        int index = 0;
         int len22 = strs2len;
         for(String[] strs2 : strs){
             System.out.println("index="+index+",->>>> "+printArr(strs2));
             index++;
         }*/

        String sumStr = toSum(strs2len, strs);
        return sumStr;
    }

    /**
     * 将二维数组竖向相加。从个位开始
     * @param strs2len
     * @param strs
     * @return
     */
    private String toSum(int strs2len, String[][] strs){
        StringBuffer sb =new StringBuffer();
        int shang = 0;
        for(int i = strs2len - 1; i >= 0; i--){
            int sumVal = 0;
            for(String[] strs2 : strs){
                String valStr = strs2[i];
                Integer val = (null == valStr ) ? 0 : Integer.valueOf(valStr);
                val = val == null ? 0 : val;
                sumVal += val;
            }
            sumVal += shang;
            shang = sumVal / 10;
            sumVal = sumVal % 10;
            sb.insert(0, sumVal);
//            System.out.println("求和。。。==="+sb.toString());
        }
        String sumStr = sb.toString();
        // 如果首位包含0，则需要剔除
        if("0".equals(sumStr.substring(0,1))){
            sumStr = sumStr.substring(1, sumStr.length());
        }
        return sumStr;
    }

    /**
     * 打印数组
     * @param strs
     * @return
     */
    private String printArr(String[] strs){
        StringBuffer sb =new StringBuffer();
        for(String s: strs){
            sb.append(" "+s);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        MultiplyStrings multiplyStrings = new MultiplyStrings();
        String sumStr = multiplyStrings.multiply("156","654");
        System.out.println(sumStr);
    }
}
```
