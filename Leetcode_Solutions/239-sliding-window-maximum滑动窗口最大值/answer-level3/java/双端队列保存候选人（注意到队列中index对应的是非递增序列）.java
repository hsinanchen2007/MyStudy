用一个双端队列保存可能成为当前窗口最大值的数对应的index。

具体实现方法为：每遍历到数组中的一个值（移动一下滑动窗口），1）把队列中已经变成处于窗口外的元素删去，因为每次只有队头的值可能从在窗口内变为在窗口外，因此每次只要检查队头的index是否还在窗口内就可以了。2）把队列中那些对应着比当前值小的值的index删掉，因为那些数绝对不可能是当前窗口最大值。3）将当前值加入队列，此时，队列中保存的就是所有可能成为当前窗口最大值的数对应的index。我们只要4）在这群数里找到最大数就可以了。但如果单纯通过遍历队列中的值来找比当前值小的值以及找最后的当前窗口最大值，那么时间复杂度就会为O(NK)，不符合线性复杂度要求。

通过分析，会发现队列中index对应的始终是一个非递增的序列，队头index对应的就是当前窗口最大元素。原因如下：采用数据归纳法，假设在遍历到第t个元素后，队列中保存的是非递增序列，此时移动滑动窗口，向队列加入第t+1个元素，很明显，经过之前描述的三步操作后，最后形成的队列仍然对应一个非递增序列。而很明显，在队列中插入数组的第一个index后，队列中保存的就是一个非递增序列（仅含一个元素）。因此，任何时刻，队列中保存的index对应的都是一个非递增序列。（这个其实和插入排序有点像）。

因此，每次删队列中的比当前值小的值时，只要从队尾向前遍历，不断删除队尾元素，直到队尾元素大于等于当前值即可。而每次取当前窗口最大值时，只要取队头元素对应的值就可以了。此时，时间复杂度就变成O(N)了，因为此时我们不用通过遍历队列中所有值来找比当前值小的值，每次我们需要访问的值的数量仅是此次要从队列中删去的值的数量+1，由于我们遍历完整个数组后，最多删去N个元素，因此2）的复杂度变为O（N）。同时，我们仅需访问队头元素就可以得到当前窗口最大值，4）的复杂度也变为O（N）。综上，时间复杂度为O（N）。

代码如下：
```
    class Solution {
        public int[] maxSlidingWindow(int[] nums, int k) {
            int n = nums.length;
            if (n * k == 0) return new int[0];
            if (n < k) {
                int max = nums[0];
                for (int i = 1; i < n; i ++) {
                    if (nums[i] > max) max = nums[i];
                }
                int[] tmp = new int[1];
                tmp[0] = max;
                return tmp;
            }
            int[] result = new int[n - k + 1];
            ArrayDeque<Integer> window = new ArrayDeque<>();//store index of potential windowmaximum
            for (int i = 0; i < n; i++) {
                if (!window.isEmpty() && window.getFirst() <= i - k) {
                    window.pollFirst();}//去除已到窗口外的值
                while (!window.isEmpty() && nums[window.getLast()] < nums[i]) {
                    window.pollLast();}//去除比当前值小的，不可能成为当前窗口最大值的值
                window.add(i);//加入当前值
                if (i >= k-1) {//此时，第一个完整窗口形成
                    result[i - k + 1] = nums[window.getFirst()];}
            }
            return result;
        }
    }
```