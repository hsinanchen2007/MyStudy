### 解题思路
求出两个元素之和为60的个数 比如31 + 29 = 60 
那么我们需要统计31 + (29 + 60), (31 + 60) + 29...等等这样的元素数量
为了避免大量运算 想到的就是将数据取模后存放在大小为60的数组里
如31/29这样的组合 只需要将arr[31] * arr[29]就能知道这个组合所有的个数
其中有两个例外: 60和30 它们都是和自身之和被60整除 它们的大小就是n(n-1)/2 
`题目中提到索引i小j大, 排列组合求可能性`
### 代码

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] arr = new int[60];
        for (int i = 0; i < time.length; i++) arr[time[i] % 60] ++;
        int count = arr[0] * (arr[0] - 1) / 2 + arr[30] * (arr[30] - 1) / 2;
        for (int i = 1; i < 30; i++) {
            count += (arr[i] * arr[60 - i]);
        }
        return count;
    }
}
```