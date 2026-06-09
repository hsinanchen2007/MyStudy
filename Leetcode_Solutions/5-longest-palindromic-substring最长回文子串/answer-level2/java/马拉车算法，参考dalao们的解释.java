### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String prepareString(String s){
        if(s.length() == 0){
            return "^#";
        }
        String res = "^";
        for(int i=0;i<s.length();i++){
            res += "#" + s.charAt(i);
        }
        res += "#$";

        return res;
    }

    public String longestPalindrome(String s) {
        //尝试使用马拉车算法
        String n_s = prepareString(s);
        //需要一个R储存最右回文串的右边界在新字符串中的下标
        int R=0;
        //需要一个C储存最右回文串的中心在新字符串中的下标
        int C=0;
        //需要一个数组储存每个位置回文串的半径（不包括中心）
        int[] p_r = new int[n_s.length()];
        //第一个字符是^，我们手动加的，半径设置为0
        p_r[0]=0;
        p_r[n_s.length()-1] = 0;
        //遍历
        for(int i =1;i<n_s.length()-1;i++){
            //需要一个i_mirro作为位置i相对于中心C的对称点
            int i_mirro = 2*C - i;
            //判断如果p_r[i_mirro]的半径加上i的位置，取小的那个
            if(i>=R){
                p_r[i] = 0;
            }else{
                p_r[i] = Math.min(R-i,p_r[i_mirro]);
            }


            //处理在边界或者在R以外的情况，要更新C和R，用中心扩展法
            while(n_s.charAt(i-p_r[i]-1) == n_s.charAt(i+p_r[i]+1)){
                p_r[i]++;
            }

            //判断是否需要更新R和C
            if(p_r[i] + i > R){
                R = p_r[i] + i;
                C = i;
            }
        }

        //找出最大的
        int max_len=0,current_index=0;
        for(int i =0; i<p_r.length;i++){
            if(p_r[i]>max_len){
                max_len = p_r[i];
                current_index = i;
            }
        }

        return s.substring((current_index - max_len) /2,(current_index - max_len) /2 + max_len);
    }
}
```