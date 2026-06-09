```
    public int[] maxSlidingWindow(int[] nums, int k)
    {
        if (k == 0)
        {
            return new int[0];
        }
//为什么k可以等于0？被题目逼的
        if (k == 1)
        {
            return nums;
        }
        int[] res = new int[nums.length - k + 1];
        int t = 0;
        PriorityQueue<int[]> priorityQueue = new PriorityQueue<>((o1, o2) -> o2[1] - o1[1]);
//一个数组，第一个数字是序号，第二个数字是值
//逆序排列
        for (int i = 0; i < nums.length;i++)
        {
            priorityQueue.offer(new int[]{i,nums[i]});
            if (priorityQueue.size() >= k)
            {
                while (priorityQueue.peek()[0] < i - k + 1)
                {
                    priorityQueue.poll();
//从队列里面取，如果序号不在范围中，再取
                }
                res[t] = priorityQueue.peek()[1];
                t++;
            }

        }
        return res;
    }
```
