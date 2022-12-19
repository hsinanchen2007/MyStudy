### 解题方案
1. 直接一步步模拟题目步骤
2. 找到规律，使用数学公式简化计算

### 方案选择
1. 暴力解法直观，不易出错
2. 数学解法效率更高，需要花时间理解

### 暴力解法
没什么好说的，直接上代码
```java
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        int i = 0;
        while (candies > 0) {
            int round = i / num_people + 1;
            int index = i % num_people;
            int temp = index + 1 + num_people * (round - 1);

            res[index] += Math.min(candies, temp);

            candies -= temp;
            i++;
        }
        return res;
    }
```

### 数学解法
#### 抽象问题
- 分发糖果的数量依次排列，得到一个增长的等差数列 + 最后剩下的糖
```text
[ 0,  0,  0,  0,  0]
 +1, +2, +3, +4, +5   完整轮
 +6, +7, +8, +r       最后一轮

r代表最后剩下的糖，也就是（总数 - 等差数列之和）
0 <= r < 8, 8代表这个等差数列的最后一个数
```
- 对于数组中的每个元素，只需要计算一次，分为两步
    1. 加上所有 完整轮 中，这个下标位置增加的值
    2. 加上 最后一轮 中，这个下标位置增加的值
        - 需要判断等差数列是否结束

#### 问题难点
- 给定数列之和，求这个等差数列的长度
- `Math#sqrt`和`double`到`int`的类型转换，都会造成精度丢失，需要特别注意一下

#### 代码实现
```java
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        // AP(arithmetic progression with common difference 1) + remaining
        int lenOfAP = (int) (Math.sqrt(2 * candies + 0.25) - 0.5);
        int numOfFullRound = lenOfAP / num_people;

        for (int i = 0; i < num_people; i++) {
            // sum for full round
            res[i] = (i + 1) * numOfFullRound + num_people * (numOfFullRound * (numOfFullRound - 1) / 2);
// This for loop is equivalent to the expression above
//            for (int j = 0; j < numOfFullRound; j++) {
//                res[i] += (i + 1) + num_people * j;
//            }

            // add last round value
            if (i < lenOfAP % num_people) {
                // += from AP
                res[i] += (i + 1) + num_people * (numOfFullRound);
            } else if (i == lenOfAP % num_people) {
                // += remaining
                res[i] += candies - (1 + lenOfAP) * lenOfAP / 2;
            }
        }
        return res;
    }
```
### Repo
[Github Repo](https://github.com/muscaestar/myDailyLeetCode/tree/master/src/_1103_Distribute_Candies_to_People)
