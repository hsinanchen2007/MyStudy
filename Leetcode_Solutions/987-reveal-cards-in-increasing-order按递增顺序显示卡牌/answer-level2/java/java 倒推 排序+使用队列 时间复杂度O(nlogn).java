### 解题思路
该题目表达的过程是一个A(A操作代表出一个元素)B(B操作代表放一个元素到后面)ABABA(A操作开头，A操作结尾)......的操作序列，所以倒过来也还是ABABABA......完全一样的操作序列，那么我们就拿结果序列往回倒推即可

### 代码

```java
class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);//结果序列即排好队的序列
        Queue<Integer> queue = new LinkedList<>();
        for(int i=deck.length-1;i>0;i--)//由于最小的数已经在本来的位置，所以不用遍历到i=0
        {
            queue.offer(deck[i]);
            int temp=queue.poll();
            queue.offer(temp);
        }
        for(int i=deck.length-1;i>0;i--)//由于最小的数已经在本来的位置，所以不用遍历到i=0
        {
            deck[i]=queue.poll();
        }
        return deck;//倒推过程结束后即我们所要的结果
    }
}
```