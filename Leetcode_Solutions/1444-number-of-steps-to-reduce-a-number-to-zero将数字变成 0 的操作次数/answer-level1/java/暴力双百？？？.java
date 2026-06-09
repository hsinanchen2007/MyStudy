public class Solution {
    //估计做的人太少了
    public int numberOfSteps (int num) {
        int i=0;
        while(num!=0){
            if(num%2!=0){
                num-=1;
            }else{
                num/=2;
            }
            i++;
        }
        return i;
    }
}