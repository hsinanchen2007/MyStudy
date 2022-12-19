
用int[10000]最快

![无标题.jpg](https://pic.leetcode-cn.com/ecc418030baf5b28e347086907d49d05614272eb44f0a28b60a8ea2e5f05bbb1-%E6%97%A0%E6%A0%87%E9%A2%98.jpg)


```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        if(deck.Length < 2)
        {
            return false;
        }
        if(deck.Length == 2)
        {
            return deck[0] == deck[1];
        }
        int[] coutList = new int[10000];
        foreach(int i in deck)
        {
            coutList[i]++;
        }
        int x = -1;
        foreach(int i in coutList)
        {
            if(i > 0)
            {
                if(x == -1)
                {
                    x = i;
                }
                else
                {
                    x = GetValue(x, i);
                    if(x == 1) return false;
                }
            }
        }
        return true;
    }

    public int GetValue(int a, int b)
    {
        if(a == b) return a;
        int max = Math.Max(a, b);
        int min = Math.Min(a, b);
        while(max % min != 0)
        {
            int x = min;
            int y = max % min;
            max = Math.Max(x, y);
            min = Math.Min(x, y);
        }
        return min;
    }
}
```

其实Linq很方便，但做算法时尽量不用
```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        if(deck.Length < 2)
        {
            return false;
        }
        if(deck.Length == 2)
        {
            return deck[0] == deck[1];
        }
        int[] coutList = 
            deck.GroupBy(a => a).Select(b => b.Count()).Distinct().ToArray();
        int x = coutList[0];
        for(int j = 1; j < coutList.Length; j++)
        {
            x = GetValue(x, coutList[j]);
            if(x == 1) return false;
        }
        return true;
    }

    public int GetValue(int a, int b)
    {
        if(a == b) return a;
        int max = Math.Max(a, b);
        int min = Math.Min(a, b);
        while(max % min != 0)
        {
            int x = min;
            int y = max % min;
            max = Math.Max(x, y);
            min = Math.Min(x, y);
        }
        return min;
    }
}
```