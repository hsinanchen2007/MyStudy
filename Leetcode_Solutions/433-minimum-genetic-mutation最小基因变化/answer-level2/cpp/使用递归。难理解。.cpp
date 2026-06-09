### 解题思路
开始想了一个，但是没考虑到顺序问题。不对。

然后看了别人的解题。  好多都好复杂。 这个是唯一不那么复杂的， 但是还有些不太懂。

总的来说是通过递归，首先匹配到bank中与start只有一字母不一样的子串。然后把匹配到的子串作为start去递归，用minNum来记录最小次数，


执行用时 :0 ms, 在所有 C++ 提交中击败了100.00% 的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了98.25%的用户

### 代码

```cpp
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> step; //用来存储每个中途变换的子串。
        helper(step, start, end, 0, bank);
        return minNum == INT_MAX ? -1 : minNum;
    }
    void helper(set<string>& step, string start, string end, int num, vector<string>& bank) {
        if (start == end) {
            minNum = min(num, minNum);//更新最小值。
            return;
        }
        for (string str : bank) {
            int diff = 0;
            for (int i = 0; i < str.size(); i++) {
                if(str[i] != start[i]) 
                    diff++;
            } 
            if (diff == 1 && step.find(str) == step.end()) {//step.find(str)返回找到str的位置指针。
                //step.find(str) == step.end()表示在step中没有重复的str，
                step.insert(str);
                helper(step, str, end, num + 1, bank);
                step.erase(str);  //找到变换方法后，要把原来加入的子串删除。
            }
        }
    }
private:
    int minNum = INT_MAX;
};
```