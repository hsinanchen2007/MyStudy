想象这是一个牌堆：
2
13
3
11
5
17
7
按题目的要求，每次抽一张牌，然后把下面的一张牌放入牌堆底部，那么操作一次之后的结果就是：
抽出的牌：
2
牌堆的牌：
3
11
5
17
7
13
再操作一次的结果就是：
抽取出的牌：
2 3
牌堆的牌：
5
17
7
13
11
不断重复此操作，可以得到最后的结果是：2 3 5 7 11 13 17。
而如果要还原原牌堆，则需要将整个操作过程反过来。
即，先将底部的牌放到顶部，再将抽出的牌里最大的一张放到排堆顶部，重复此过程即可还原牌堆。



```
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        Deque<Integer> deque = new LinkedList<>();
        for (int i = deck.length - 1; i >= 0; i--) {
            if (deque.isEmpty()) { // 当牌堆是空的时候，直接将抽出的牌里最大一张放到排堆顶部
                deque.offerFirst(deck[i]);
            } else { // 当牌堆不为空时，则先将底部的牌放到顶部，再将抽出的牌里最大的一张放到排堆顶部
                deque.offerFirst(deque.pollLast());
                deque.offerFirst(deck[i]);
            }
        }
        int[] result = new int[deck.length];
        int index = 0;
        for (int card : deque) {
            result[index] = card;
            index++;
        }
        return result;
    }
}
```
