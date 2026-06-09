### 递归
选出最大的两个数，相减，将最大数变为-1，第二大数为相差。
出口：
	没有石头/只有一块石头，返回0/该数
	排序后第二大数<=0 则可知当前只剩下最后一个数了。

### 代码

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        if(stones.length == 0)
			return 0;
		if(stones.length == 1)
			return stones[0];
		Arrays.sort(stones);
		if(stones[stones.length-2] <= 0)
			return stones[stones.length-1];
		stones[stones.length-2] = stones[stones.length-1] - stones[stones.length-2];
		stones[stones.length-1] = -1;
		return lastStoneWeight(stones);   
    }
}
```