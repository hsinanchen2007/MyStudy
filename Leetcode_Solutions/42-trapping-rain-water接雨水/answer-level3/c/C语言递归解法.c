### 解题思路
此处撰写解题思路
先找到最高点，然后分别找到最高点左边和右边的次高点，计算出面积后继续递归的向左右两个方向找
### 代码

```c
int trap(int* height, int heightSize){
    int indexMax = -1;
    int max = 0;
    int secLeft = 0;
    int indexSecLeft = -1;
    int secRight = 0;
    int indexSecRight = -1;
    int area = 0;

    if(height == NULL || heightSize <= 2)
        return 0;
    
    /*计算当前最高的点和索引*/
    for(int i = 0;i < heightSize;i++) {
        if(max < height[i]) {
            max = height[i];
            indexMax = i;
            printf("max = %d, indexMax = %d\n",max , indexMax);
        }
    }
    /*计算当前左边最高的点和索引*/
    for(int i = 0;i < indexMax;i++) {
        if(secLeft < height[i]) {
            secLeft = height[i];
            indexSecLeft = i;
            printf("secLeft = %d, indexSecLeft = %d\n",secLeft , indexSecLeft);
        }
    }
    /*计算当前右边最高的点和索引*/
    for(int i = indexMax + 1;i < heightSize;i++) {
        if(secRight < height[i]) {
            secRight = height[i];
            indexSecRight = i;
            printf("secRight = %d, indexSecRight = %d\n",secRight , indexSecRight);
        }
    }
    printf("0area = %d\n",area);
    /*计算左边最高点和右边最高点之间形成的面积*/
    if(indexSecLeft != -1) {
        for(int i = indexSecLeft;i < indexMax;i++)
            area += secLeft - height[i];
        printf("xxxarea = %d\n",area);
    }
    
    if(indexSecRight != -1) {
        for(int i = indexMax + 1;i < indexSecRight;i++) {
            printf("1area = %d\n",area);
            area += secRight - height[i];
            printf("secRight = %d, height[i] = %d,area = %d\n",secRight,height[i],area);
        }
        printf("area = %d\n",area);
    }
    

    /*递归*/
    if(indexSecLeft == -1 && indexSecRight == -1)
        return area;
    else if(indexSecLeft == -1 && indexSecRight != -1)
        return area + trap(height  + indexSecRight,heightSize - indexSecRight);
    else if (indexSecRight == -1 && indexSecLeft != -1)
        return area + trap(height, indexSecLeft + 1);
    else
        return area + trap(height, indexSecLeft + 1) + trap(height
            + indexSecRight,heightSize - indexSecRight);
}
```