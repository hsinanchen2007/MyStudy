多使用了一个队列，两个数组一起遍历，谁小放谁进queue。最后dequeue，赋值给nums1.

实现也许不够nice，但也提供一种思路。队列本身也是一种数组嘛。。

```
/*
 * @lc app=leetcode.cn id=88 lang=csharp
 *
 * [88] 合并两个有序数组
 */
public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        if(nums1 == null)
        {
            if(nums2 == null)
            {
                return;
            }

            for(int a = 0; a < n; a++)
            {
                nums1[a] = nums2[a];
            }
            return;
        }

        if(nums2 == null)
        {
            return;
        }

        if(m == 0 && n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                nums1[i] = nums2[i];
            }
            return;
        }
        if(m > 0 && n == 0)
        {
            return;
        }

        var queue = new Queue<int>();
        int p1 = 0;
        int p2 = 0;

        while(p1 <m && p2 < n)
        {
            if(nums1[p1] <= nums2[p2])
            {
                queue.Enqueue(nums1[p1]);
                p1++;
            }
            else
            {
                queue.Enqueue(nums2[p2]);
                p2++;
            }
        }

        if(p1 < m)
        {
            for(int k1 = p1; k1 < m; k1++)
            {
                queue.Enqueue(nums1[k1]);
            }
        }
        if(p2 < n)
        {
            for(int k2 = p2; k2 < n; k2++)
            {
                queue.Enqueue(nums2[k2]);
            }
        }

        int count = 0;
        while(queue.Count > 0)
        {
            nums1[count++] = queue.Dequeue();
        }
    }
}


```


