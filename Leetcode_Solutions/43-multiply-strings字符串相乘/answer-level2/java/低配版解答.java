### 解题思路
先以二维数组记录每次乘积
然后处理二维数组记录相加结果

### 代码

```java
class Solution {
    public String multiply(String num1, String num2){
        int[][] zj = new int[num2.length()][num1.length() + num2.length()];
        for (int i = num2.length() - 1; i >= 0; i--) {//乘数
            int jinwei = 0;
            for (int j = num1.length() - 1; j >= 0; j--) {//被乘数
                int a = (num2.charAt(i) - 48) * (num1.charAt(j) - 48) + jinwei;
                jinwei = a / 10;
                if (j != 0) {
                    a=a%10;
                }
                zj[num2.length() - i - 1][i + j + 1] = a;
            }
        }
        int[] ints = new int[num1.length() + num2.length()];
        StringBuffer buffer = new StringBuffer();
        for (int i = 0; i < zj.length; i++) {
            for (int j = 0; j < zj[i].length; j++) {
                ints[j] += zj[i][j];
            }
            System.out.println("");
        }

        int jinwei = 0;
        for (int i = ints.length - 1; i >= 0; i--) {
            buffer.insert(0, (ints[i] + jinwei) % 10);
            jinwei = (ints[i] + jinwei) / 10;
        }

        //去零
        while (buffer.charAt(0) == '0') {
            if (buffer.length() == 1) {
                break;
            }
            buffer.deleteCharAt(0);
        }


        return buffer.toString();
    }
}
```