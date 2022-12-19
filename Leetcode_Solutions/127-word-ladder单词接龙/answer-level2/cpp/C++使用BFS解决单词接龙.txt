### 解题思路
先放一个BFS解题模版，BFSBFS通常使用队列实现
```
初始化队列Q;
Q={起点S};
标记S为已经访问;
while(Q非空)
{
    取Q队首元素u;
    u出队;
    if(u==目标状态)
    {
        找到目标，返回;
    }
    所有与u相邻且未被访问的点进入队列;
    标记u已经被访问;
}
```


### 代码

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())
        {
            return 0;
        }
        //判断endword在不在wordlist中，如果不在直接返回0
        bool visited[(int)wordList.size()];
        memset(visited,false,sizeof(visited));
        //初始化记录节点访问情况的数组visited
        int index=find(wordList.begin(),wordList.end(),beginWord)-wordList.begin();
        if(index>=0 && index<wordList.size())
        {
            visited[index]=true;
        }
        //查找beginword是否在wordlist中，如果在就将其标记为true
        queue<string>Q;
        Q.push(beginWord);
        int count=0;
        //使用模块
        while(!Q.empty())
        {
            int size=Q.size();
            count++;
            while(size-- > 0)
            {
                string start=Q.front();
                Q.pop();
                if(start==endWord)
                {
                    return count;
                }
                //找到目标，返回结果
                for(int i=0;i<wordList.size();i++)
                {
                    if(visited[i])
                    {
                        continue;
                    }
                    //被访问过，跳过
                    if(!canConvert(start,wordList[i]))
                    {
                        continue;
                    }
                    //不能转换，跳过
                    //访问过，添加到队列，并标记为true
                    visited[i]=true;
                    Q.push(wordList[i]);
                }  
            }
        }
        return 0;
    }
    bool canConvert(string s1,string s2)
    {
        int count=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
            if(count>1)
            {
                return false;
            }
        }
        return count==1;
    }
};
```