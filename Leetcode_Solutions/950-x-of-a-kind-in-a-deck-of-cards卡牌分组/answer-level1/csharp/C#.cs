### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for (int i = 0; i < deck.Length; i++)
        {
            if (!dic.ContainsKey(deck[i]))
            {
                dic.Add(deck[i], 1);
            }
            else
            {
                dic[deck[i]]++;
            }
        }
        int tag = -1;
        foreach (int value in dic.Values)
        {
            if(tag == -1)
            {
                tag = value;
            }
            else
            {
                tag = get(tag, value);
            }
        }
        return tag >= 2 ? true : false;
    }
    public int get(int x,int y)
    {
        return x % y == 0 ? y : get(y, x % y);
    }
}

```