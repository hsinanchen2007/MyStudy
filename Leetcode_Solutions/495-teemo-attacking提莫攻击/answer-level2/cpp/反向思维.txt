
拿到这题我第一反应是设一个很大的数组接受输入序列，标记中毒时间，但是考虑到题设中给的输入范围十分大，这样一来会浪费很多的空间
于是尝试从反向考虑这个问题：
考虑到时间总长度为输入序列的最后一项+间隔时间
视中毒的时间为“空泡”，两者做减法即可

时间复杂度为o(n)
```
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int i=0;//遍历用指针
        int sum=0;//计算空泡数量
        int timelenth=0;
      
        int lenth=timeSeries.size();
        int temp=0;
        
        if(lenth==0)
            return 0;
        
        while(i<lenth)
        {
            if(i>=1)
            temp=timeSeries[i-1]+duration;
            else
                temp=0;
            
            if(timeSeries[i]>temp)
                sum+=timeSeries[i]-temp;
            
            timelenth=timeSeries[i]+duration;
            i++;
        }
        return timelenth-sum;
    }
};
```

