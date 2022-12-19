我认为这题降序排列数组 再顺序遍历一遍就可以了 
时间复杂度为nlogn 因为有排序 维护一个天数列表 空间复杂度为n
主要就是压缩天数的状态。用降序排列events数组满足贪心思想。
如果要参加最多的会议，那么必然追求压哨参加每一个会议。
```
class Solution {
public:
int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        if(n==1)
            return 1;
        vector<int> v(100001,0);
        sort(events.begin(),events.end());
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(events[i][0]==events[i][1]&&v[events[i][0]]==0)
                v[events[i][0]]++;
            else if(events[i][0]!=events[i][1])
            {
                for(int j=events[i][1];j>=events[i][0];j--)
                {
                    if(v[j]==0)
                    {
                        v[j]++;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<v.size();i++)
            if(v[i]==1)
                sum++;
        return sum;
        
    }
};
```
![image.png](https://pic.leetcode-cn.com/5a6ffe35b1d4888d93c79e9fb275979351f0c72fc609e25111715de5c1a119b9-image.png)

