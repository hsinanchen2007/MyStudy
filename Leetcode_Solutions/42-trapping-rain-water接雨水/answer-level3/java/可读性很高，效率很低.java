### 解题思路
1. 计算每个柱子可以承载的雨量，然后相加
2. 每个柱子的雨量= 左边和右边最高柱子高度的min值-自身柱子高度。
3. 双指针分别求解左右第一个符合条件的柱子 

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int res = 0;
        for (int i = 0; i < height.length; i++){
            int num = getNum(height,i);
            res += num;
        }
        return res;
    }
    public int getNum (int[] height,int index){
        int value;
        int leftValue = height[index];
        for (int i = index; i>=0;i--){
            leftValue = height[i] > leftValue ? height[i]:leftValue;
        }
        int rightValue = height[index];
        for (int i = index; i< height.length;i++){
            rightValue = height[i] > rightValue ? height[i]:rightValue;
        }
        value = leftValue < rightValue?leftValue:rightValue;
        if (value > height[index]){
            return value - height[index];
        }else
        {
            return 0;
        }
    }
}
```