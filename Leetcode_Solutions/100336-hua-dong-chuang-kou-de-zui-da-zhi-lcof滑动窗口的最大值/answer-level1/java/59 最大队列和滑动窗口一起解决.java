```java
package test;

/*
 * 59. 滑动窗口的最大值
 * Difficult: Easy
 * <p>
 * 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
 * Example:
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7]
 * Explanation:
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * <p>
 * Note:
 * 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。
 * Follow up:
 * Could you solve it in linear time?
 *
 */

/**
 * @see SwardOffer59_II_MaxQueue
 * @see T239_SlidingWindowMaximum
 */
public class SwardOffer59_I_MaxSlidingWindow {

    public static void main(String[] args) {
        SwardOffer59_I_MaxSlidingWindow test = new SwardOffer59_I_MaxSlidingWindow();
        Tools.printArray(test.maxSlidingWindow(new int[]{1, 3, -1, -3, 5, 3, 6, 7}, 3));
    }

    /**
     * 维护一个最大队，保持队列长度为k，每入队出队一次，取一次最大值
     * 执行用时 :19 ms, 40.12%
     * 内存消耗 :48.9 MB, 5.03%
     */
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k <= 1)
            return nums;
        int len = nums.length;
        if (len <= k)
            return new int[]{getMax(nums)};
        int[] ans = new int[len - k + 1];  //返回结果长度可以计算
        int j = 0;
        //定义一个最大队列，使用其性质进行求解
        SwardOffer59_II_MaxQueue queue = new SwardOffer59_II_MaxQueue();
        for (int i = 0; i < len; i++) {
            if (i >= k) {
                ans[j++] = queue.max_value();
                queue.pop_front();
            }
            queue.push_back(nums[i]);
        }
        ans[j] = queue.max_value();  //最后一个元素入队后，未取最大值，需获取
        return ans;
    }

    private int getMax(int[] nums) {
        int max = nums[0];
        for (int n : nums)
            if (max < n)
                max = n;
        return max;
    }
}
```

其中SwardOffer59_II_MaxQueue的定义如下，其是59-MaxQueue的解答。
```java
package test;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 59. MaxQueue
 * Difficult: Medium
 * <p>
 * 请定义一个队列并实现函数 max_value 得到队列里的最大值，
 * 要求函数max_value、push_back 和 pop_front 的时间复杂度都是O(1)。
 * <p>
 * 若队列为空，pop_front 和 max_value 需要返回 -1
 * <p>
 * 输入:
 * ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
 * [[],[1],[2],[],[],[]]
 * 输出: [null,null,null,2,1,2]
 * <p>
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue obj = new MaxQueue();
 * int param_1 = obj.max_value();
 * obj.push_back(value);
 * int param_3 = obj.pop_front();
 */
public class SwardOffer59_II_MaxQueue {

    /**
     * 执行用时 :38 ms, 68.82%
     * 内存消耗 :46.1 MB, 100.00%
     */
    public static void main(String[] args) {
        SwardOffer59_II_MaxQueue queue = new SwardOffer59_II_MaxQueue();
        System.out.println(queue.pop_front());  // -1
        System.out.println(queue.max_value());  // -1
        queue.push_back(1);   //current queue:[1]  current max queue:[1]  max:1
        queue.push_back(3);   //current queue:[1, 3]  current max queue:[3]  max:3
        queue.push_back(6);   //current queue:[1, 3, 6]  current max queue:[6]  max:6
        queue.push_back(5);   //current queue:[1, 3, 6, 5]  current max queue:[6, 5]  max:6
        queue.pop_front();    //current queue:[3, 6, 5]  current max queue:[6, 5]  max:6
        queue.push_back(2);   //current queue:[3, 6, 5, 2]  current max queue:[6, 5, 2]  max:6
        queue.push_back(4);   //current queue:[3, 6, 5, 2, 4]  current max queue:[6, 5, 4]  max:6
        queue.pop_front();    //current queue:[6, 5, 2, 4]  current max queue:[6, 5, 4]  max:6
        queue.pop_front();    //current queue:[5, 2, 4]  current max queue:[5, 4]  max:5
        queue.pop_front();    //current queue:[2, 4]  current max queue:[4]  max:4
        queue.pop_front();    //current queue:[4]  current max queue:[4]  max:4
    }

    // 保存元素
    private Queue<Integer> Q;

    // 双端队列，队头为当前序列最大值
    private Deque<Integer> maxQ;

    public SwardOffer59_II_MaxQueue() {
        Q = new LinkedList<>();
        maxQ = new LinkedList<>();
    }

    public int max_value() {
        return maxQ.size() > 0 ? maxQ.getFirst() : -1;
    }

    public void push_back(int value) {
        Q.add(value);  //队尾插入
        //当最大队列不为空，且队尾元素小于要插入的元素时，移除队尾元素
        //目的是将最大队中，小于当前元素的值全部移除
        while (!maxQ.isEmpty() && maxQ.getLast() < value)
            maxQ.removeLast();
        maxQ.addLast(value);
        printQ();
    }

    public int pop_front() {
        if (Q.size() == 0)
            return -1;
        int v = Q.poll();  //队头取出
        if (v == maxQ.getFirst())
            maxQ.removeFirst();
        printQ();
        return v;
    }

    private void printQ() {
        System.out.print("current queue:" + Q);
        System.out.println("  current max queue:" + maxQ + "  max:" + max_value());
    }
}
```

59-最大队列可以同原站的155. Min Stack一起看，有些相似的解题思路，典型的空间换时间。