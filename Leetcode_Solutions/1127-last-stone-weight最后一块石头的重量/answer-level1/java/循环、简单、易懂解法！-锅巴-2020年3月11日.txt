### 解题思路
情况1：两个元素清0，
情况2：一个元素清0
最坏的情况下，每次最大的两个元素都不相等，n个元素，每次1个清零，那么最多n-1次就能满足剩下1个非0元素，进行返回结果。

那就建立循环：for (int i = 0; i < stones.length-1; i++)

从小到大排序：Arrays.sort(stones); 0全在前面，非0全在后面

进行大--小：weight = stones[stones.length - 1] - stones[stones.length - 2];

上面这步骤肯定存在特殊情况（最大元素非0，其余均为0）：大(是非0元素)-小(已经是0)，不用管，继续减即可。

最终返回最大者即可！

### 代码

```java
class Solution {
    public int lastStoneWeight(int[] stones) {
        int weight = 0;
        //i>1才会进入次循环
        for (int i = 0; i < stones.length-1; i++) {
            Arrays.sort(stones);

            weight = stones[stones.length - 1] - stones[stones.length - 2];
            stones[stones.length - 1]=weight;
            stones[stones.length - 2]=0;
            for (int j = 0; j <stones.length-1 ; j++) {
                System.out.print(stones[j]);
                System.out.print(",");
            }
        }//小-大顺序，前面全是0
        return stones[stones.length-1];
    }
}
```