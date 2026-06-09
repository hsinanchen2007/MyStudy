```
package ZJM_28_实现strStr函数;

public class Main {
    public static void main(String[] args) {
        String haystack1 = "hello", needle1 = "ll";
        String haystack2 = "aaaaa", needle2 = "bba";
        String haystack3 = "aa", needle3 = "";
        String haystack4 = "aaa", needle4 = "aa";
        String haystack5 = "aaabb", needle5 = "baba";
        String haystack6 = "a", needle6 = "a";
        String haystack7 = "mississippi", needle7 = "issip";

        Solution solution = new Solution();
        System.out.println(solution.strStr(haystack1,needle1));     //2
        System.out.println(solution.strStr(haystack2,needle2));     //-1
        System.out.println(solution.strStr(haystack3,needle3));     //0
        System.out.println(solution.strStr(haystack4,needle4));     //0
        System.out.println(solution.strStr(haystack5,needle5));     //-1
        System.out.println(solution.strStr(haystack6,needle6));     //0
        System.out.println(solution.strStr(haystack7,needle7));     //4
    }
}

class Solution {
    public int strStr(String haystack, String needle) {
        if(needle.equals("")){
            return 0;
        }

        char[] haystackarray = haystack.toCharArray();
        char[] needlearray = needle.toCharArray();

        for(int i=0;i<haystackarray.length-needlearray.length+1;i++){
            if(haystackarray[i]==needlearray[0]){
                int j=1;
                for(;j<needlearray.length;j++){
                    if(haystackarray[i+j]!=needlearray[j]){
                        break;
                    }
                }
                if(j==needlearray.length){
                    return i;
                }
            }
        }

        return -1;
    }
}

/**
 * awsl，本题我使用造轮子写法，通过对字符串的暴力匹配得到答案，
 * 首先，将haystack和needle转化为字符串数组，然后匹配首字母，首字母匹配成功，就继续匹配接下来的字符，
 * 如果成功就继续，不成功就break，比较，如果循环结束的j值等于needle的长度，说明匹配成功，返回i的值，
 * 注意，如果haystack剩下未匹配的长度小于needle的长度，就不用继续匹配了，因为不可能会有匹配的了，也防止数组下标越界
 */

```
