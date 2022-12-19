先找到最大数字的下标。然后分别算出从左到最高点和从右到最高点的面积。左右两个部分的计算方式是一样的，因为都是从低点向高点遍历。算面积的时候，要注意更新当前的有效高度。
```
    public int trap(int[] height) {
        int sum = 0;
        int maxHeightIndex = 0;
        for (int i = 0; i < height.length; i++) {
            if(height[i]>= height[maxHeightIndex]){
                maxHeightIndex = i;
            }
        }
        // 正向
        int effectiveHeight = 0;
        for (int i = 0; i < maxHeightIndex; i++) {
            if(height[i] > effectiveHeight){
                effectiveHeight = height[i];
                continue;
            }
            sum += effectiveHeight - height[i];
        }
        // 反向
        effectiveHeight = 0;
        for (int i = height.length - 1; i > maxHeightIndex; i--) {
            if(height[i] > effectiveHeight){
                effectiveHeight = height[i];
                continue;
            }
            sum += effectiveHeight - height[i];
        }
        return sum;
    }
```
