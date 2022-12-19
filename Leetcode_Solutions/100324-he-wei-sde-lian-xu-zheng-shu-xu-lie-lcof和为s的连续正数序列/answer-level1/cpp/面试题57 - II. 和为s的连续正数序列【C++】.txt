### 解题思路

首先很容易想到一点，最大可能取到的数是 `target/2 + 1` ，例如对 `target == 5` 而言，最大只可能取到 `5/2 +1 = 3` ，若取到4，由于题目要求是连续正整数，那么就必须取到3或者5，此时 `3 + 4 = 7` 已经大于目标值5。

这个题按照人的思维还是很容易想到的，就是从第一个正整数1开始往后依次相加，如果相加之后的和sum小于目标值，那就继续加后一个正整数，如果sum大于目标值，就减去序列最小的数，直到 `sum == target ` 即找到了一组符合题目要求的连续正整数。

转化为编程思想，我首先想到了用队列queue来存储一串连续的正整数。队列中的数的和小于目标值，就将后一个正整数加入队列；如果大于目标值，就将队首的最小数弹出；直到队列中的数的和等于目标值target，此时逐个取出队列中的数即为一组符合题意的连续正整数。但是，使用队列只能很方便的用于找到一组这样的数，如果我们要继续找第二组，那就要让第一组数中从第二个数开始的所有数重新加入队列，这是很不划算的~

所以，还是用 `vector<int>`，与队列同样的步骤，但不需要每次找到一组连续整数后都重新将那些数加入到数组，每找到一个只需要利用 `push_back()` 函数，仅一条语句就可以将这个 `vector<int>` 加入到 `vector<vector<int>>` 的返回值中，然后就可以继续使用这个`vector<int>` 查找下一组满足题目要求的连续整数。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;//返回值
        vector<int> consecutive;//存储连续的数
        int sum = 0;//一串连续的数的和
        for (int i = 1; i <= target;) {
            //consecutive.push_back(i);//将i加到一串连续的数的末尾
            //sum += i;//连续的数的和加上i
            if (sum < target) {
                sum += i;
                consecutive.push_back(i);//将i加到一串连续的数的末尾
                i++;
            }
            else if (sum == target) {
                ans.push_back(consecutive);
                sum -= consecutive[0];//减掉序列中最小的数
                consecutive.erase(consecutive.begin());//删去序列中最小的数
            }
            else {
                sum -= consecutive[0];
                consecutive.erase(consecutive.begin());//删除第一个元素（最小的数）
            }
        }
        return ans;
    }
};
```