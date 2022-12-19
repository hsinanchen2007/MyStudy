```
class Solution {
    public int maxSumDivThree(int[] nums) {
        //累计所有的值 找到最小的且多出来的一部分
        //差 1 两个2 或者一个 1
        //差 2 两个1 或者一个 2
        //可能存在 凑不齐两个 迭代后直接返回
        int res=0,yy=0;
        int temp=0,cur=0;
        for(Integer i:nums){
            res+=i;
        }
        if(res%3==0){
            return res;
        }else{
            int x=res%3;
            int j=x==1?2:1;
            Arrays.sort(nums);
            for(Integer i:nums){
                if(i%3==x && yy==0 ){
                   yy=i;
                }
                if(i%3==j  && cur!=2){
                    cur++;
                    temp+=i;
                }
            }
            if(temp<yy && yy!=0 && cur==2){
                         return res-temp;
            }else if(yy!=0){
                        return res-yy;
            }      
        }
    return 0;
    }
}
```
