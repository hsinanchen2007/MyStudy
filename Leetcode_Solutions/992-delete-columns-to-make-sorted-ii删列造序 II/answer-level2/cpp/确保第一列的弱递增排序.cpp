### 解题思路
第一步，先选出一个弱递增（后一个字符大于等于前一个字符）的第一列（这一步也可以通过把tobechecked填满直接来做，看起来优雅点但慢得多）。在选出弱递增的过程中，记录后一个字符等于前一个字符的位置，到下一步继续检查。

第二步，检查tobechecked中的那几行是否在下一列相较于前一行是若递增的；如果不是，则将tobechecked的所有成员带到下一列中去检测；如果是，则继续将非强递增的行选出来，到下一列中继续去检查。

用时8ms，战胜90%。

### 代码

```cpp
class Solution {
public:
	int minDeletionSize(vector<string>& A) {
		int res = 0;
		int i = 0, j = 1;
        unordered_set<int> tobechecked;
// 选出弱递增的第一列
        for(; j < A.size() && i < A[0].size(); j++)
        {
            if(A[j][i] < A[j - 1][i])
            {
                j = 0;
                tobechecked.clear();
                i++;
                res++;
                continue;
            }
            if(A[j][i] == A[j - 1][i])
                tobechecked.insert(j);
        }
        i++;
// 将还未确定是否是递增的行选出来，继续检查
        while(i < A[0].size() && tobechecked.size())
        {
            unordered_set<int> left;
            for(int j: tobechecked)
            {
                if(A[j][i] < A[j - 1][i])
                {
                    left = tobechecked;
                    res++;
                    break;
                }
                else if(A[j][i] == A[j - 1][i])
                    left.insert(j);
            }
            tobechecked = left;
            i++;
        }
		return res;
	}
};
```