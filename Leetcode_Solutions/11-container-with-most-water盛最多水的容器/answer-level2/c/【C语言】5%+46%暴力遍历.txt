### 解题思路
1.思路比较简单：暴力法，遍历所有两根线组成的矩形的面积，取最大的。
2.corner condition：
（1）.也没有什么特殊的边界条件；
3.知识点总结：
没有什么特殊的知识点。
4.耗时：17mins，比较满意了，哈~~。主要耗时点：
（1）算法实现时变量没有定义，编译报错修改了一段时间-----实现需要全神贯注，把代码实现完整；
（2）在计算高时，用了hight[j]-hight[i],这不对，应该是取其小者------算法实现需要全神贯注；
![image.png](https://pic.leetcode-cn.com/bb3bb03e0ad90a1b22ad4601ab3071cc289183232c9d2cbc598527a32d61c968-image.png)


### 代码

```c
int maxArea(int* height, int heightSize){
    int i = 0;
    int j = 0;
    int S = 0;
    int max = 0;
    int maxi = 0;
    int maxj = 0;
    for(i = 0; i < heightSize; i++) {
        for(j = i; j < heightSize; j++) {
            S = (height[i] > height[j] ? height[j] : height[i]) * (j - i);
            max = max > S ? max : S;
        }
    }
    //printf("max = %d, maxi = %d, maxj = %d\n",max, maxi, maxj);
    return max;

}
```