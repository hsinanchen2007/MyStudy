```
class Solution{
    public int numTeams(int[] rating){
        int n=rating.length;
        if(n<=2){
            return 0;   //总共没有3个士兵
        }
        int[] minToMax2=new int[n];     //minToMax2[j]代表,i->j中间有多少数rating[j]小
        int[] maxToMin2=new int[n];     //maxToMin2[j]代表,i->j中间有多少数rating[j]大
        int i,j,result=0;
        for(i=0;i<n;i++){
            minToMax2[i]=0;
            maxToMin2[i]=0;
            for(j=i-1;j>=0;j--){
                if(rating[i]>rating[j]){
                    minToMax2[i]++;     //计算有多少数比rating[i]小
                    result+=minToMax2[j];       //rating[i]>rating[j],rating[j]比minToMax2[j]个下标小于j的数大,所以{rating[k](k<j)<rating[j]<rating[i]}共有minToMax2[j种情况]
                }
                if(rating[i]<rating[j]){
                    maxToMin2[i]++;
                    result+=maxToMin2[j];
                }
            }
        }
        return result;
    }
}
```
