![截屏2020-04-03上午12.02.59.png](https://pic.leetcode-cn.com/107558084684a1d54e71dfac8abfe5695873b11cb29be95213de18901227365b-%E6%88%AA%E5%B1%8F2020-04-03%E4%B8%8A%E5%8D%8812.02.59.png)

class Solution {
   /**
     * 方法：遍历字符串
     */
    public boolean backspaceCompare(String S, String T) {
        S = formatString(S);
        T = formatString(T);
        if (S.equals(T)) {
            return true;
        }
        return false;
    }

    /**
     * 格式化字符串 （这里主要到技巧是维护一个下标index用于操作StringBuffer到字符）
     * @param s
     */
    private String formatString(String s) {
        StringBuilder builder = new StringBuilder(s);
        int index = 0;
        for (int i = 0; i < s.length(); i++ ){
            index++;
            char c = s.charAt(i);
            if (c == '#'){
                index--;
                builder.deleteCharAt(index);
                if (index >0){
                    index--;
                    builder.deleteCharAt(index);
                }
            }
        }
        return builder.toString();
    }

}

[@guan-fang-2](/u/guan-fang-2/)