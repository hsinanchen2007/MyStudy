## 分析
对于每一根柱子上最后接的雨水。其结果应该是其左右两边高度的最小值，减去本柱子的高度。
    举个例子，柱子高度为[2,1,5]。最后高度为1的柱子上盛放的雨水的高度应该为min(5,20)-1=1。
    因此对于本题，我们只需要将每根柱子左右两边最大值的较小值减去自己，即可得到解。
## 代码
```java
public int trap(int[] height) {

        if(height == null || height.length < 3){
            return 0;
        }
        //left[i]表示第i列左边的最高的列值,包含第i列
        int[] left = new int[height.length];

        left[0] = height[0];

        for (int i = 1; i < height.length ; i++) {
            left[i] = left[i-1] > height[i]?left[i-1] : height[i];
        }
        //right[i]表示第i列右边的最高的列值,包含第i列
        int[] right = new int[height.length];

        right[height.length -1] = height[height.length-1];

        for (int i = height.length-2; i >= 0 ; i--) {
            right[i] = right[i+1] > height[i]?right[i+1] : height[i];
        }
        int sum = 0;
        for (int i = 1; i < height.length-1 ; i++) {
            sum += Math.min(left[i],right[i])-height[i];
        }
        return sum;

    }
```