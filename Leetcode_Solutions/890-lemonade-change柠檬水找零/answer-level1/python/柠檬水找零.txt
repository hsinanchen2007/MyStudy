#### 方法：模拟情景

**思路与算法**

让我们尝试模拟给每个购买柠檬水的顾客进行找零的过程。最初，我们从没有 `5` 美元钞票也没有 `10` 美元钞票的情况开始。

* 如果顾客支付了 5 美元钞票，那么我们就得到 5 美元的钞票。

* 如果顾客支付了 10 美元钞票，我们必须找回一张 5 美元钞票。如果我们没有 5 美元的钞票，答案就是 `false`，因为我们无法正确找零。

* 如果顾客支付了 20 美元钞票，我们必须找回 15 美元。

    * 如果我们有一张 10 美元和一张 5 美元，那么我们总会更愿意这样找零，这比用三张 5 美元进行找零更有利。

    * 否则，如果我们有三张 5 美元的钞票，那么我们将这样找零。

    * 否则，我们将无法给出总面值为 15 美元的零钱，答案是 `false`。


```java [jPT7hXyM-Java]
class Solution {
    public boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        for (int bill: bills) {
            if (bill == 5)
                five++;
            else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
}
```
```python [jPT7hXyM-Python]
class Solution(object): #aw
    def lemonadeChange(self, bills):
        five = ten = 0
        for bill in bills:
            if bill == 5:
                five += 1
            elif bill == 10:
                if not five: return False
                five -= 1
                ten += 1
            else:
                if ten and five:
                    ten -= 1
                    five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `bills` 的长度。

* 空间复杂度：$O(1)$。