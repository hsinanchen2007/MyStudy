先找到最高的墙坐标 index，对于 index 左边的所有坐标，只关心当前坐标左边最高的墙即可。右边同理。
```
class Solution {
    public int trap(int[] height) {
        int index = 0;//记录最长墙的坐标
        int result = 0;//结果
        for (int i = 0; i < height.length; i++) {
            if (height[i] > height[index]) {
                index = i;
            }
        }
        int left = 0;
        int right = height.length - 1;
        int max_left = 0;
        int max_right = 0;

        while (left < index) {//最长墙的左边的水滴
            if (max_left > height[left]) {
                result += max_left - height[left];
            } else if (max_left < height[left]) {
                max_left = height[left];
            }
            left++;
        }

        while (right > index) {//最长墙的右边的水滴
            if (max_right > height[right]) {
                result += max_right - height[right];
            } else if (max_right < height[right]) {
                max_right = height[right];
            }
            right--;
        }
        return result;

    }

}
```
