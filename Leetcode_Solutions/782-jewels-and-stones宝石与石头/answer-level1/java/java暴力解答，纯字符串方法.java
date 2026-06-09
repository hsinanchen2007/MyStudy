
执行用时 :2 ms, 在所有 Java 提交中击败了99.62%的用户内存消耗 :35.1 MB, 在所有 Java 提交中击败了90.53%的用户
暴力解答了，纯粹的字符串方法。

class Solution {

    public int numJewelsInStones(String J, String S) {
        int count = 0;
        for(int i = 0;i < J.length();i++){
            char str =J.charAt(i);
            int index = 0;
            while((index =S.indexOf(str,index))!= -1){
                count++;
                index++;
            }

        }
        return count;
    }
}