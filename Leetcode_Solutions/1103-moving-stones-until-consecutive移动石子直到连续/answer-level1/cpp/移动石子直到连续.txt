#  移动石子直到连续
三枚石子放置在数轴上，位置分别为 a，b，c。

每一回合，我们假设这三枚石子当前分别位于位置 x, y, z 且 x < y < z。从位置 x 或者是位置 z 拿起一枚石子，并将该石子移动到某一整数位置 k 处，其中 x < k < z 且 k != y。

当你无法进行任何移动时，即，这些石子的位置连续时，游戏结束。

要使游戏结束，你可以执行的最小和最大移动次数分别是多少？ 以长度为 2 的数组形式返回答案：answer = [minimum_moves, maximum_moves]

 

示例 1：

```
输入：a = 1, b = 2, c = 5
输出：[1, 2]
解释：将石子从 5 移动到 4 再移动到 3，或者我们可以直接将石子移动到 3。
```

示例 2：

```
输入：a = 4, b = 3, c = 2
输出：[0, 0]
解释：我们无法进行任何移动。
```

提示：

1 <= a <= 100
1 <= b <= 100
1 <= c <= 100
a != b, b != c, c != a

<hr>

##  解题思路：
移动次数最大值：移动a和c，一次只走一格。所以maxn=（z-y-1）+（y-x-1）=z-x-2
<br>
移动次数最小值：移动一次尽可能的走多步
- 若存在连续的两个石子以及间隔只有一个位置的石子，则说明只需要移动一次就能使3个石子连续。例如：1 2 4，1 3 5
- 若不存在则移动x时要移动到y的前面一格，然后再将在z移动到 x前面。 

###  实现代码：

```
class Solution {
public:
    static bool cmp(const int &a,const int &b)
    {
        return a<b;
    }
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> res;
        vector<int> n{a,b,c};
        sort(n.begin(),n.end(),cmp);
        int maxn=n[2]-n[0]-2;
        int minn=0;
        if(n[0]+2==n[1] || n[2]-2==n[1])//存在间隔为1的石子
        {
            minn++;
        }
        else 
        {
            if(n[0]+1<n[1])
            {
                if((n[1]+1)!=n[2])
                {
                    n[0]=n[1]+1;
                    minn++;
                }
                else
                {
                    n[0]=n[1]-1;
                    minn++;
                }
                sort(n.begin(),n.end(),cmp);
            }
             if(n[2]-1>n[1])
            {
                minn++;
            }
        }
        res.push_back(minn);
        res.push_back(maxn);
        return res;
    }
};
```

