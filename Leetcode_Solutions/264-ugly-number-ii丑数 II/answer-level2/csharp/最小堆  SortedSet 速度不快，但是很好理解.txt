![微信截图_20191223203923.png](https://pic.leetcode-cn.com/769ceb2cda7fb4b2e48aabe12a3b34b19bb506e25c3c41a1acf9bad579d7b7d5-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20191223203923.png)

public class NthUglyNumberSolution
{
    public int NthUglyNumber(int n)
    {
        if (n == 1) return 1;
        SortedSet<long> list = new SortedSet<long>();
        list.Add(1);
        int counter = 1;
        while (counter < n)
        {
            var min = list.Min;
            list.Remove(min);
            list.Add(min * 2);
            list.Add(min * 3);
            list.Add(min * 5);
            counter++;
        }
        return (int)list.Min;
    }
}
```
