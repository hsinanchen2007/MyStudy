### 暴搜法
需要将所有水桶的容积算出，计算的过程不断更新容积的最大值。

```c
int maxArea(int* height, int heightSize){
    int s = 0, temp;
    for(int i=0;i<=heightSize-2;i++){
        for(int j=i+1;j<=heightSize-1;j++){
            temp = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
            s = (temp > s) ? temp : s;
        }
    }
    return s;
}
```

### 双指针法
定义两个指针（可以是数组下标），初始分别指向高度数组的首和尾。
然后遵循前面的指针往后移，后面的指针往前移的原则。每次只移动一个指针，看哪个指针指向的高度较小，就移动哪个指针，每移动一次就进行一次最大容积的更新。🌟每次都移动指向较小高度的指针的理由：因为较小高度决定了容器的高度，每次移动都是容器宽度变小的过程，只有导致容器高度增加的移动，才是增加容积的移动。如果移动的是指向较大高度的指针，则不会改变容器的高度，只会减少容易的宽度，从而一定会减少容器的容积。

```c
int maxArea(int* height, int heightSize){
    int i = 0, j = heightSize - 1;   // 分别指向数组的首尾元素
    int temp, s = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
    while(j>i){
        if(height[i]<height[j]){
            i++;
            temp = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
            s = (temp > s) ? temp : s;
        }
        else{
            j--;
            temp = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
            s = (temp > s) ? temp : s;
        }
    }
    return s;
}
```