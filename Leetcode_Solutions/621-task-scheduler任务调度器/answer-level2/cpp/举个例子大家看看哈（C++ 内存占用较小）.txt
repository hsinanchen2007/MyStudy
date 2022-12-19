### 解题思路

仅给需要一些例子的朋友～

1）需要待命的情况：

```shell
例如：[Ax5, Bx5, Cx4, Dx3], **n=3**

to_fill = (5 - 1) x 3 = 12, n_jobs = min(5, 4) + 4 + 3 = 11
                                      ^因为B=A    ^C  ^D

次数最多的拖长了总时间。。

A   B   C   D
------------>
A   B   C   D
------------>
A   B   C   D
------------>
A   B   C   !
------------>
A   B   @   @  
---->

总时间=18
```

2) 无需待命的情况：

```shell
例如：[Ax5, Bx5, Cx4, Dx3], **n=2**

to_fill = (5 - 1) x 2 = 8, n_jobs = min(5, 4) + 4 + 3 = 11

这种情况下把D排在多余的一列，然后按顺序执行就好了，肯定不会出现冷却不够的情况。（希望比题解说的更清楚。。）

A   B   C | D
--------->  -
A   B   C | D
----->  -----
A   B   C | D
->  -------->
A   B   C |
-------->
A   B   @ |
----->

总时间=17
```

### 代码

```cpp
class Solution {
public:

    int leastInterval(vector<char>& tasks, int n) {

        // map counts to the alphabet
        int counts[26]{0};
        for (char task: tasks) {
            counts[task - 'A']++;
        }
        sort(counts, counts+26);

        // get the maximum count from the sorted array
        int max = counts[25];

        // the number of the blank slots to be filled 
        int to_fill = (max - 1) * n;

        // loop counts, get the number of slots still to be filled (the wait slot)
        for (int i = 24; i >= 0 && counts[i] > 0; i--) {
            to_fill -= min(max - 1, counts[i]);
            if (to_fill < 0) {
                to_fill = 0; break;    
            }
        }

        // execute one-by-one 
        return to_fill + tasks.size();
    }
};
```