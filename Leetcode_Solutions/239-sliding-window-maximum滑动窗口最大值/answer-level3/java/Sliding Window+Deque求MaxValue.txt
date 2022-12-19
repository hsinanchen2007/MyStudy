一、简单运用滑动窗口思路做法
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length == 0) return nums;
        //存储答案的数组
        int[] ans = new int[nums.length - k + 1];
        //i指向即将丢弃的数字，j指向即将加进窗口的数字
        int i = 0,j = k,maxVal = max(nums,i,k);
        

        for(;j < nums.length;j++,i++) {
            ans[i] = maxVal;
            boolean flag = false;
            //要丢去的数字恰好等于最大值(不可能大于)，可能这个数就是唯一的最大值，则需要标记为需要重新寻找最大值 flag = true
            if(nums[i] == maxVal){
                flag = true;
            }
            //新加进来的数字恰好等于或大于最大值，则不必重新找最大值
            if(nums[j] >= maxVal){
                maxVal = nums[j];
                flag = false;
            }
            //需要重新求窗口最大值
            if(flag){
                maxVal = max(nums,i+1,k);
            }
        }
        //最后一种情况未加入数组
        ans[i] = maxVal;

        return ans;
    }

    //求当前窗口的最大值
    int max(int[] nums,int i,int k){
        int maxVal = Integer.MIN_VALUE;
        for(int j = i;j < i + k;j++) {
            maxVal = Math.max(maxVal,nums[j]);
        }
        return maxVal;
    }
}
```


二、添加了Deque用于便捷找出window最大值
```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(nums.length == 0) return nums;
        //存储答案的数组
        int[] ans = new int[nums.length - k + 1];
        //i指向即将丢弃的数字，j指向即将加进窗口的数字
        int i = 0,j = 0;
        //双向队列存储答案
        Deque<Integer> deque = new LinkedList<Integer>();

        for(;j < k;j++){
            init(deque,nums[j]);
        }

        int maxVal = deque.pollLast();

        for(;j < nums.length;j++,i++) {
            ans[i] = maxVal;
            maxVal = option(deque,nums[j],nums[i],maxVal);
        }
        //最后一种情况未加入数组
        ans[i] = maxVal;

        return ans;
    }

    void init(Deque<Integer> deque,int newNum){
        while(deque.peek() != null && deque.peek() < newNum) {
            deque.pollFirst();
        }
        //已经移除所有比newNum小的元素，加入队列
        deque.push(newNum);
    }

    int option(Deque<Integer> deque,int newNum,int oldNum,int ans){
        /**
        * 保证此队列是降序排列。之所以不需要newNum的之前比此元素小原因是：
        * newNum比之前的元素大，满足题意，
        *且newNum存在在window中时间会比之前元素长。
        */
        while(deque.peek() != null && deque.peek() < newNum) {
            deque.poll();
        }
        //已经移除所有比newNum小的元素，加入队列
        deque.push(newNum);

        /** 如果即将移除的元素oldNum就是当前window最大元素。
         * 一、则获取队列中最大元素。
         * 若只是刚好大小相等？ 那么队列中还会存在一个大小相等的数。
         * 因为我们在处理newNum时候，并没有移除与newNum相等的数
         * 二、当新加的元素大于当前窗口ans时，也要更新ans
        */
        if(oldNum == ans || newNum > ans){
            ans = deque.pollLast();
        }

        return ans;
    }
}
```

