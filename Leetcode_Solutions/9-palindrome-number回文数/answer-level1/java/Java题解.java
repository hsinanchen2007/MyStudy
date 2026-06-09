class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int index = 1;
        int tmp = x;
        while(tmp >= 10){
            index = index * 10;
            tmp = tmp /10;
        } 
        int left = 0;
        int right = 0;
        while(index>0){
            left = x/index;
            right = x%10;
            System.out.println(x+ "|" + left + "|" + right + "|"+ index);
            if(left!=right){
                return false;
            }
            x=x%index/10;
            index=index/100;
        }
        return true;
    }
}