最直接（二）的方法模拟入栈出栈操作，成功即可：
```
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n_push = pushed.size();
        int n_pop = popped.size();

        //定义一个栈来模拟入栈出栈操作
        stack<int> sta;
        //定义两个队列存放vector
        queue<int> q_pushed;
        queue<int> q_popped;
        for(int m = 0;m < n_push;m++)
        {
            q_pushed.push(pushed[m]);
            q_popped.push(popped[m]);
        }
        int count = 0;
        while(!q_popped.empty())
        {
            if(!sta.empty() && sta.top()==q_popped.front())
            {
                sta.pop();

                q_popped.pop();
                continue;
            }
            if(!q_pushed.empty())
            {
                sta.push(q_pushed.front());
                q_pushed.pop();
            }
            count++;
            if(count >= 2*n_pop)
            {
                break;
            }
        }

        if(sta.empty())
        {
            return true;
        }
        else
            return false;
        }
```
