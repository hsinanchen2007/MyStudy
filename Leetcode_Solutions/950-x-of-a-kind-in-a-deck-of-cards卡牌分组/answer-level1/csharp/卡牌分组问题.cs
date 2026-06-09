### 解题思路
先统计出每种卡牌出现的次数，存放在Dictionary结构中
若可确保多种出现次数之间的最大公约数大于1，即可返回true

### 代码

```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        Dictionary<int, int> dict = new Dictionary<int, int>();
            for (int i = 0; i < deck.Length; i++)
            {
                if(!dict.ContainsKey(deck[i]))
                {
                    dict.Add(deck[i], 1);
                }
                else
                {
                    dict[deck[i]]++;
                }
            }
            Dictionary<int, int>.ValueCollection dictValues = dict.Values;
            int x = 0;
            for (int i = 0; i < dictValues.Count; i++)
            {
                x = GetGcd(x, dictValues.ElementAt(i));
                if (x == 1) return false;
            }
            return true;
    }

    public int GetGcd(int x,int y)
        {
            return (y == 0) ? x : GetGcd(y, x % y);
        }
}
```