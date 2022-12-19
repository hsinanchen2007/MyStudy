代码
```
import java.util.*;
class Solution {
    public String nearestPalindromic(String n) {
        int half = n.length()/2;
        String leftHalf = n.substring(0, half);
        //三种情况，左半边不变，左半边减一，左半边加一
        String[] left = new String[3];
        //左边确定了，右边相应也确定了
        String[] right = new String[3];
        //分奇偶
        if(half * 2 == n.length()) {
            left[0] = add(leftHalf, "1");
            left[1] = leftHalf;
            //确保不为负数
            if(compare(leftHalf, "1") < 0) {
                left[2] = "0";
            }else
                left[2] = sub(leftHalf, "1");
            for(int i = 0; i < 3; i++) {
                left[i] = deleteZero(new StringBuilder(left[i]));
            }
            for(int i = 0; i < 3; i++) {
                //只有当左边为1、10、100、1000，变成0，9，99，999；那么左边也全为9
                if(left[i].equals("0") || left[i].length() == half -1) {
                    char[] temp = new char[half];
                    Arrays.fill(temp,'9');
                    right[i] = String.valueOf(temp);
                    //14-》15长度不变
                } else if(left[i].length() == half)
                    right[i] = new StringBuilder(left[i]).reverse().toString();
                //从99-》100
                else if(left[i].length() == half + 1)
                    right[i] = new StringBuilder(left[i].substring(0, left[i].length() - 1)).reverse().toString();
            }
        }else {
            leftHalf = leftHalf + n.charAt(half);
            half++;
            left[0] = add(leftHalf, "1");
            left[1] = leftHalf;
            //确保不为负数
            if(compare(leftHalf, "1") < 0) {
                left[2] = "0";
            }else
                left[2] = sub(leftHalf, "1");
            for(int i = 0; i < 3; i++) {
                left[i] = deleteZero(new StringBuilder(left[i]));
            }
            for(int i = 0; i < 3; i++) {
                //无论左边是99-》100，100-》99还是如何 右边的长度都不变，并且左边的长度>=右边
                right[i] = new StringBuilder(left[i].substring(0, half - 1)).reverse().toString();
            }
        }
        return getString(left, right, n);
    }

    //获得左边的字符串，右边的字符串之后，对其进行处理
    public String getString(String[] left, String[] right, String n) {
        String[] result = new String[3];
        String[] diff = new String[3];
        int index = -1;
        //进行拼接，然后获得跟原来的差值
        for(int i = 0; i < 3; i++) {
            result[i] = left[i] + right[i];
            result[i] = deleteZero(new StringBuilder(result[i]));
            if(compare(result[i], n) >= 0) {
                diff[i] = sub(result[i], n);
            }else
                diff[i] = sub(n, result[i]);
        }
        String temp = "";
        for(int i = 0; i < 3; i++) {
            //不能是原值
            if(compare(result[i], n) != 0) {
                //发现差值变小（相等时，下标越大代表的result数值越小）；
                if(index == -1 || compare(diff[i], temp) <= 0) {
                    temp = diff[i];
                    index = i;
                }
            }
        }
        return result[index];
    }
    //两个字符串相加
    public String add(String a, String b) {
        if(a.length() < b.length()) {
            String temp = a;
            a = b;
            b = temp;
        }
        StringBuilder s = new StringBuilder();
        while(s.length() < a.length() - b.length()) {
            s.append('0');
        }
        StringBuilder result = s.append(b);
        int tag = 0;
        for(int i = result.length() - 1; i >= 0; i--) {
            int num = (a.charAt(i) - '0') + tag + (result.charAt(i) - '0');
            tag = num / 10;
            result.setCharAt(i, (char)('0' + num % 10));
        }
        if(tag != 0) {
            result.insert(0, (char)(tag + '0'));
            tag = 0;
        }
        return result.toString();

    }
    //当a>b，获得a-b
    public String sub(String a, String b) {
        StringBuilder s = new StringBuilder();
        while(s.length() < a.length() - b.length()) {
            s.append('0');
        }
        StringBuilder s1 = new StringBuilder(a);
        StringBuilder s2 = s.append(b);
        int tag = 0;
        for(int i = s1.length() - 1; i >= 0; i--) {
            int num = (s1.charAt(i) - '0') - (s2.charAt(i) - '0') - tag;
            if(num < 0) {
                num += 10;
                tag = 1;
            }else tag = 0;
            s1.setCharAt(i, (char)(num + '0'));
        }
        return deleteZero(s1);
    }

    //比较a,b字符串所代表数值大小
    //a>b,1;a==b,0;a<b,-1;
    public int compare(String a, String b) {
        if(a.length() > b.length()) {
            return 1;
        }else if(a.length() < b.length()) {
            return -1;
        }else {
            for(int i = 0; i < a.length(); i++) {
                if(a.charAt(i) > b.charAt(i)) {
                    return 1;
                }else if(a.charAt(i) < b.charAt(i)) {
                    return -1;
                }
            }
            return 0;
        }
    }

    //去掉前导零
    public String deleteZero(StringBuilder s) {
        int index = -1;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '0') {
                index++;
            }else break;
        }
        s.delete(0, index + 1);
        if(s.length() == 0)
            s.append('0');
        return s.toString();
    }
}
```
