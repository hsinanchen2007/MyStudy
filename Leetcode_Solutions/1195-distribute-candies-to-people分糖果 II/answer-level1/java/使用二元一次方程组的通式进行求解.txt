### 解题思路
其实这题使用初中数学方法即可解决，根据二元一次方程组：`n(n + 1)/2 = candies`，求解得到对应的n值
`n = (int)(-1 + Math.sqrt(1 + 8 * candies))/2`（为负数的情况舍去）
再求多出来的部分leaving = candies - (n + 1)*n/2
而后先求第一个小朋友分得到糖果，即如下：
```
for(int i = 1; i <= upperValue; i += num_people){
  count ++;
  result[0] += i;
}
```
其中count是统计循环次数，以便后面小朋友可以分得的糖果数直接可以通过`result[i] = result[i - 1] + count;`即可完成
因为糖果不一定够分，因此需要减去`endIndex = upperValue % num_people;`往后小朋友的糖果，即`for(int i = endIndex; i < num_people; i ++) result[i] -= (++ n);`
endIndex往后每个小朋友都多加了`n + i + 1 - endIndex(i >= endIndex)`个糖果。
至于为啥需要添加endIndex != 0，是因为刚好够分的情况，不需要减去。
最后再给第`endIndex`个小朋友分得剩下不够分的糖果`leaving`。

**但需要注意越界情况，因为`1 + 8 * candies在candies = 1,000,000,000`的情况下超过了int的范围，因而此时需要进行如下处理**，****即将2换算到根号里面****
即`n = (int)(-0.5 + Math.sqrt(0.25 + 2.0 * candies));`

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        if(num_people <= 0) return null;
        int[] result = new int[num_people];
        if(candies <= 0) return result;
        int upperValue = (int)(-0.5 + Math.sqrt(0.25 + 2.0 * candies));
        int leaving = candies - (upperValue + 1) * upperValue / 2;
        int count = 0;
        for(int i = 1; i <= upperValue; i += num_people){
            count ++;
            result[0] += i;
        }
        for(int i = 1; i < num_people; i ++){
            result[i] = result[i - 1] + count;
        }
        int endIndex = upperValue % num_people;
        if(endIndex != 0){
            for(int i = endIndex; i < num_people; i ++) result[i] -= (++ upperValue);
        }
        result[endIndex] += leaving;
        return result;
    }
}
```