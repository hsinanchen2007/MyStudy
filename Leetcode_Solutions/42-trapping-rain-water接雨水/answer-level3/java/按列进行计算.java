1、当不超过两个的时候直接返回0
2、遍历第二个到倒数第二个，取出每个位置右边最高点，存入数组
3、遍历计算，记录当前的最左至高点，不用存数组，只存一个值就行，遍历的同时就可以直接计算结果了




public int trap(int[] height) {
        int result = 0;
        if (height.length <= 2) {
            return result;
        }
        int maxLeft = 0;
        int maxRight[] = new int[height.length];
        for (int i = height.length - 2; i > 0; i--) {
            maxRight[i] = Math.max(maxRight[i + 1], height[i + 1]);
        }
        for (int i = 1; i < height.length - 1; i++) {
            maxLeft = Math.max(maxLeft, height[i - 1]);
            int min = Math.min(maxLeft, maxRight[i]);
            if (height[i] < min) {
                result += min - height[i];
            }
        }
        return result;
}