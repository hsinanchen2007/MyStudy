### 代码

```csharp
public class Solution {
    public int OpenLock(string[] deadends, string target)
    {
        HashSet<string> deadSet = new HashSet<string>(deadends);
        if (deadSet.Contains("0000"))
            return -1;
        
        if (target == "0000")
            return 0;
        
        HashSet<string> set = new HashSet<string>();

        Queue<string> queue = new Queue<string>();
        queue.Enqueue("0000");
        set.Add("0000");
        int step = 0;

        while (queue.Count != 0)
        {
            step++;
            int len = queue.Count;
            for (int j = 0; j < len; j++)
            {
                char[] current = queue.Dequeue().ToCharArray();
                for (int i = 0; i < 8; i++)
                {
                    char c = current[i / 2];
                    current[i / 2] = char.Parse(((10 + (c - '0') + (i % 2 == 0 ? 1 : -1)) % 10).ToString());
                    string neighbor = new string(current);
                    current[i / 2] = c;

                    if (neighbor == target)
                        return step;

                    if (!deadSet.Contains(neighbor) && set.Add(neighbor))
                        queue.Enqueue(neighbor);
                }
            }
        }
        return -1;
    }
}
```