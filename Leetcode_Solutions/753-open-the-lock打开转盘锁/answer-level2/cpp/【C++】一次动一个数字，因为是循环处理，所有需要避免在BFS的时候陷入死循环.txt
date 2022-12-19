1.初始化状态“0000”
2.每次每位向前或者向后动一下，1000或者9000这种
3.BFS搜索
4.如果变换后的target不是目标的target，添加到deadends队列中，避免后续重复进入，比如"0000"->"9000"再变换到"0000"，这样就循环了

```

struct ResultNode {
    string str;
    int depth;
};

class Solution
{
public:
    Solution()
    {
        key = "0123456789";
    }

    int openLock(vector<string>& deadends, string target)
    {
        copy(deadends.begin(), deadends.end(), inserter(this->deadends, this->deadends.begin()));
        if (target.empty() || target.length() != 4) {
            return -1;
        }

        return openLockBfs(target);
    }

private:
    int openLockBfs(string target)
    {
        string start = "0000";
        queue<ResultNode> pathQueue;
        pushStartString(start, pathQueue);

        while (!pathQueue.empty()) {
            ResultNode result = pathQueue.front();
            pathQueue.pop();
            if (target == result.str) {
                cout << target << "|" << result.str << "," << result.depth << endl;
                return result.depth;
            }
            if (deadends.find(result.str) != deadends.end()) {
                continue;
            }
            deadends.insert(result.str);

            for (int j = 0; j < result.str.length(); ++j) {
                for (int i = 0; i < key.length(); ++i) {
                    if (result.str.at(j) == key.at(i)) {

                        int num = key.at(i) - '0';
                        ResultNode next = result;
                        next.depth += 1; // 变化一次，深度添加一层
                        next.str[j] = key[(num + 1) % 10];
                        pathQueue.push(next);
                        ResultNode pre = result;
                        pre.depth += 1; // 变化一次，深度添加一层
                        pre.str[j] = key[(num + 9) % 10];
                        pathQueue.push(pre);
                        continue;
                    }

                }
            }
        }

        return -1;
    }

    void pushStartString(string start, queue<ResultNode> &pathQueue)
    {
        ResultNode result;
        result.str = start;
        result.depth = 0;
        pathQueue.push(result);
    }

private:
    string key;
    set<string> deadends;
};
```
