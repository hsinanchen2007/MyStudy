```
/**
     * 暴力法
     * 就是找左右柱子的最大值的最小值，即Math.min(L_max,R_max),然后减去自身高度就是能接的雨水
     * 值得注意的是，求左右柱子最大值时需要把自己计算在内！！！
     * @param height
     * @return
     */
    public int trapByViolence(int[] height){
        int res = 0;
        for(int i = 0;i < height.length;i++){
            int L_max = 0;
            int R_max = 0;
            for(int j = i;j >= 0;j--){
                L_max = Math.max(L_max,height[j]);
            }
            for(int j = i;j < height.length;j++){
                R_max = Math.max(R_max,height[j]);
            }
            res = res + Math.min(L_max,R_max) - height[i];
        }
        return res;
    }

    /**
     * dp大法
     * 用空间换时间，把 L_max、R_max 记录下来，就不用重复计算了
     * @param height
     * @return
     */
    public int trapByDp(int[] height){
        int res = 0;
        int len = height.length;
        if(len == 0) return 0;
        int[] L_max = new int[len];
        int[] R_max = new int[len];
        L_max[0] = height[0];
        R_max[len-1] = height[len-1];
        for(int i = 1;i < len;i++){
            L_max[i] = Math.max(L_max[i-1],height[i]);
        }
        for(int i = len - 2;i >= 0;i--){
            R_max[i] = Math.max(R_max[i+1],height[i]);
        }
        for(int i = 0;i < height.length;i++){
            res = res + Math.min(L_max[i],R_max[i]) - height[i];
        }
        return res;
    }

    /**
     * 双指针之固定最高点
     * 先找到最高点，然后左边向最高点靠近，右边也向最高点靠近，左边只需要考虑左边，右边只需要考虑右边
     * @param height
     * @return
     */
    public int trapByDouble(int[] height){
        int res = 0;
        int len = height.length;
        if(len == 0) return 0;
        int max = 0;
        int max_index = -1;
        for(int i = 0;i < len;i++){
            if(height[i] > max){
                max = height[i];
                max_index = i;
            }
        }
        int L_max = height[0];
        for(int i = 0;i < max_index;i++){
            if(height[i] > L_max) L_max = height[i];
            else res = res + L_max - height[i];
        }
        int R_max = height[len-1];
        for(int i = len - 1;i > max_index;i--){
            if(height[i] > R_max) R_max = height[i];
            else res = res + R_max - height[i];
        }
        return res;
    }

    /**
     * 双指针法二
     * 整体思路其实是一样的，只是这个更简便一点而已，无需找最高点，只要确保遍历的数只需要考虑一边即可
     * @param height
     * @return
     */
    public int trapByDouble2(int[] height){
        int res = 0;
        int len = height.length;
        int left = 0;
        int right = len - 1;
        if(len == 0) return 0;
        int L_max = height[0];
        int R_max = height[len-1];
        //一定在最高点相遇，所以无需 left <= right 
        while(left < right){
            L_max = Math.max(L_max, height[left]);
            R_max = Math.max(R_max, height[right]);
            if (L_max < R_max) {
                res = res + L_max - height[left];
                left++;
            }
            else {
                res = res + R_max - height[right];
                right--;
            }
        }
        return res;
    }
```