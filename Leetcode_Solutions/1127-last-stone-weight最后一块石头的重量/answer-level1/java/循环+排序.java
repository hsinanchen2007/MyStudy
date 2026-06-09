先排序，按题意减去最大的两个相减后再排序，重复之，直到最后倒数二个为0，最后剩下的即为题意所求。
```
if (stones.length == 1) return stones[0];
        Arrays.sort(stones);
        while (stones[stones.length - 2] != 0) {
            stones[stones.length - 1] = stones[stones.length - 1] - stones[stones.length - 2];
            stones[stones.length - 2] = 0;
            Arrays.sort(stones);
        }
        return stones[stones.length - 1];
```
