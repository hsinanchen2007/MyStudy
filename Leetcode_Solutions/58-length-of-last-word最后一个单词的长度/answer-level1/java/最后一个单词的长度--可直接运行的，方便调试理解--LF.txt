```
package ZJM_58_最后一个单词的长度;

public class Main {
    public static void main(String[] args) {
        String str1 = "Hello World";
        String str2 = "Hello World I am coming";
        String str3 = "Hello";
        String str4 = "a ";
        String str5 = " ";

        Solution solution = new Solution();
        System.out.println(solution.lengthOfLastWord(str1));
        System.out.println(solution.lengthOfLastWord(str2));
        System.out.println(solution.lengthOfLastWord(str3));
        System.out.println(solution.lengthOfLastWord(str4));
        System.out.println(solution.lengthOfLastWord(str5));
    }
}

class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();

        char[] strarray = s.toCharArray();
        int num = -1;               //避免没有空格的情况
        int count = s.length();

        for(int i=0;i<strarray.length;i++){
            if(strarray[i]==' '){
                num = i;
            }
        }

        return count-num-1;
    }
}

/**
 * 本题一开始我没有使用trim()函数，结果在处理特殊情况（如 "a "," "）会遇到不小困难
 * 将问题越想越复杂，使用trim()函数除去尾部空格后，这个问题就很清晰了
 * 首先，记录最后一次空格出现的位置下标，取出字符串的长度，将字符串长度减去空格位置下标再减1得到的就是最后一个单词的长度
 * 此处需要注意没有空格的情况，这种情况下字符串长度就是最后一个单词的长度
 */

```
