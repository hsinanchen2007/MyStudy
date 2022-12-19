```
class Solution {//通过代码
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(),[](vector<int>& a, vector<int>& b)
        		{
        			if(a[0] == b[0])
        				return a[1] < b[1];
        			return a[0] < b[0];
        		});
        int i, j, count = 0, attendTime = 0;
        for(i = 0; i < events.size(); ++i)
        {
        	if(attendTime < events[i][0])
        	{
        		attendTime = events[i][0];
        		count++;
        		attendTime++;//下一个可参加的时间
        	}
        	else if(attendTime <= events[i][1])//参加时间在区间内
        	{
        		for(j = i+1; j < events.size() && events[i][1] <= events[j][1]; ++j)
        		{	//向下查找，被i包含的区间j
        			if(attendTime < events[j][0])
        				break;//如果与attendTime没有交点，后面都不可能有
        		}
        		if(j < events.size() && attendTime >= events[j][0])
        		{	//如果有交点，优先参加j
        			count++;
        			events.erase(events.begin()+j);//参加了，删除掉
        			attendTime++;//下一个可能的参会时间点
        			i--;//后面会i++，先--i,继续跳转到原来的i进行处理
        			continue;
        		}
                count++;//attendTime与j没有交点，参加会议 i
        		attendTime++;//时间点往后挪一个
        	}
        }
        return count;
    }
};

```

```
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<int,vector<int>, greater<int>> q;//小顶堆，结束时间早的，先出队
        int count = 0, i = 0, time = 0;
        while(i < events.size() || !q.empty())
        {
            time++;
            while(!q.empty() && q.top() < time)//结束时间过去了，该会议删除
                q.pop();
            while(i < events.size() && events[i][0] == time)
            {
                q.push(events[i][1]);//time时间，会议i开始了，把他的结束时间push进去
                i++;
            }
            if(!q.empty())
            {
                count++;
                q.pop();//最早结束的先参加
            }
        }
        return count;
    }
};
```

[https://michael.blog.csdn.net/article/details/104344969](https://michael.blog.csdn.net/article/details/104344969)