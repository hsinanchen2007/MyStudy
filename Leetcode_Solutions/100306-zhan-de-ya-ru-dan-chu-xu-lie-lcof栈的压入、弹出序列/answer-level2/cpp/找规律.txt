我看大家都是用辅助栈做的，这里写一个取巧的办法。
总结起来就是，向后随便找，向前不能跳。下面用一个例子说明。

[1,2,3,4,5]
[4,5,3,2,1]

对popped进行遍历，对其中的每一个数字到pushed中进行查找，把找到的置为-1。比如popped第一个数字为4，那么就把pushed中4的位置变为-1。变为

[1,2,3,-1,5]
[4,5,3,2,1]

现在在pushed中找popped的第二个数字5，记住刚才数字4在pushed中的位置，以此位置为界，按照口诀，5可以出现在这个位置的后面，无论跳过几个数字都行。但是如果出现在这个位置的前面，就不能跳过未访问过的数字（既，不能跳过不为-1的数字）。本例中向后找5是可以的。变为

[1,2,3,-1,-1]
[4,5,3,2,1]

那么接下来找3,2,1，可以看到，从原来5的位置向前找，没有跳过任何一个未访问过的数字。所以可以匹配。

下面举一个不能匹配的例子。

[1,2,3,4,5]
[4,3,5,1,2]

直接跳过前面的步骤，4,3,5可以被成功的找到。变为

[1,2,-1,-1,-1]
[4,3,5,1,2]

此时pushed中的位置在原数字5上，接下来应该匹配的数字为1，那么可以看出，想要得到1，就必须跳过一个未访问过的数字2才行，不符合条件。所以不能匹配。

就酱，也不知道说没说明白。。
偶然想出来的，反正leetcode的测试用例是过了，不知道有没有奇怪的用例不能过的。


```c++
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int len1 = pushed.size(), len2 = popped.size();
        if (!len1 && !len2)
            return true;
        if (!len1 || len1 != len2)
            return false;

        int front = 0, back = 1;
        for (int i = 0; i < len2; i++)
        {

            // 判断是不是前面
            if (front >= 0 && popped[i] == pushed[front])
            {
                pushed[front] = -1;
                while (front >= 0 && pushed[front] == -1)
                    front--;
            }
            else
            {
                bool flag = false;
                // 那就是在后面
                for (int j = back; j < len1; j++)
                {
                    if (pushed[j] == -1)
                        continue;

                    if (popped[i] == pushed[j])
                    {
                        flag = true;
                        pushed[j] = -1;
                        back = j + 1;
                        break;
                    }
                    front = j;
                }
                if (!flag)
                    return false;
            }
        }
        return true;
    }
};
```
