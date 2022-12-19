### 解题思路
思路就是先求出能完整分发几轮，知道完整轮次后，可以求出最后一个不完整的轮次总共要发几个
然后可以在遍历的过程中求出每个小朋友在完整轮次内获得的糖果数，以及最后一个不完整的轮次内小朋友能获得的糖果数
只需要遍历一次**num_people**，时间复杂度`O(num_people)`

# 一、先算出能完整分发几轮，记为**round**
1. 先求出分发第一轮需要的糖果数`baseNum=(1 + num_people) * num_people / 2`;
1. 再求出某一完整的轮次发放的糖果比上一个完整轮次发放的糖果数量的差值`addOneRound = num_people * num_people`;
1. 然后列出不等式 `[baseNum+baseNum+(round-1)*addOneRound]*round/2<=candies`
不等式含义：每一个完整的轮次发放出的糖果数量是等差数量，首项是第一轮的糖果数**baseNum**，公差是**addOneRound**，项数是**round**，末项是`baseNum+(round-1)*addOneRound`，利用求和公式，求出的和<=糖果数**candies**
化简得到`addOneRound*round^2+(2*baseNum-addOneRound)*round-2*candies<=0`
为了方便起见，**addOneRound**简称**a**，**baseNum**简称**b**，**candies**简称**c**，所求的**round**简称**x**
所以不等式为`2ax+(2b-a)x-2c<=0`
利用求根公式
![image.png](https://pic.leetcode-cn.com/ce93c04f9abe41ace030dcbdee4fab6078f6a6c11fc80f96f0102bda5b56adf2-image.png)
求出较大那个根，即为能完整分发的最大轮次round
![image.png](https://pic.leetcode-cn.com/6c8d14b448d8f680ab040aa08a3489a51c4fc31866f1aa743efbad4e561e995a-image.png)

代码为
```
double roundD = (addOneRound - 2 * baseNum + Math.Sqrt(Math.Pow(2 * baseNum - addOneRound, 2) + 8.0 * addOneRound * candies)) / (2 * addOneRound);
```

# 二、求出轮次**round**后，接着求出发了这么多轮次后，能剩下多少糖果**rest**（如果一个完整的轮次都发不了，则**rest**=**candies**）
- 为了求**rest**，先求出发了**round**轮后，总共发了多少糖果，等差数列求和（有两种求和的思路，一种是按照每轮发放糖果作为等差数列的项，一种是按照每人被发了**round**轮后得到的糖果数作为等差数列的项，此处采用第二种），首项**start**，即第一个人在发了**round**轮糖果后，手上的糖果数，公差是**round**，因为每一轮，后面的人总是比前面的人多拿了**1**个糖果，经过**round**轮后，差值累积到了**round**；项数是**num_people**；
    - 求首项start的话，同样也是等差数列，第一个人第一轮拿到1，第二轮拿到1+num_people，第三轮拿到1+num_people+num_people……所以start=  (1+1 + (round - 1) * num_people) * round / 2;即start=(2 + (round - 1) * num_people) * round / 2;
- 所以经过**round**轮，一共发了` (2 * start + (num_people - 1) * round) * num_people / 2`个糖果，可以求出最后一个不完整的轮次所要发放的糖果总数**rest**；

# 三、最后遍历每个小朋友，给小朋友发糖，包括两部分，第一部分是完整轮次的糖果，第二部分是最后一轮不完整的糖果
1. 完整轮次部分：给该小朋友先发放完整轮次的糖果数是在第二部分中求**rest**的时候所用等差数列的项，所以第0个小朋友所获得的完整轮次部分的糖果总数为**start**，第1个小朋友比第0个小朋友多拿了**round**，第2个小朋友由比第1个小朋友多拿了**round**，所以第i个小朋友比第0个小朋友多拿了`i*round`个糖果，所以第i个小朋友这部分拿到的糖果数是`start + i * round`；
2. 最后一轮不完整的部分:最后一个不完整的轮次里给第i个小朋友发放的糖果数记为**num**，**num**的初始值也就是第一个小朋友在这个轮次拿到的糖果数**lastThisRound**，由于第一个小朋友每轮拿到的糖果数也构成等差数列，求和得到末项`lastThisRound = 1 + round * num_people`;
所以每个小朋友在最后一个不完整的轮次里拿到的糖果数就从**lastThisRound**开始递增，直到发完。
1. 所以第i个小朋友能拿到的糖果数是`result[i] += start + i * round + num`;每次计算后**lastThisRound**需要递增**1**，因为下一个小朋友会比这个小朋友多拿到**1**个糖果；最后一轮的剩余糖果数**rest**要递减**num**，毕竟刚刚又发掉了**num**个糖果（最后一个不完整的轮次），**rest**的递减需判断一下，如果不够扣了就不扣了，说明最后一个不完整的轮次也发完了，这部分就不发了；

### 代码

```csharp
public class Solution {
    public int[] DistributeCandies(int candies, int num_people) {
            int baseNum = (1 + num_people) * num_people / 2;
            int addOneRound = num_people * num_people;
            double roundD = (addOneRound - 2 * baseNum + Math.Sqrt(Math.Pow(2 * baseNum - addOneRound, 2) + 8.0 * addOneRound * candies)) / (2 * addOneRound);
            int round = (int)Math.Floor(roundD);
            int[] result = new int[num_people];

            int rest = candies;
            int start = (2 + (round - 1) * num_people) * round / 2;
            if (round >= 1)
            {
                rest -= (2 * start + (num_people - 1) * round) * num_people / 2;
            }

            int lastThisRound = 1 + round * num_people;
            for (int i = 0; i < num_people; i++)
            {
                int num = (rest >= lastThisRound) ? lastThisRound : rest;
                result[i] += start + i * round + num;
                lastThisRound++;
                rest -= num;
            }
            return result;
    }
}
```