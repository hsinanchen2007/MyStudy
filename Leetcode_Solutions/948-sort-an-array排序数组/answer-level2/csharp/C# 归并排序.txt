```csharp
public class Solution {
    public int[] SortArray(int[] nums) {
        List<Queue<int>> list = new List<Queue<int>>();
        for(int i = 0; i < nums.Length; i++)
        {
            Queue<int> que = new Queue<int>();
            if(i < nums.Length - 1)
            {
                que.Enqueue(Math.Min(nums[i], nums[i + 1]));
                que.Enqueue(Math.Max(nums[i], nums[i + 1]));
                i++;
            }
            else
            {
                que.Enqueue(nums[i]);
            }
            list.Add(que);
        }

        while(list.Count > 1)
        {
            List<Queue<int>> temp = new List<Queue<int>>();
            for(int i = 0; i < list.Count; i++)
            {
                if(i < list.Count - 1)
                {
                    temp.Add(MergeQueue(list[i], list[i + 1]));
                    i++;
                }
                else
                {
                    temp.Add(list[i]);
                }
            }
            list = temp;
        }
        return list[0].ToArray();
    }

    public Queue<int> MergeQueue(Queue<int> q1, Queue<int> q2)
    {
        Queue<int> q = new Queue<int>();
        while(q1.Count > 0 || q2.Count > 0)
        {
            if(q1.Count > 0 && q2.Count > 0)
            {
                int i1 = q1.Peek();
                int i2 = q2.Peek();
                if(i1 > i2)
                {
                    q.Enqueue(q2.Dequeue());
                }
                else 
                {
                    q.Enqueue(q1.Dequeue());
                }
            }
            else if(q1.Count > 0)
            {
                q.Enqueue(q1.Dequeue());
            }
            else if(q2.Count > 0)
            {
                q.Enqueue(q2.Dequeue());
            }
        }
        return q;
    }
}
```