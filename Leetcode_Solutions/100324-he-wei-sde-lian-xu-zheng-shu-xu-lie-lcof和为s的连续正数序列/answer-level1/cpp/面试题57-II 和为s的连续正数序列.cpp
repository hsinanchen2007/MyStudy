### 解题思路
思路：双指针。
当指针包括的区间和大于target，则减去头再比较；
如果和小于target，则end++往后扩；
如果和等于target，则加入res，然后end++继续往后扩；
显然停止的点是target+1的一半。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        // 特殊
        if(target <=0)
            return res;
        //功能
        int head = 1;
        int end = 2;
        int midTarget = (target+1)/2;
        int curSum = head+end;
        while(end <= midTarget)
        {
            if(curSum == target)
            {
                vector<int> tmpRes;
                for(int i=head;i<=end;i++)
                {
                    tmpRes.push_back(i);
                }
                res.push_back(tmpRes);
                end++;
                curSum += end;
            }
            else if(curSum < target)
            {
                end++;
                curSum += end;
            }
            else
            {
                while(curSum > target)
                {
                    curSum -= head;
                    head++;
                    if(curSum == target)
                    {
                        vector<int> tmpRes;
                        for(int i=head;i<=end;i++)
                        {
                            tmpRes.push_back(i);
                        }
                        res.push_back(tmpRes);
                    }
                }
                end++;
                curSum += end;
                
            }
        }
        return res;
    }
};
```