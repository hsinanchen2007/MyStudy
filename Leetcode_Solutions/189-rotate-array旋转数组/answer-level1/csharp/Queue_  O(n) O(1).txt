 public void Rotate(int[] nums, int k) {
         Queue<int> q = new Queue<int>();
            k = k % nums.Length;
            for (int i = 0; i < nums.Length; i++)
            {
                if (i < nums.Length - k)
                    q.Enqueue(nums[i]);
                if (i < k)
                    nums[i] = nums[nums.Length - k + i];
                else
                    nums[i] = q.Dequeue();
            }
    }