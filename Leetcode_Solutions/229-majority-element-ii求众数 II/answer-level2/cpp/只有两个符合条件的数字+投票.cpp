### 解题思路
关键是要明白大于n/3的数字最多有2个。
如果输入是123123123，各占1/3，没有符合条件的数字。
如果牺牲一个3（拿掉3），就成就了1和2，使得1和2成为了符合条件的数字。

再者要知道投票的做法。
三个人比拼，如果大家投票都不一样，那么可以认为这三个人的投票都不存在，互相删去。
比如123,123,12这样的情况，前面两组123都可以删去了，留下了12。
也就是说经过最后谁剩下了，就成为了比较多的那个候选人，最有可能成为符合条件的结果。

设置两个量：x和y，记录见过的最多的候选人。再来一个人z，如果不是x和y（不投给x和y），那么拼掉x和y手中各一票。
如果z是x或y（投给x或y），那么x或y手中的票就多了一个。

代码中的x和y其实代表两个提案的存放处。

来一个n代表某个提案，看看x和y是否有和自己相同的提案，有的话就给它投票。

如果没有，那么就回过头来看看x和y是否有空的，如果有空的那么自己就占用它。

如果既没有和自己相同的提案，也没有空位置可已占用，那就拼掉你们每个提案各一票。

### 代码

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;

        int x = 0, y = 0, count_x = 0, count_y = 0;
        for (int n : nums) {
            if (n == x) {
                count_x += 1;
                continue;
            } else if (n == y) {
                count_y += 1;
                continue;
            } if (count_x < 1) {
                x = n;
                count_x = 1;
                continue;
            } else if (count_y < 1) {
                y = n;
                count_y = 1;
                continue;
            }

            // 没有我想投的候选人，也没有空位让我增加我的候选人，
            // 我和你们同归于尽。
            count_x -= 1;
            count_y -= 1;
        }

        // 统计票数
        count_x = count_y = 0;
        for (int n : nums) {
            if (n == x) {
                count_x += 1;
            } else if (n == y) {
                count_y += 1;
            }
        }

        if (count_x > nums.size() / 3) {
            result.push_back(x);
        }
        if (count_y > nums.size() / 3) {
            result.push_back(y);
        }

        return result;
    }
};
```