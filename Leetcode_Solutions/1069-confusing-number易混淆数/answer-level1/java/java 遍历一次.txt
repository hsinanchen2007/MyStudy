
执行用时 : 0 ms , 在所有 java 提交中击败了100.00% 的用户
内存消耗 : 32.8 MB, 在所有 java 提交中击败了100.00%的用户

遍历一次的过程中同时翻转并检查有效数字
最后检查翻转后是否和原数相同

class Solution {
    public boolean confusingNumber(int n) {
     
        int temp =n;
        int helper =0;
        while(temp>0){
            int k = temp%10;
            if(k== 2 || k ==3 || k == 4 || k==5 || k==7)
                return false;
            else if(k== 0 || k==1 || k==8){
                helper = 10 * helper + k;
            }else if(k==9){
                helper = 10 * helper + 6;
            }else if(k==6){
                helper = 10 * helper + 9;
            }
            
            temp /=10;
        }
        
        if(helper == n)
            return false;
        
        return true;
       
    }
}