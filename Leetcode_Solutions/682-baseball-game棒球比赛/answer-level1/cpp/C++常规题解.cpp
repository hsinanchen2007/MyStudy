![image.png](https://pic.leetcode-cn.com/e67788c61a3b9da12a36b47316ae4fc03e3c8dc7d22d82ce59a5effa1fc703e4-image.png)
解题思路：分四种情况：前两轮之和、上一轮两倍、删除上轮、输入本轮得分。此处有个技巧，第四种难写判断条件，可放到最后一个else后面。整体难度较低。
```
    int calPoints(vector<string>& ops) {
        int res = 0,addscr = 0,lastscr = 0;
            stack<int> points;
        for(auto itm : ops)
        {
            if(itm == "+")
            {
                lastscr = points.top();
                points.pop();
                addscr = lastscr + points.top();
                points.push(lastscr);
                points.push(addscr);
            }
            else if(itm == "D")
            {
                points.push(points.top() * 2);
            }
           else if(itm == "C")
            {
                points.pop();
            }
            else    
            {
                points.push(atoi(itm.c_str()));
            }
        }
        while(!points.empty())
        {
            res  += points.top(); 
            points.pop();
        }
        return res;
    }
```

