对给出的prices数组，求每个prices[i] - prices[i-1]的值，将结果记录到priceChange数组，那么，题目变为求priceChange数组的最大子数组的和。
求priceChange数组的最大子列可以利用分治思想：
对于一个数组，它的最大子序列必定是以下三种之一：
1.最大子序列在该数组的左半部分
2.最大子序列在该数组的右半部分
3.最大子序列横跨数组中间部分
我们只要求出**3.最大子序列横跨数组中间部分**，其余两步交给递归完成就可以。
```
    public int maxProfit(int[] prices) {
        if(prices.length == 0)
            return 0;
        int[] priceChange = new int[prices.length - 1];
        for(int i=1;i<prices.length;i++){
            priceChange[i - 1] = prices[i] - prices[i - 1];
        }
        return Math.max(findMaxSub(priceChange, 0, priceChange.length - 1), 0);
    }
    private int findMaxSub(int[] priceChange, int left, int right){
        if(left == right)
            return priceChange[left];
        int mid = (left + right) / 2;
        int maxCrossingSub = findMaxCrossingSub(priceChange, left, right, mid, mid + 1);
        int maxLeftSub = findMaxSub(priceChange, left, mid);
        int maxRightSub = findMaxSub(priceChange, mid + 1, right);
        return Math.max(maxCrossingSub, Math.max(maxLeftSub, maxRightSub));
    }
    private int findMaxCrossingSub(int[] priceChange, int leftBound, int rightBound, int leftStart, int rightStart){
        int leftSum = 0, maxLeftSum = Integer.MIN_VALUE;
        for(int i=leftStart;i>=leftBound;i--){
            leftSum += priceChange[i];
            maxLeftSum = Math.max(leftSum, maxLeftSum);
        }
        int rightSum = 0, maxRightSum = Integer.MIN_VALUE;
        for(int i=rightStart;i<=rightBound;i++){
            rightSum += priceChange[i];
            maxRightSum = Math.max(rightSum, maxRightSum);
        }
        return maxLeftSum + maxRightSum;
    }
```
