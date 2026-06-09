### 解题思路
用两个数来记录两头的下标，用两头最短的数来作为高乘以下标的差得到目前容量。然后将最小的一端的下标向中间移动寻求最大的值。最终遍历一遍所有可能是最大容量的值记录下来。

### 代码

```c
int maxArea(int* height, int heightSize){
    int maxcontain = 0;
    if(heightSize==0) return 0;
    int i=0;
    int per=0,he = heightSize-1;
    while(per!=he)
    {
        int min = 0;
        if(height[per]>height[he]){
            min = height[he];
            int temp_count = (he-per)*min;
            if(temp_count > maxcontain)
            {
                maxcontain=temp_count;
            }
            he--;
        }
        else{

            min = height[per];
            int temp_count = (he-per)*min;
            if(temp_count > maxcontain)
            {
                maxcontain=temp_count;
            }
            per++;
        }
        
    }
    return maxcontain;
}
```