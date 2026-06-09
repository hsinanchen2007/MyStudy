```
package ZJM_14_最长公共前缀;

public class Main {
    public static void main(String[] args) {
        String[] strary1 = {"flower","flow","flight"};
        String[] strary2 = {"dog","racecar","car"};
        String[] strary3 = {""};
        String[] strary4 = {"a"};
        String[] strary5 = {"c","c"};

        Solution solution = new Solution();
        System.out.println(solution.longestCommonPrefix(strary1));
        System.out.println(solution.longestCommonPrefix(strary2));
        System.out.println(solution.longestCommonPrefix(strary3));
        System.out.println(solution.longestCommonPrefix(strary4));
        System.out.println(solution.longestCommonPrefix(strary5));

    }
}

class Solution {
    public String longestCommonPrefix(String[] strs) {
//        System.out.println(strs.length);
        if(strs.length==0){     //这是对之后strs[0].length();的防错
            return "";
        }
        if(strs.length==1){
            return strs[0];
        }

        int minlong = strs[0].length();
        String temp = "";

        for(int i=1;i<strs.length;i++){
            if(minlong>strs[i].length())
            {
                minlong = strs[i].length();
            }
        }

        for(int i=0;i<minlong;i++){
            temp = strs[0].substring(0,i+1);
//            System.out.println(temp);
            for(int j=0;j<strs.length;j++){
                if(!temp.equals(strs[j].substring(0,i+1))){
                    if(i==0) {
                        return "";
                    }else {
                        return strs[0].substring(0,i);
                    }
                }
            }

        }

        return temp;
    }
}

/**
 * 本题其实思路是挺清晰的，就是实际写起来容易将截取的位与循环的序号搞混，还有题目提交时的特殊情况也需要注意
 * 首先确定字符串数组中最短的字符串，得到它的长度，作为截取的最长位数
 * 先对首位进行截取，如例：{flower","flow","flight"}截取到f赋值给temp，外层循环负责控制截取的公共前缀的长度
 * 里层循环负责比较temp，也就是当前截取的前缀与其他的字符串进行前缀比较，相等继续，不等返回temp，
 * 而如果是第一次就不等的话，应该返回""，而不是已有一个字母的temp
 * 提交题目的特殊情况有如下两种
 * {""},{"a"}
 * 特别注意""的字符串数组长度是1而不是0，null的字符串数组无长度，返回strs[0]即可解决
 */

```
