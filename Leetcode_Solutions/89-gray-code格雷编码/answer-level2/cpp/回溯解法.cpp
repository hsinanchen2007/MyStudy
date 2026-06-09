### 解题思路
既然分类到回溯了，这里就用回溯解法。通过画树形图，可以观察到一个规律，当前节点中1的数量为偶数时，下面子节点依次为0,1。如果数量为奇数时，下面子节点依次为1,0。这样我们需要一个变量统计当前节点处1的数目，然后依次分类，递归两次，分别计算左右节点。

### 代码

```cpp
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        backtrack(n, 0, 0, 0, res);
        return res;
    }

    void backtrack(int n, int sum, int count, int lenght, vector<int>& res)
    {
        if(lenght == n)
        {
            res.push_back(sum);
            return;
        }

        if(count%2 == 0)//count为1的数目。若为偶数，以0开头，否则以1开头。
        {
            backtrack(n, sum*2, count, lenght+1, res);
            backtrack(n, sum*2+1, count+1, lenght+1, res);
        }
        else
        {
            backtrack(n, sum*2+1, count+1, lenght+1, res);
            backtrack(n, sum*2, count, lenght+1, res);
        }
    }
};
```