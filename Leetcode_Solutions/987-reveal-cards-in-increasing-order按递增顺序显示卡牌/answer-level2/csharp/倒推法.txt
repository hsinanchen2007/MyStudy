### 解题思路
观察过程规律并使用倒推法
![image.png](https://pic.leetcode-cn.com/567187c4bac658a03837aa5b5c0681bc9080ca8fcb2a94b1a2acf248366e9e22-image.png)
遍历排序后的deck(从大到小)
{
    List在表头插入元素
    List表位的元素移动到表头
}

### 代码

```csharp
public class Solution {
    public int[] DeckRevealedIncreasing(int[] deck) {
        Array.Sort(deck);
        List<int> newDeck = new List<int>();
        for (int i = deck.Length - 1; i >= 0; i--)
        {
            newDeck.Insert(0, deck[i]);
            newDeck.Insert(0, newDeck[newDeck.Count - 1]);
            newDeck.RemoveAt(newDeck.Count - 1);
        }
        newDeck.Add(newDeck[0]);
        newDeck.RemoveAt(0);
        return newDeck.ToArray();
    }
}
```