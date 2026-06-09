
```cpp
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>l(deadends.begin(),deadends.end());
        if(l.count("0000"))
        return -1;
        queue<string>q;
        q.push("0000");
        unordered_set<string> v;
        v.insert("0000");
        int step = 0;
        int dir[2] = {-1,1};
        while(!q.empty())
        {
            int size = q.size();
            step++;
            for(int i = 0;i < size;i++)
            {
                string str = q.front();
                q.pop();
                for(int j = 0;j < 4;j++)
                {
                    for(int  t = 0;t < 2;t++)
                    {
                        char ch = str[j];//记录保存当前值，避免缺少部分情况
                        str[j] = (str[j] -'0' + 10 + dir[t]) % 10 + '0';
                        if(str == target)
                        return step;
                        if(v.count(str) !=0 || l.count(str)!=0 )//锁里面没有且未被使用过
                        {
                            str[j] = ch;
                            continue;
                        }
                        v.insert(str);
                        q.push(str);
                        str[j] = ch;//修改回原来的值
                    }
                }
            }

        }
        return -1;
    }
};
```