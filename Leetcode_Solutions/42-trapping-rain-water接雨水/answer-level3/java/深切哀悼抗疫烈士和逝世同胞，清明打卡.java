当前位置的柱子高cur
左边最高的柱子为L_Max
右边最高的柱子为R_Max
当Min(L_Max,R_max)>cur时，该位置积累的雨水量为Min(L_Max,R_max)-cur;

如果每次都求左边右边的最大值的话会超时，所以想办法保存之前求过柱子的最大值，如果变动了就更新一下
```
public static int trap(int[] height) {
    if (height.length == 0 || height.length == 1){
        return 0;
    }
    int L_Max,R_Max,cur,res=0;
    int[] dp = new int[height.length];
    LinkedList<Integer> leftList = new LinkedList<Integer>();
    LinkedList<Integer> rightList = new LinkedList<Integer>();
    leftList.add(height[0]);
    L_Max = height[0];
    for (int i = 1; i < height.length; i++) {
        rightList.add(height[i]);
    }
    R_Max = Collections.max(rightList);
    dp[0] = 0;
    dp[dp.length-1] = 0;
    for (int i = 1; i < dp.length-1; i++) {
        cur = rightList.poll();
        if (cur == R_Max){
            R_Max = Collections.max(rightList);
        }
        if (Math.min(L_Max,R_Max)-cur > 0){
            dp[i] = Math.min(L_Max,R_Max)-cur;
        }else dp[i] = 0;
        leftList.add(cur);
        if (cur > L_Max){
            L_Max = cur;
        }
        res += dp[i];
    }
    return res;
}
```
