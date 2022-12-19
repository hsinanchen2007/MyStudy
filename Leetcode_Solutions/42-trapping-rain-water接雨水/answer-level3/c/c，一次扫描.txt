int trap(int* height, int heightSize){
    int i,j,k,lowest,t;
    int rong = 0;
    i = j = 0;
    while(i < heightSize)
    {
        j = i+1;
        if(j<heightSize)
            if(height[i] <= height[j])//这个判断主要是为了找到一个比较大的左边沿
            {                           //提高连续上升的实例的效率，删了也行。
                i = j;                  //（我猜可以删2333。没有试
                continue;
            }
        k = j+1;
        while(k<heightSize)
        {
            if(height[k] >= height[j])
            {
                j = k;
                if(height[j] >= height[i])//比开始要高，或一样高
                {
                    break;
                }
            }
            k++;
        }
        //统计雨水量
        t = i+1;
        lowest = height[i]<height[j]?height[i]:height[j];
        while(t < j)
        {
            rong += lowest - height[t] ;
            t++;
        }
        i = j;
    }
    return rong;
}