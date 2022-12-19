    /**
    *找波谷
    *O(n^2)
    *O(1)
    */
    public int trap(int[] height) {
        if(height==null||height.length<3)return 0;
        int len = height.length;
        int sum = 0;
        //从左向右遍历时波谷的左边界 也是最矮边界
        int leftS =0;
        boolean isRecord=false;
        for(int i=1;i<len;i++){
            if(!isRecord&&height[i]<height[i-1]){
                leftS=i-1;
                isRecord=true;
            }
            //此处包含波谷两端一样高的情况
            if(isRecord&&height[i]>=height[leftS]){
                for(int j=leftS;j<i;j++){
                    sum+=height[leftS]-height[j];
                }
                isRecord=false;
            }
        }
        //从右向左遍历时波谷的右边界 也是最矮边界
        int rightS =len-1;
        isRecord=false;
        for(int i=len-2;i>=0;i--){
            if(!isRecord&&height[i]<height[i+1]){
                rightS=i+1;
                isRecord=true;
            }
            //此处排除掉波谷两端一样高的情况
            if(isRecord&&height[i]>height[rightS]){
                for(int j=rightS;j>i;j--){
                    sum+=height[rightS]-height[j];
                }
                isRecord=false;
            }
        }
        return sum;
    }