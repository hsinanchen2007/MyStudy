//视频讲解链接https://www.bilibili.com/video/BV1YV411o7Gr/


```
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if(n == 0)  return nums;
        int[] res = new int[n - k + 1];

        //dq里面存的是数组的index, 不是数组的值
        Deque<Integer> dq = new LinkedList<>();

        for(int i = 0; i < n; i++){
            //Step1: 头: 移除头部, 保证窗口的长度范围
            if(!dq.isEmpty() && dq.getFirst() < (i - k + 1)){
                dq.removeFirst();//poll();
            }
            //Step2: 尾: 移除尾部小于当前值得元素, 原理参考篮球队长模型, 去除不可能的元素
            while(!dq.isEmpty() && nums[i] >= nums[dq.getLast()]){
                dq.removeLast();
            }
            //Step3: 尾部加入, 滑动窗口向右扩充
            dq.addLast(i);
            //Step4: 头, 从头部返回极大值
            if(i >= k - 1){
                res[i - k + 1] = nums[dq.getFirst()];
            }
        }

        return res; 
    }
}
```


//视频讲解链接https://www.bilibili.com/video/BV1YV411o7Gr/