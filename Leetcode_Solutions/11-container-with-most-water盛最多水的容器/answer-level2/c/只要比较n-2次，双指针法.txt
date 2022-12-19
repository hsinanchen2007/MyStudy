
1. 构造一个长度为n-1的数组，构造双指针i和j分别为0和n-1，数组第一个元素即为a1,an面积，长为n-1;
2. 先比较a1和an，假设a1较小，则下一轮长为n-2的面积若以a1为边肯定比第一轮面积小，排斥a1为边；
3. 每一轮排除较小的边为下一轮的边；
4. 每一轮面积赋给数组元素，一共n-1个面积；
5. 比较这n-1个元素最大值
```
int min(int x, int y){
    int t = (x < y)?x:y;
    return t;
}

int maxArea(int* height, int heightSize){
    int a[heightSize-1];
    int i = 0;
    int j = heightSize - 1;
    for(int k = 0; k < heightSize -1; k++){
        if(min(height[i], height[j]) == height[i]){
            a[k] = (j - i) * height[i];
            i++;
        }
        else{
            a[k] = (j - i) * height[j];
            j--;
        }
    }
    int max = a[0];
    for(int k = 1; k < heightSize - 1; k++){
        max = (a[k] > max)?a[k]:max;
    }
    return max;
}
```


