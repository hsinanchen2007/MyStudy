int trap(int* height, int heightSize){
    if(heightSize<=2) return 0;
    int left=0,right=heightSize-1;
    int leftMax=height[0],rightMax=height[heightSize-1];
    int ans=0;
    while(left<=right){
        if(leftMax<rightMax){
            if(height[left]<leftMax){
                ans+=leftMax-height[left];
            }else{
                leftMax=height[left];
            }
            left++;
        }
        else{
            if(height[right]<rightMax){
                ans+=rightMax-height[right];
            }else{
                rightMax=height[right];
            }
            right--;
        }
    }
    return ans;
}