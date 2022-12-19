
![image.png](https://pic.leetcode-cn.com/f96e50a939f5adc7fa3478f9fce8d1be69088bf0271b4b18472ba0a36e6a430b-image.png)

### 解题思路
遍历bank，统计遍历到的序列与当前序列(start)不同基因的数量，当数量为1时， 进入下一层。

### 代码

```cpp
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> step;
        helper(step, start, end, 0, bank);
        return minNum == INT_MAX ? -1 : minNum;
    }
    void helper(set<string>& step, string start, string end, int num, vector<string>& bank) {
        if (start == end) {
            minNum = min(num, minNum);
            return;
        }
        for (string str : bank) {
            int diff = 0;
            for (int i = 0; i < str.size(); i++) {
                if(str[i] != start[i]) 
                    diff++;
            } 
            if (diff == 1 && step.find(str) == step.end()) {
                    step.insert(str);
                    helper(step, str, end, num + 1, bank);
                    step.erase(str);
                }
        }
    }
private:
    int minNum = INT_MAX;
    
    

};
```