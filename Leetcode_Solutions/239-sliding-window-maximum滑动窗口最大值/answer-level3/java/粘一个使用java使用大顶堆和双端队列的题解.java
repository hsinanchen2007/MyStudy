解法一（时间复杂度为O（n*logK））：返回窗口中的的最大值，最大最小值我们可以优先考虑到“优先队列”，优先队列用于流式数据的最大最小值。算法题中，有出现slide window的都是高频考点

使用优先队列维持一个大顶堆，（和703 题 数据流中的第k大元素正好相反（https://blog.csdn.net/qq_38765867/article/details/84146811））。

a.维持一个max heap（删除滑动窗口最左边的元素，加入新的元素）

b.让最大值位于大顶堆

a步骤的维持max head的时间复杂度是logK。

b步骤的时间复杂度是N *O（1），即O(N）。

总体时间复杂度为O（n*logK）。

```
class Solution {
 
    public int[] maxSlidingWindow(int[] nums, int k) {
               if(nums==null || nums.length<0 || k<=0 || k==1)
            return nums;
 
        queue = new PriorityQueue<>(k, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o2 - o1;
            }
        });
        
        int[] max = new int[nums.length - k  + 1];
        for (int i = 0; i < nums.length; i++){
//          如果是第K个数之前和第K个数，就说明优先队列没有满，继续添加
            if(i  <  k - 1){
                queue.add(nums[i]);
            }else if(i == k- 1){
                queue.add(nums[i]);
                max[0] = queue.peek();
            }else {
//              优先队列已满，删除滑动窗口最左边的数[i - k],添加新的数
                queue.remove(nums[i - k]);
                queue.add(nums[i]);
                max[i - k + 1] = queue.peek();
            }
        }
 
 
 
        return max;
 
    }
}
```


解法二（时间复杂度为O(N)）：
使用双端队列。java中的双端队列deque（支持在两端插入和移除元素）。deque是一个接口，实现它的类有ArrayDeque，LinkedBlockingDeque,LinkedList.

这里参考了一位大神的解法（https://segmentfault.com/a/1190000003903509）

我们用双向队列，在遇到新的数的时候，将新的数和双向队列的末尾进行比较，如果末尾的数比新数小，则把末尾的数扔掉，直到该队列的末尾数比新数大或者队列为空的时候才停止。这样，我们可以保证队列里的元素是重头到位的降序。由于队列中只有窗口里的数，就是窗口里的第一大数，第二大数，第三数...。

如何保持队列呢。每当滑动窗口的k已满，想要新进来一个数，就需要把滑动窗口最左边的数移出队列，添加新的数。

我们在添加新的数的时候，就已经移出了一些数，这样队列头部的数不一定是窗口最左边的数。技巧：我们队列中只存储那个数在原数组的下标。这样可以判断该数是否为最滑动窗口的最左边的数。

为什么这个解法的时间复杂度是O(N)呢。因为每个元素在双端队列里有且仅存在过一次。即最多被操作两次，一次是加入该队列的时候，一次是因为后面有更大的数而被移除队列的时候

```
class Solution {
 
    public int[] maxSlidingWindow(int[] nums, int k) {
    
        if(!(nums instanceof int[]) || nums == null || nums.length == 0)//判断传进来的是否为int数组，int数组是否为空，int数组是否没有数据
            return new int[0];
        
        ArrayDeque<Integer> adq = new ArrayDeque<Integer>(k);
        int[] max = new int[nums.length + 1 - k];//获得该nums数组滑动窗口的个数
        for(int i = 0; i < nums.length; i++){
            //每当新数进来，如果发现队列的头部的数的下标是窗口最左边的下标，则移出队列
            if(!adq.isEmpty() && adq.peekFirst() == i - k)
                adq.removeFirst();
            //把队列尾部的数和新数一一比较，比新数小的都移出队列，直到该队列的末尾数比新数大或者队列为空的时候才停止，保证队列是降序的
            while(!adq.isEmpty() && nums[adq.peekLast()] < nums[i])
                adq.removeLast();
            //从尾部加入新的数
            adq.offerLast(i);
            //队列头部就是该窗口最大的数
            if(i >= k -1)//i < k - 1时，滑动窗口才有最大值
                max[i + 1 -k] = nums[adq.peek()];
                
        }
        return max;
        
        
 
    }
}
```

原文链接：https://blog.csdn.net/qq_38765867/article/details/84197314
