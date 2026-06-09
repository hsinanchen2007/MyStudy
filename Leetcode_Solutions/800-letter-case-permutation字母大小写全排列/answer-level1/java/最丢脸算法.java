// ## 回溯算法 [`看到其它解法崩溃😫`]
// ```
import java.util.*;
public class LeetCode784 {
     /**
     * 字母大小写全排列
     *
     * @param S 长度不超过12。仅由数字和字母组成。
     * @return
     */
    public List<String> letterCasePermutation(String S) {
        List<String> res = new ArrayList<>();
        backtrack(res, S.toCharArray(), 0);

        return  res;
    }

    /**
     * 指定一个字符大小写转化
     *
     * @param soure 字符串
     * @param index 下标值
     */
    public void backtrack(List<String> res, char[] soure, int index) {
        char[] soure_tmp = soure;
        if (index == soure.length) {
            res.add(new String(soure));
            return;
        }
        if (!Character.isDigit(soure[index])) {
            backtrack(res, soure, index + 1);
            if (Character.isUpperCase(soure[index])) {
                //当前字符转化为小写
                soure_tmp[index] = Character.toLowerCase(soure[index]);
                backtrack(res, soure_tmp, index + 1);
            } else {
                //当前字符转化为大写
                soure_tmp[index] = Character.toUpperCase(soure[index]);
                backtrack(res, soure_tmp, index + 1);
            }
        }else{
            backtrack(res, soure_tmp, index + 1);
        }
    }
}

// ```
// ![image.png](https://pic.leetcode-cn.com/616582a54680829b23cdca747e1d766b9c274bb91a49f8b4f97973f353bdcb8c-image.png)


// `大小写字母切换:s[i]^=(1<<5);`

// - 大小写字母相差32,又因为异或重要特性:不进位加法,所以大写字母和(1<<5)异或变成变成小写字母,小写字母和(1<<5)异或变成大写字母。

// ### 优化后
// ```
import java.util.*;
public class LeetCode784 {

    /**
     * 字母大小写全排列
     *
     * @param S 长度不超过12。仅由数字和字母组成。
     * @return
     */
    public List<String> letterCasePermutation(String S) {
        List<String> res = new ArrayList<>();
        backtrack(res, S.toCharArray(), 0);

        return  res;
    }

    /**
     * 指定一个字符大小写转化
     *
     * @param soure 字符串
     * @param index 下标值
     */
    public void backtrack(List<String> res, char[] soure, int index) {
        char[] soure_tmp = soure;
        if (index == soure.length) {
            res.add(new String(soure));
            return;
        }
        backtrack(res, soure, index + 1);
        if(!Character.isDigit(soure[index])){
            soure[index]^=(1<<5);
            backtrack(res, soure, index + 1);
        }

    }
}

// ```

