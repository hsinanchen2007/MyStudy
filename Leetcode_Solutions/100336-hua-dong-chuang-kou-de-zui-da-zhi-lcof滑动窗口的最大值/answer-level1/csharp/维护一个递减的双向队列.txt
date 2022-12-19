```csharp
public int[] MaxSlidingWindow(int[] nums, int k) 
{
    if (k == 0) return nums;

    int   len         = nums.Length;
    int   maxArrayLen = len - k + 1;
    int[] ans         = new int[maxArrayLen];

    // 存的是数组下标
    LinkedList<int> q = new LinkedList<int>();
    
    for (int i = 0; i < len; i++)
    {
        // 1. 移除超过滑动窗口大小的左端第一个数字
        if (q.Count > 0 && q.First.Value + k <= i)
            q.RemoveFirst();

        // 2. 在将i插入队列之前，从队列尾部删除它们值比nums[i]小的索引。
        while (q.Count > 0 && nums[q.Last.Value] <= nums[i])
            q.RemoveLast();

        q.AddLast(i);

        // 3. 需要滑动窗口的左下标和右下标相差K个数才开始放入结果数组
        // 第一个值总是最大的
        int leftindex = i + 1 - k;
        if (leftindex >= 0)
            ans[leftindex] = nums[q.First.Value];
    }

    return ans;
}
```
