### 解题思路
感觉像是初中奥数题，其实并不需要复杂公式推导。
有n个人，最后返回的数组长度就是n。
暴力求解的算法大家都能想到，就是复杂度偏高，但是我们注意到一个现象，在我们**最后一次**发糖果的时候，只会有两种情况：
1. 最后n个人都被发到了糖
2. 最后糖不够了，无法发给全部n个人

其实这两种情况是一样的，我们只需要保证最后一次发糖能把糖发完就行。
我们先忽略掉最后一次发糖可能的情况，只考虑前面的发糖次数，记为：countTimes
最后一次发糖的个数，记为：leftCandies
这时候我们的目标就变成了求解：countTimes和ledftCandies
这就相当简单了，我列个表大家感受一下，这个表记录了前countTimes发糖，每个人手里一共有多少糖的情况。

第1人|第2人|第3人|...|第n人|
:-:|:-:|:-:|:-:|:-:|
$1$|$2$|$3$|...|$n$|
$1+n$|$2+n$|$3+n$|...|$n+n$|
$1+2n$|$2+2n$|$3+2n$|...|$n+2n$|
...|...|...|...|...|
$1+\frac{countTimes * (countTimes - 1) * n}{2}$|...|...|...|$n+\frac{countTimes * (countTimes - 1) * n}{2}$|

这样我们就很容易能算出countTimes和leftCandies。
在此之后我们利用leftCandies去最后遍历一遍数组就行，时间复杂度为O(n)，空间复杂度为O(1)。

### 代码

```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];
        int oneTimeCounts = (1 + num_people) * (num_people) / 2;
        int countTimes = 0;
        int leftCandies = candies;
        while(leftCandies > 0){
            // 因为我们先不考虑最后一次发糖，所以countTimes在后面要减一
            countTimes++;
            // 一次遍历要把这一次发的糖求和
            leftCandies -= (oneTimeCounts + (countTimes - 1) * num_people * num_people);
        }
        leftCandies += (oneTimeCounts + (--countTimes) * num_people * num_people);
        for(int i = 0; i < num_people; i++){
            ans[i] = countTimes * (countTimes - 1) * num_people / 2 + countTimes * (i + 1);
            int needToAdd = countTimes * num_people + i + 1;
            if(needToAdd > leftCandies){
                ans[i] += leftCandies;
                leftCandies = 0;
            }
            else{
                ans[i] += needToAdd;
                leftCandies -= needToAdd;
            }
        }
        return ans;
    }
}
```