1. 从两头开始。两边的高度肯定会被计算在内的，他是防止水溢出的边界。
2. 找出两头最小的，然后往中间找。找到比边上的更大或者相等，则选为新的两边。
3. 以上就能找出所有的水位。并且在过程中累积计算容量

![image.png](https://pic.leetcode-cn.com/6a58cd43adf0d8bebfe75d5f9b5d21309f00b3284ff7eef8047433a715036d04-image.png)


```
class Solution {
        public int trap(int[] height) {
            if (height.length < 2){
                return 0;
            }
            int result = 0;
            int i = 0;
            int j = height.length - 1;
            while (i < j){
                if (height[i] < height[j]){
                    int temp = i;
                    i++;
                    while (height[temp] > height[i]){
                        result += height[temp];
                        result -= height[i];
                        i++;
                    }
                    if (temp - i > 1){
                        result -= height[temp];
                    }
                }else {
                    int temp = j;
                    j --;
                    while (height[temp] > height[j]){
                        result += height[temp];
                        result -= height[j];
                        j --;
                    }
                    if (j - temp > 1){
                        result -= height[temp];
                    }
                }
            }
            return result;
        }
    }
```
