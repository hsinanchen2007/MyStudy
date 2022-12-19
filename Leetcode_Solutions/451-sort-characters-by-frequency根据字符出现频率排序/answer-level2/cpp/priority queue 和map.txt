### 解题思路
priority queue里存的是pair
1、将string导到map中实现统计次数；
2、将map导到优先队列(最大堆)中实现从大到小排序； 队列是push()和pop()
3、将优先队列导到string中存储结果
### 代码

```cpp
/*
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
*/

class Solution {
public:
    string frequencySort(string s) {
        string result;
        map<char,int> mymap;
        if (s.size() == 0) {
            return result;
        }
        for (auto it : s) {
            mymap[it]++;
        }
        priority_queue<pair<int,char>> myqueue;
        for (auto m : mymap) {
            myqueue.push({m.second, m.first}); //存的是pair
        }

        while (!myqueue.empty()) {
            auto t = myqueue.top();
            while (t.first--) { //控制输出次数
                result.push_back(t.second);
            }
            myqueue.pop();
        }
        return result;
    }
};

/*
int main()
{
    class Solution s;
    string str = "tree";
    string result = s.frequencySort(str);
    cout << "The result is : " << result << endl;
    system("pause");
    return 0;
}
*/
```