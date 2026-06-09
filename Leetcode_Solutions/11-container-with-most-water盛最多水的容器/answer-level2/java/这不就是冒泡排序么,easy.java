class Solution {
    public int maxArea(int[] height) {
        int size = 0;
        for(int i=0;i<height.length-1;i++){
            int v1 = height[i];
            for(int j=i+1;j<height.length;j++){
                int v2 = height[j];
                int cs = Math.min(v1,v2)*(j-i);
                size = Math.max(cs,size);
            }
        }
        return size;
    }
}