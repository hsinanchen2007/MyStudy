```
package ZJM_38_报数;

public class Main {
    public static void main(String[] args) {
        int num1 = 1;
        int num2 = 4;

        Solution solution = new Solution();
        System.out.println(solution.countAndSay(num1));
        System.out.println(solution.countAndSay(num2));
    }
}

class Solution {
    public String countAndSay(int n) {
        String str = "1";
        for (int i = 2; i <= n; i++) {
            StringBuilder stringBuilder = new StringBuilder();
            //取得要数的数
            char pre = str.charAt(0);
            int count = 1;
            //数 数的个数
            for (int j = 1; j < str.length(); j++) {
                char c = str.charAt(j);
                if (c == pre) {
                    count++;
                } else {
                    stringBuilder.append(count).append(pre);
                    pre = c;
                    count = 1;
                }

            }
            stringBuilder.append(count).append(pre);
            str = stringBuilder.toString();
        }
        return str;
    }
}

/**
 * 本题难点在于理解题目的意思，报数的概念很难理解，结合题意，得到
 * 1.     1	        .1	        （没个数）
 * 2.     11	    .11	        （没个数）
 * 3.     21	    2.1	        （2个1）
 * 4.     1211		1.1 1.2 1.1	（1个1和1个2和1个1）
 * 5.     111221	1.1 1.2 2.1	（1个1和1个2和2个1）
 *
 *
 * 1是1个1
 * 2是2个1
 * 3是1个2和1个1
 * 4是1个1和1个2和1个1
 * 5是1个1和1个2和2个1
 * 所以每一种就是它的上一种的读法，比如说2的上一个是1（读1个1），所以2=11，
 * 3的上一个是2(11)读做（2个1），所以3=21，依此类推
 *
 * 由此，得到原理，可以写出相对应的函数
 */

```
