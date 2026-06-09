int maxArea(int* height, int heightSize){
    int maxtemp = 0;
    // for(int i=0;i<heightSize;i++){
    //     for(int j=i+1;j<heightSize;j++){
    //         if(height[i]<=height[j]){
    //             int temp = height[i] * (j-i);
    //             if(temp>maxtemp){
    //                 maxtemp= temp;
    //             }
    //         }
    //         else{
    //             int temp = height[j] * (j-i);
    //             if(temp>maxtemp){
    //                 maxtemp= temp;
    //             }
    //         }
    //     }
    // }
    for(int i=0,j=heightSize-1;i<j;){
        if(height[i]<=height[j]){
                int temp = height[i] * (j-i);
                if(temp>maxtemp){
                    maxtemp= temp;
                }
                i++;
            }
            else{
                int temp = height[j] * (j-i);
                if(temp>maxtemp){
                    maxtemp= temp;
                }
                j--;
            }
    }
    return maxtemp;
}