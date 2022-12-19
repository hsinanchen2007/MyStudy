### 解题思路
做这个题之前可以先看一下169题，投票算法，169题，找一个众数，那就只要一个候选，他是保证一定有一个是众数的，直接投票就好
但是这个题没有保证有一个元素一定出现 n/3以上。

首先我们得明确，n/k的众数最多只有k-1个，为什么呢？假设有k个众数，n/k * k=n,这k个元素都是众数，还要不同，怎么可能啊。那么对于这个题，超过n/3的数最多只能有3-1 = 2 个，我们可以先选出两个候选人A,B。 遍历数组，分三种情况：
- 候选1：> n/3
- 候选2：> n/3
- 其他：< n/3

### 写代码三步走
1、如果投A（当前元素等于A），则A的票数++;
2、如果投B（当前元素等于B），B的票数++；
3、如果A,B都不投（即当前与A，B都不相等）,那么检查此时A或B的票数是否减为0，如果为0,则当前元素成为新的候选人；如果A,B两个人的票数都不为0，那么A,B两个候选人的票数均减一。

最后会有这么几种可能：有2个大于n/3，有1个大于n/3，有0个大于n/3
遍历结束后选出了两个候选人，但是这两个候选人是否满足>n/3，还需要再遍历一遍数组，找出两个候选人的具体票数，因为题目没有像169题保证一定有。


### 代码

```java
class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> res = new ArrayList<>();
        if (nums == null || nums.length == 0) {
            return res;
        }
        // 定义两个候选者和它们的票数
        int cand1 = 0,cand2 = 0;    
        int cnt1 = 0, cnt2 = 0;
        // 投票过程
        for (int num : nums) {
            // 如果是候选者1，票数++
            if (num == cand1) {
                cnt1++;
                // 一遍遍历，如果你不想写continue，你写多个else if也可以
                continue;
            }
            // 如果是候选者2，票数++
            if (num == cand2) {
                cnt2++;
                continue;
            }
            // 既不是cand1也不是cand2，如果cnt1为0，那它就去做cand1
            if (cnt1 == 0) {
                cand1 = num;
                cnt1++;
                continue;
            }
            // 如果cand1的数量不为0但是cand2的数量为0，那他就去做cand2
            if (cnt2 == 0) {
                cand2 = num;
                cnt2++;
                continue;
            }
            // 如果cand1和cand2的数量都不为0，那就都-1
            cnt1--;
            cnt2--;
        }
        // 检查两个票数符不符合
        cnt1 = cnt2 = 0;
        for (int num : nums) {
            if (num == cand1) {
                cnt1++;
            } else if (num == cand2) {  
                // 这里一定要用else if
                // 因为可能出现[0,0,0]这种用例，导致两个cand是一样的，写两个if结果就变为[0,0]了
                cnt2++;
            }
        }
        int n = nums.length;
        if (cnt1 > n / 3) {
            res.add(cand1);
        }
        if (cnt2 > n / 3) {
            res.add(cand2);
        }
        return res;
    }
}
```