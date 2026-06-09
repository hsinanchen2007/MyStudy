该方法是通过查看王大伟写的c++贪心算法之后根据自己的理解，让逻辑更清晰，题目中描述是让最大的数变成最大的数减去第二大数的差。
class Solution {
    public int lastStoneWeight(int[] stones) {
         if(stones.length==1)
            return stones[0];
        int first=0;
        int second=0;
        for (int i=0;i<stones.length-1;i++)
        {
            int value1=0;
            int value2=0;
         for (int j=0;j<stones.length;j++){
             if(stones[j]>value1){
                 value1=stones[j];
                 first=j;
             }

         }
         stones[first]=0;
         for (int k=0;k<stones.length;k++){
             if(stones[k]>value2){
                 value2=stones[k];
                 second=k;
             }
         }
         stones[second]=0;
         stones[first]=value1-value2;

        }
        return stones[first];
    }
}