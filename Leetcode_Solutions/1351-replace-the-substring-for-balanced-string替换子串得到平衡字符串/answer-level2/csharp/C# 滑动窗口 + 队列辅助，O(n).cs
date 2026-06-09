滑动窗口法 + 队列辅助。

队列起到了记录left的作用。使用的时候直接从队列中去取即可！

```c#
public class Solution
{
    public int BalancedString(string s)
    {
        int[] count = new int[256];

        foreach (char c in s)
        {
            count[c]++;
        }

        int n = s.Length / 4;

        Dictionary<char, int> more = new Dictionary<char, int>();
        for (int i = 0; i < 256; ++i)
        {
            if (count[i] > n)
            {
                more.Add((char)i, count[i] - n);
            }
        }

        int res = Int32.MaxValue;

        //用以记录left
        Queue<int> log = new Queue<int>();

        for (int r = 0; r < s.Length; ++r)
        {
            if (more.ContainsKey(s[r]))
            {
                more[s[r]]--;
                log.Enqueue(r);

                bool check = true;
                foreach (var v in more.Values)
                {
                    if (v > 0)
                    {
                        check = false;
                        break;
                    }
                }

                if (check)
                {
                    while (log.Count != 0)
                    {
                        int l = log.Peek();
                        log.Dequeue();

                        res = Math.Min(res, r - l + 1);
                        more[s[l]]++;
                        if (more[s[l]] > 0)
                        {
                            break;
                        }
                    }
                }
            }
        }

        return res == Int32.MaxValue ? 0 : res;
    }
}
```