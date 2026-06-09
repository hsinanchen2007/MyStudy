### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public bool HasGroupsSizeX(int[] deck) {
        if (deck.Length == 0)
        {
            return false;
        }
        
        bool result = false;
        
        Dictionary<int,int> _dicCount = new Dictionary<int, int>();
        for(int i = 0; i < deck.Length; i++)
        {
            var cur = deck[i];
            if(_dicCount.ContainsKey(cur))
            {
                _dicCount[cur]++;
            }
            else
            {
                _dicCount.Add(cur,1);
            }
        }
        
        var counts = _dicCount.Values.ToList();
        for(int i = 2; i <= deck.Length; i++)
        {
            if(deck.Length % i != 0)
                continue;
                
            result = !counts.Any(item => item % i != 0);
            if(result)
                break;
        }
        
        return result;
    }
}

```