```java
public class 数字的补数 {
    public static void main(String[] args) {
//        System.out.println(1 ^ 1);
//        System.out.println(0 ^ 1);
        System.out.println(findComplement(5));
        System.out.println(findComplement2(5));
    }

    /**
     * 把数字转化为二进制的字符串， 再遍历字符串，取反，最后把改变的字符串转化为数字
     *
     * @param num
     * @return
     */
    public static int findComplement(int num) {
        String bin = Integer.toBinaryString(num);
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < bin.length(); i++) {
            if (bin.charAt(i) == '1') {
                sb.append('0');
            } else {
                sb.append('1');
            }
        }
        return Integer.parseInt(sb.toString(), 2);
    }

    /**
     * 把数字右移位得到二进制形式的每一位进行转化，最后左移位恢复过来
     * @param num
     * @return
     */
    public static int findComplement2(int num) {
        int sum = 0;

        for (int i = 0; num != 0; i++) {
            int j = num & 1;
            sum += (j ^ 1) << i;
            num >>= 1;
        }
        
        return sum;
    }
}

```