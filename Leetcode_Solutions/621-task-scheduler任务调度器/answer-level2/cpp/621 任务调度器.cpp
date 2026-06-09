### 解题思路
根据官方解答中的方法三解答

### 代码

```cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26); //记录每个任务的频次
        int maxTimes = 0; //最高的频次
        int maxLetters = 0; //出现最高频次的任务的数量
        for (char c:tasks) 
            maxTimes = max(maxTimes, ++count[c-'A']);
        for (int i=0; i<26; i++) 
            if (count[i] == maxTimes)
                maxLetters++;
        return max((int)tasks.size(), (maxTimes-1)*(n+1)+maxLetters);
    }
};
```