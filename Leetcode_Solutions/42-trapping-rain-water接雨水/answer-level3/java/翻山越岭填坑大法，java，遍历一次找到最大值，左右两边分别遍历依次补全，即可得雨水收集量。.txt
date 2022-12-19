
![test.png](https://pic.leetcode-cn.com/6610045f1bfa3a095e8b8bed285b20e4d8321217e2a94e337cae6e8a7054c16e-test.png)

假设，最高为A，将整个模型对半切，一半为left-A,一半为A-right。
```
class Solution {
    public int trap(int[] height) {
        int max = 0;
        int maxIndex = 0;
        //寻找A点
        for (int i = 0; i < height.length; i++) {
            if(height[i]>max){
                max = height[i];
                maxIndex =i;
            }
        }
        int maxLeft = 0;
        int result = 0;
        //计算left-A的雨水收集
        for (int i = 0; i < maxIndex; i++) {
            if(height[i]>maxLeft){
                maxLeft = height[i];
            }else {
                result += maxLeft-height[i];
            }
        }
        int maxRight = 0;
        //计算A-left的雨水收集
        for (int i = height.length-1; i > maxIndex ; i--) {
            if(height[i]>maxRight){
                maxRight = height[i];
            }else {
                result += maxRight - height[i];
            }
        }
        return result;
    }
}
```