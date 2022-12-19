### 算法分析
1. 使用广度优先搜索，定义哈希表ends存储deadends中的字符串
2. 定义哈希表visited存储访问过的字符串，定义num=0用于统计需要多少次转换
3. 定义队列queue，将0000加入队列，将空字符串入队用于判断是否累加转换次数num
4. 遍历队列直到为空，出队字符串node
5. 如果node==""，num累加，判断队列不为空，则加空字符串到队尾
6. 如果node==target，返回num
7. 如果ends不包含node，遍历字符串四个位置加减一对应的8个相邻节点，如果不在visited，将其加入visted和queue
### 复杂度分析
+ 时间复杂度：O(d + n^2*a^n)，d表示deadends.size()，a表示数组的个数，n表示字符串长度
+ 空间复杂度：O(d + a^n)
### 源码
```C++ []
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> ends;
        for (auto end : deadends)
        {
            ends.insert(end);
        }       

        string startNode = "0000";
        if (ends.find(startNode) != ends.end())
            return -1;

        set<string> visited;
        int num = 0;

        queue<string> queue;
        queue.push(startNode);
        queue.push("");

        while (!queue.empty())
        {
            string node = queue.front();
            queue.pop();
            
            if (node == "")
            {
                ++num; 

                if (!queue.empty())
                    queue.push("");
            }
            else if (node == target)
            {
                return num;
            }
            else if (ends.find(node) == ends.end())
            {
                for (int i = 0; i < 4; i++)
                {
                    for (int j = -1; j <= 1; j += 2)
                    {
                        int val = ((node.at(i) - '0') + j + 10) % 10;
                        string str = node;
                        str[i] = '0' + val;

                        if (visited.find(str) == visited.end())
                        {
                            visited.insert(str);
                            queue.push(str);
                        }
                    }
                }               
            }            
        }
        
        return -1;
    }
};