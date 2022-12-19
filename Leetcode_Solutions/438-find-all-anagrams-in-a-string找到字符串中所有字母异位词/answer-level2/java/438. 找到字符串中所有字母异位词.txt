/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/11
 *
 * 解题思路1: 暴力 + hash （770ms）
 *
 * 解题思路2: 有一点技巧 + 滑动窗口 + hash  (12ms)
 *              
 *  滑动窗口:窗口右侧向右移动，直到出现满足目标数组异位的情况, 再移动左侧窗口缩小窗口的长度等于目标数组的长度。
 * 
 *  移动的过程中判断是否符合目标数组异位,符合则继续移动知道数组长度等于窗口长度，则匹配成功。不符合则移动右侧窗口，重复以上动作。
 *       
 *  注意：建议参照代码进行手动画图思考一下 见图。
 *
 

![DD8A9A6C508203F5CFC76A0D2E35E8F9.png](https://pic.leetcode-cn.com/823d0c80bb9487d6282eb28b2c2c01155d2cca492104feb8f84fc56c1002b80f-DD8A9A6C508203F5CFC76A0D2E35E8F9.png)
*/

```
public class leetcode438 {
    public List<Integer> findAnagrams(String s, String p) {
        char[] s_arr = s.toCharArray();
        char[] p_arr = p.toCharArray();
        List<Integer> list = new ArrayList<>();

        char[] p_letter = new char[26];
        for(int i = 0; i < p_arr.length;i++){
            p_letter[p_arr[i] - 'a']++;
        }


        for(int i = 0;i < s_arr.length - p_arr.length + 1;i++){
            char[] temp = new char[26];
            //放入hash
            if(p_letter[s_arr[i] - 'a'] == 0) continue;
            for(int j = i; j < i + p_arr.length;j++){
                temp[s_arr[j] - 'a']++;
            }

            //匹配hash
            boolean ok = true;
            for(int j = 0;j < p_arr.length;j++){
                if(temp[p_arr[j] - 'a'] == 0){
                    ok = false;
                    break;
                }else{
                    temp[p_arr[j] - 'a']--;
                }
            }

            //ok 加入list
            if(ok){
                list.add(i);
            }

        }

        return list;
    }

    public List<Integer> findAnagrams2(String s, String p) {
        //转化为char array
        char[] s_arr = s.toCharArray();
        char[] p_arr = p.toCharArray();
        List<Integer> list = new ArrayList<>();

        //定义两个hash数组
        char[] s_letter = new char[26]; // 滑动窗口hash
        char[] p_letter = new char[26]; //目标数组hash
        //hash p数组
        for(int i = 0; i < p_arr.length;i++){
            p_letter[p_arr[i] - 'a']++;
        }

        //滑动窗口
        int left = 0;
        int right = 0;

        //当窗口右边出界 则退出
        while (right < s_arr.length){
            //获取当前最右边的字符的hash值
            int current_char_index = s_arr[right++] - 'a';
            //当前最优字符加入hash
            s_letter[current_char_index]++;

            //当前字符的hash值 大于 目标数组（溢出） 1.当前字符不在目标数组中 2.当前字符有重复数组 左边界右移缩小窗口
            //主要技巧点 可以进行手动验证
            while (p_letter[current_char_index] < s_letter[current_char_index]){
                s_letter[s_arr[left++] - 'a']--;
            }
            //当出现窗口大小等于目标数组的大小的时候 匹配成功+1
            if(right - left == p_arr.length){
                list.add(left);
            }
        }
        return list;
    }

    public static void main(String[] args) {
        leetcode438 leetcode438 = new leetcode438();
        leetcode438.findAnagrams("cbaebabacd","abc");
    }
}

```