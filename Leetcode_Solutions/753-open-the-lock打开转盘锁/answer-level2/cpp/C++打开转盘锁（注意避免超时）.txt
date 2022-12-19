# 题目解析
本题明显的BFS题目，我感觉本题的难点在于
1.锁是可以双向旋转的（0-1，0-9），可能会漏掉状态
2.程序可能超时，有几条数据比较大，需要注意

方法
1.对于每个装态，考虑2个方向的变化
2.记录搜索过的节点，避免重复和死循环。可以考虑将deadends转为unordered_set提高查找效率，同时将搜索过的状态也放入deadends中。

# 示例代码
```
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        if("0000"==target)
            return 0;
        
        queue<string> myqueue;
    
        unordered_set<string> deadends_set;
        int result=0,stage=0;
        
        myqueue.push("0000");
        for(string item : deadends)
            deadends_set.insert(item);
        if(deadends_set.find("0000")!=deadends_set.end())    
            return -1;
        deadends_set.insert("0000");
        while(!myqueue.empty())
        {
            result++;
            stage=myqueue.size();
            for(int k=0;k<stage;k++)
            {
                for(int i=0;i<4;i++)
                {
                    string temp_add=myqueue.front(),temp_min=myqueue.front();
                    temp_add[i]='0'+(myqueue.front()[i]-'0'+1)%10;
                    temp_min[i]='0'+(myqueue.front()[i]-'0'-1+10)%10;
                    //cout<<result<<" "<<temp_min<<" "<<temp_add;
                    if(temp_add==target || temp_min==target)
                        return result;
                     
                    if(deadends_set.count(temp_add)==0)
                    {
                        myqueue.push(temp_add);
                        deadends_set.insert(temp_add);
                    }
                   

                    if(deadends_set.count(temp_min)==0)
                    {
                        myqueue.push(temp_min);
                        deadends_set.insert(temp_min);
                    }
                    
                    
                }
                myqueue.pop();
            }
        }
        return -1;
    }
};
```
