## 重难点题目
* [LeetCode重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)


**【核心思想】**
* 用双向队列存储数组的**下标**

**【数据结构】**
* 双向队列

**【思路】**

* 用双向队列存储数组的**下标**，每一轮进行**移动窗口、维护和输出**的动作
* 每一轮使**最大的数对应的下标**在双向队列的**最左端**，如果双向队列中“左边下标对应的元素”要小于“右边下标对应的元素”，那么就把左边的元素进行清除维护
* 输出双向队列最左端下标对应的元素



**【代码】**
```java
public int[] maxSlidingWindow2(int[] nums, int k) {
    if(nums.length == 0 )
        return nums;
    Deque<Integer> deque=new ArrayDeque<>();
    int[] ans = new int[nums.length-k+1];
    for(int i=0;i<nums.length;i++){
        if(!deque.isEmpty() && deque.peekFirst()<i-(k-1))
            deque.removeFirst();
        while(!deque.isEmpty() && nums[deque.peekLast()]<nums[i])
            deque.removeLast();
        deque.offerLast(i);
        if(i>=k-1){
            ans[i-(k-1)]=nums[deque.peekFirst()];
        }  
    }
    return ans;
}
```
**【关注微信公众号，带你拿大厂offer】**

![logo_gif.gif](https://pic.leetcode-cn.com/f6d7085de4095860835e77030f7fd659dc589c02e9fbc0ed5e125ca913d1b15f-logo_gif.gif)