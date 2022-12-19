### 解题思路
1. 最大容积只有一个，且一定是有尽可能高的高度与尽可能长的宽度乘积得来。那么只要遍历，其宽度就一直在下降，为了最大程度补偿宽度下降带来的损失，我们就要找最有可能增加高度的选项。至于高度的增加能否补偿到宽度的损失，这不重要，因为我们已经把max记录下来了。
2. 有些情况下不需要判定，比如新来的比原来的高度要低，那么必然不可能产生新的max。

### 代码

```c
/*方法一：莽就完事了*/
// int maxArea(int* height, int heightSize){
//     int i, j;
//     int max = 0;
//     int size = 0;
//     for (i=0; i<heightSize; i++){
//         for (j=i+1; j<heightSize; j++){
//             size = minNum(height[i], height[j])*(j-i);
//             if (size > max){
//                 max = size;
//             }
//         }
//     }
//     return max;

// }

int minNum(int i, int j){
    if (i > j){
        return j;
    }
    else{
        return i;
    }
}
/*方法二：动脑*/
int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize-1;
    int max = minNum(height[left], height[right])*(right-left);
    while (left < right){
        if (height[left] <= height[right]){
            left++;
            if (height[left] > height[left-1]){//只有新来的比原来的高，那么才需要判定面积
                if (minNum(height[left], height[right])*(right-left) > max){
                max = minNum(height[left], height[right])*(right-left);
                }
            }

        }
        else{
            right--;
            if (height[right] > height[right+1]){
                if (minNum(height[left], height[right])*(right-left) > max){
                max = minNum(height[left], height[right])*(right-left);
                }
            }
        }

    }
    return max;
}
```