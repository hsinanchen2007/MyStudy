```
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int max=(target+1)/2;  //窗口最大值
        int numbers=(int)sqrt(2*target); //窗口最大范围
        vector<vector<int>> res;
        int nextBegin=1;
        while(numbers>=2)
        {
            for(int i=nextBegin;i+numbers-1<=max;i++)
            {
                int sum=(i+i+numbers-1)*numbers/2;
                if(sum<target)
                    continue;
                else if(sum==target)
                {
                    vector<int> temp;
                    for(int j=i;j<=i+numbers-1;j++)
                        temp.push_back(j);
                    res.push_back(temp);
                    nextBegin=i;
                    break;
                }
                else
                {
                    nextBegin=i;
                    break;
                }
            }
            numbers--;
        }
        return res;
    }
};
```
先根据target的值判断滑动窗口的范围，以及窗口中的值最大是多少；
根据n(n+1)=target 可得窗口最大范围为：sqrt(2*target),最大值(target+1)/2
然后接下来就是滑动窗口了，根据上次循环得情况确定下次循环中的窗口起始位置，减小一点时间。