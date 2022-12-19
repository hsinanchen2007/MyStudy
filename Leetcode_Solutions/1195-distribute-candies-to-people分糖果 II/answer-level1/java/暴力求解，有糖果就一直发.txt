### 解题思路
用一个变量i来计数，则i+1和剩余糖果数candies的较小值，是当前数组元素需要发放的糖果。

数组下标通过i % num_people 来定位，累加发放的糖果

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        int i = 0;
        while (candies > 0){
            // 当前发放糖果
            int send = Math.min(i + 1,candies);
            // 得到新的糖果
            res[i % num_people] += send;
            // 总糖果扣减
            candies -= send;
            i++;
        }
        return res;
    }
}
```