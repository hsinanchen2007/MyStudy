//最值之前单调自增，最值之后单调递减
class Solution {
    public int trap(int[] height) {
        if (height.length==0){return 0;}
        int max=0;
        int maxid=0;
        int sum=0;
    for(int i=0;i<height.length;i++){
    if (height[i]>=max){
        max=height[i];
        maxid=i;
    }
    }
    int tepmax=height[0];
    for(int i=0;i<maxid;i++){
       if  (height[i]>tepmax){tepmax=height[i];}
       if  (height[i]<tepmax){sum+=(tepmax-height[i]);}
    }
    tepmax=height[height.length-1];
    for(int i=height.length-1;i>maxid;i--){
       if  (height[i]>tepmax){tepmax=height[i];}
       if  (height[i]<tepmax){sum+=(tepmax-height[i]);}
    }
    return sum;
    }
}