执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户
内存消耗 :34 MB在所有 java 提交中击败了100.00%的用户
class Solution {
    public int balancedStringSplit(String s) {
        int count1=0,count2=0;
        char[] ch=s.toCharArray();
        for(int i=0;i<s.length();i++){
            if(ch[i]=='L'){
                count1++; //出现L的话，count值加1
            }else{
                count1--;//出现R的值，count的值减1
            }
            if(count1==0){
                count2++;//如果count1的值为0，则说明出现了一个平衡字符串
            }
        }
        return count2;
    }
}