### 解题思路
执行用时 :112 ms, 在所有 C 提交中击败了12.81%的用户
内存消耗 :6 MB, 在所有 C 提交中击败了100.00%的用户

遍历数组，本位置的蓄水量由左边最高的挡水柱子和右边最高的挡水柱子中最低的那个决定。

### 代码

```c
int trap(int* height, int heightSize){
    int i, j, left_bar=0, right_bar=0, min_bar=0, res=0;
    for(i=0; i<heightSize; i++){
        // 找出右边最高的挡水柱子
        right_bar = 0;
        for(j=i+1; j<heightSize; j++){
            right_bar = height[j]>right_bar?height[j]:right_bar;
        }
        // 当前位置的接水量
        min_bar = left_bar<right_bar?left_bar:right_bar;
        if(min_bar>height[i]){
            res += (min_bar-height[i]);
        }
        // 更新左边挡水柱子高度
        left_bar = height[i]>left_bar?height[i]:left_bar;
    }
    return res;
}


/*
最初版本——超出时间限制

int trap(int* height, int heightSize){
    int i, j, left_bar=0, right_bar=0, res=0;
    for(i=0; i<heightSize; i++){
        // 找出右边最高的挡水柱子
        right_bar = 0;
        for(j=i+1; j<heightSize; j++){
            right_bar = height[j]>right_bar?height[j]:right_bar;
        }
        // 第i位置第j高度的空格子不高于左边的挡水柱子和右边的挡水柱子
        for(j=0; ;j++){
            if(j >= height[i]){
                if(j < left_bar && j < right_bar){
                    res++;
                }else{
                    break;
                }
            }
        }
        // 更新左边挡水柱子高度
        left_bar = height[i]>left_bar?height[i]:left_bar;
    }
    return res;
}
*/

/*
改进版本——我觉得应该更好，但是相比未注释的版本运行时时间反而变差了一点点

int trap(int* height, int heightSize){
    int i, j, left_bar=0, right_bar=0, res=0;
    for(i=0; i<heightSize; i++){
        if(left_bar > height[i]){  // 如果左边挡水柱子能挡住水
            // 找出右边最高的挡水柱子
            right_bar = 0;
            for(j=i+1; j<heightSize; j++){
                right_bar = height[j]>right_bar?height[j]:right_bar;
            }
            if(right_bar > height[i]){  // 如果右边挡水柱子也能挡住水
                res += ((left_bar<right_bar?left_bar:right_bar) - height[i]);
            }
        }
        // 更新左边挡水柱子高度
        left_bar = height[i]>left_bar?height[i]:left_bar;
    }
    return res;
}
*/
```