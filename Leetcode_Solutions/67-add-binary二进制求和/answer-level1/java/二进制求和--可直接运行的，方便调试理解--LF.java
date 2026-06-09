```
package ZJM_67_二进制求和;

public class Main {
    public static void main(String[] args) {
        String a1 = "11", b1 = "1";

        String a2 = "1010", b2 = "1011";

        String a3 = "10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101",
                b3 = "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011";

        Solution solution = new Solution();
        System.out.println(solution.addBinary(a1, b1));
        System.out.println(solution.addBinary(a2, b2));
        System.out.println(solution.addBinary(a3, b3));
    }
}

class Solution {
    public String addBinary(String a, String b) {
//        String stra = Integer.valueOf(a,2).toString();
//        String strb = Integer.valueOf(b,2).toString();
//
//        int ia = Integer.parseInt(stra);
//        int ib = Integer.parseInt(strb);
//
//        return Integer.toBinaryString(ia+ib);

        StringBuilder result = new StringBuilder();

        int al = a.length() - 1;                //取得字符串a的长度，编程中从0开始，注意此处若由-1后面是>=0
        int bl = b.length() - 1;                //取得字符串b的长度

        int carry = 0;                          //判断是否要进位

        while (al >= 0 || bl >= 0)              //判断两串二进制字符串是否处理完毕
        {
            int sum = carry;                    //将上一次的进位结果进行积累，并参与运算，这样才能解决最终进位的问题
            if (al >= 0)                        //当字符串a没处理完毕
            {
                sum += (a.charAt(al) - '0');    //由尾向前取每一位，减去'0'得到的就是实际数字（如'1'-'0'得到1，'0'-'0'得到0)
                al--;                           //指针向前移动一位
            }
            if (bl >= 0)                        //当字符串b没处理完毕
            {
                sum += (b.charAt(bl) - '0');    //由尾向前取每一位，减去'0'得到的就是实际数字（如'1'-'0'得到1，'0'-'0'得到0)
                bl--;                           //指针向前移动一位
            }
            result.append(sum % 2);             //相加结果
            carry = sum / 2;                    //进位，如果是1那么carry=0，如果是2则要进位给下面一位+1
        }

        if (carry != 0)                         //都相加完了，还要进位的情况
            result.append(1);

        return result.reverse().toString();     //先反转，再输出，因为我们是从尾向头进行的处理
    }
}

/**
 * 本题我通过Integer.valueOf(str,2).toString();先将二进制字符串转化为十进制字符串
 * 十进制字符串使用Integer.parseInt(str);转化为数字，然后两数相加
 * 将两数相加的结果使用Integer.toBinaryString(int i);得到二进制格式的字符串
 * 但是测试用例中的例子过大，此方法失败
 * 所以只能老老实实的进行二进制相加，二进制相加的难点在于处理进位，进多少位，需要好好考虑下
 * 通过对两串字符串
 */

```
