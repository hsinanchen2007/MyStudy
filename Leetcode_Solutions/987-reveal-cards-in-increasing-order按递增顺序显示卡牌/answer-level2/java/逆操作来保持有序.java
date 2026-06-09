### 解题思路
以题为例
数组 [17,13,11,2,3,5,7]
递增排序后 [2,13,3,11,5,17,7]
[17] -> [13,17] -> [11,17,13] -> [7,13,11,17] -> ...
可以发现上述分别是n个最大元素的递增顺序（n为1到nums.length）
因此每次在数组头部插入新的元素时，将数组尾部的元素插入到数组index为1的位置即可，也就是插入到新插入元素的下一个位置。

### 代码

```java
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        List<Integer> res = new ArrayList<>();
        for (int i = deck.length - 1; i >= 0; i--) {
            res.add(0,deck[i]);
            if (res.size()==1 || res.size()==2)
                ;
            else{
                //将最后一个元素插入到第二个位置
                Integer remove = res.remove(res.size() - 1);
                res.add(1,remove);
            }
        }
        for (int i = 0; i < res.size(); i++) {
            deck[i] = res.get(i);
        }
        return deck;
    }
}
```