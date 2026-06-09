### 解题思路
递归，时间复杂度$O(n\log n)$，空间复杂度$O(\log n)$

### 代码

```c
int maxindex(int* height, int left, int right){
    int i, maxi, max = -1;
    for(i = left;i < right;i ++)
        if(height[i] > max){
            max = height[i];
            maxi = i;
        }
    return maxi;
}

int traprain(int* height, int left, int right){
    if(right - left < 2)
        return 0;
    if(height[left] <= height[right]){
        int i, maxi, rain = 0;
        maxi = (height[left] == height[right] ? left : maxindex(height, left, right));
        for(i = maxi + 1;i < right;rain += height[maxi] - height[i ++]);
        return rain + traprain(height, left, maxi);
    }
    else{
        int i, maxi = maxindex(height, left + 1, right + 1), rain = 0;
        for(i = left + 1;i < maxi;rain += height[maxi] - height[i ++]);
        return rain + traprain(height, maxi, right);
    }
}

int trap(int* height, int heightSize){
    if(heightSize == 0)
        return 0;
    int maxi = maxindex(height, 0, heightSize);
    return traprain(height, 0, maxi) + traprain(height, maxi, heightSize - 1);
}
```