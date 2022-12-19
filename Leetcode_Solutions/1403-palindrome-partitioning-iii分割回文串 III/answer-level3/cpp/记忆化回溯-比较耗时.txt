### 解题思路

思路：回溯
1、首先分两个步骤来解这个题：一是字符串分成k段有多少种分法，二是在每种分法里面计算最小回文操作数
2、所以其实最重要的就是把这个字符串分割列表给统计出来，每次满足条件的时候才去想回文的事情
3、对于一个字符串s，假设长度为len，那么要分成k段的话，每一段最大的长度为len-k+1，最小长度为1，那么我们就可以进行遍历回溯
4、结束条件：
    > 记录遍历过程记录当前位置字符串索引，字符串走到尾部的时候，如果分段个数也满足条件k，计算该场景分段的最少回文操作数
    > 字符串走到尾部，k没满足或者分段个数超过k时字符串还没到尾部，提前返回进行回溯
5、结果 ~ 超时，因为存在太多的重复计算

基于上述结果，可以考虑记忆化数组，不过在记忆化数组实现的时候，就不能全遍历所有字符串之后再统计了，因为记忆化数组要达到的目的是在某个状态下的值，就是当前的最优值，或者结果值
1、我们可以假设mem[i][j]表示当前处于字符串的i位置时，剩余划分次数为j时的最优解，注意这里的划分次数和分段的关系，假设分成k段，那么划分次数及应该是k-1
2、终止条件：
    > 如果当前剩余字符串长度<=剩余划分次数的时候，划分失败，比如当前剩余字符串长度为3时，其实最大只能进行两次划分
    > 记忆化数组里面存在当前划分方式的时候，直接返回，因为记忆化数组种记录的总是最优解
    > 如果剩余划分次数为0时，表明当前剩余字符串不需要进行划分了，记忆化数组中存储剩余字符串的最优解即可
3、循环遍历当次能够取到的字符串的长度，计算该长度下的字符串的最优解

124ms 69.6M
--- wangtao HW-2020/3/3

### 超时代码

```cpp
class Solution {
public:
    int opCount(string s)
    {
        int count = 0;
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if (s[i] != s[j]) {
                count++;
            }
            i++;
            j--;
        }
        return count;
    }

    int calcMinOpCount(vector<string>& stack)
    {
        int count = 0;
        for (int i = 0; i < stack.size(); i++) {
            if (stack[i].size() == 1) continue;
            count += opCount(stack[i]);
        }
        return count;
    }

    void partionDFS(string s, int curindex, int k, vector<string>& stack, int& ans)
    {
        if (curindex >= s.size() && stack.size() < k) return;
        if (curindex < s.size() && stack.size() >= k) return;
        if (curindex == s.size() && stack.size() == k) {
            // 计算最小操作数
            int mincount = calcMinOpCount(stack);
            ans = min(ans, mincount);
            return;
        }
        for (int i = 1; i <= s.size() - k + 1; i++) {
            if (curindex + i > s.size()) continue;
            stack.push_back(s.substr(curindex, i));
            partionDFS(s, curindex + i, k, stack, ans);
            stack.pop_back();
        }
    }

    int palindromePartition(string s, int k) {
        vector<string> stack;    
        int ans = INT_MAX;
        int curindex = 0;

        partionDFS(s, 0, k, stack, ans);
        return ans;
    }
};
```

### 记忆化代码
```cpp
class Solution {
public:
    int opCount(string s, int start, int end)
    {
        int count = 0;
        int i = start;
        int j = end - 1;
        while(i < j) {
            if (s[i] != s[j]) {
                count++;
            }
            i++;
            j--;
        }
        return count;
    }

    int partionDFS(string s, int len, int start, int k, vector<vector<int>>& mem)
    {
        if (len == start && k == 0) return 0;
        if (len - start <= k) {
            return -1;
        }
        if (mem[start][k] != -1) {
            return mem[start][k];
        }
        if (k == 0) {
            return mem[start][k] = opCount(s, start, len);
        }
        int minCost = INT_MAX;
        for(int i = 1; i <= len - start; i++) {
            int costs = opCount(s, start, start + i);
            int sub = partionDFS(s, len, start + i, k - 1, mem);
            if (sub == -1) {
                break;
            }
            minCost = min(minCost, costs + sub);
        }
        return mem[start][k] = minCost;
    }

    int palindromePartition(string s, int k) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, -1));
        
        return partionDFS(s, n, 0, k - 1, mem);
    }
};
```
