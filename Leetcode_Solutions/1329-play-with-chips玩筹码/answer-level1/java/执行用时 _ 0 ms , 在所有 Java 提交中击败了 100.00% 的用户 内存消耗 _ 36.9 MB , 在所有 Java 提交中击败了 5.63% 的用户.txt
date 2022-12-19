### 解题思路
啥也不说了，我是看了题解才写的解答，我理解能力太差了，代码很简单，理解起来很困难。

### 代码

```java
class Solution {
    public int minCostToMoveChips(int[] chips) {
        int count1 = 0;
        int count2 = 0;
        for(int i = 0;i<chips.length;i++) {
            if(chips[i]%2==0) {
                count2++;
            }else count1++;
        }

        return count1>count2?count2:count1;
    }
}
```