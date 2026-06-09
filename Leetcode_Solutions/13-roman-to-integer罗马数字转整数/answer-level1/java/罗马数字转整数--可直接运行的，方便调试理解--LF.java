```
package ZJM_13_罗马数字转整数;

public class Main {
    public static void main(String[] args) {
        String str1 = "III";
        String str2 = "IV";
        String str3 = "IX";
        String str4 = "LVIII";
        String str5 = "MCMXCIV";

        Solution solution = new Solution();
        System.out.println(solution.romanToInt(str1));
        System.out.println(solution.romanToInt(str2));
        System.out.println(solution.romanToInt(str3));
        System.out.println(solution.romanToInt(str4));
        System.out.println(solution.romanToInt(str5));
    }
}

class Solution {
    public int romanToInt(String s) {
//        I             1
//        V             5
//        X             10
//        L             50
//        C             100
//        D             500
//        M             1000
        int l = s.length();
        char[] temp = s.toCharArray();
        int tempnum = 0;

        for(int i=0;i<temp.length;i++){
//            System.out.println(temp[i]);

//            I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
//            X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
//            C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
            switch (temp[i]){
                case 'I':
                    if(i+1<temp.length) {
                        if (temp[i + 1] == 'V' || temp[i + 1] == 'X') {
                            tempnum -= 1;
                        } else {
                            tempnum += 1;
                        }
                    }else {
                        tempnum += 1;
                    }
                    break;

                case 'V':tempnum+=5;
                    break;

                case 'X':
                    if(i+1<temp.length) {
                        if (temp[i + 1] == 'L' || temp[i + 1] == 'C') {
                            tempnum -= 10;
                        } else {
                            tempnum += 10;
                        }
                    }else {
                        tempnum += 10;
                    }
                    break;

                case 'L':tempnum+=50;
                    break;

                case 'C':
                    if(i+1<temp.length) {
                        if (temp[i + 1] == 'D' || temp[i + 1] == 'M') {
                            tempnum -= 100;
                        } else {
                            tempnum += 100;
                        }
                    }else {
                        tempnum += 100;
                    }
                    break;

                case 'D':tempnum+=500;
                    break;

                case 'M':tempnum+=1000;
                    break;
            }
        }

        return tempnum;
    }
}

/**
 * 根据相对应的每个数进行相对应的转换求和，需要注意的是题目提示的三种特殊情况
 *             I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 *             X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 *             C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 这三种情况要做对应的判断，值得注意的是，Java对于数组下标是严格不能越界的，需要先做一次判断
 * 通过对特殊情况的把控，得到的结果就不会有失误了
 */

```
