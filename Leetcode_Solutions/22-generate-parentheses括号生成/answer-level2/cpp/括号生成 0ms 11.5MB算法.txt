递归实现的深度优先遍历加回溯

#### 解题思路
开辟了一个2n大小的字符数组，用来暂存当前拼出的字符串。
需要用到的几个变量：
left： 保存当前左括号数量
right：保存当前右括号数量
index：保存当前需要写入字符的位置
res：  记录所有答案
每一次调用dfs时，判断是否已经写到最后一个位置，如果是的话，用当前暂存区的2*n个字符生成一个字符串，存入结果容器中。
如果并没有写到最后一个位置，就先判断是否可在index处写入一个左括号，条件：左括号数小于n。如果可以，写入，并对这种情况再次深度优先遍历。
再判断是否可以在index处写入右括号。此时先前采用左括号时的深度优先遍历已经执行完毕，分支上的所有可能字符串已经保存，因此，覆盖head[index]是不存在问题的。

#### 代码
```c++
class Solution {
public:
    void dfs(char* head, int left, int right, int index, int& n, vector<string>& res){
        if(index == (n  << 1)){
            string str(head, index);
            res.push_back(move(str)); // 这个是c++新特性，可以不必拷贝临时变量，以减少空间损耗
            return;
        }
        if(left < n){
            head[index] = '(';
            dfs(head, left + 1, right, index + 1, n, res);
        }
        if(right < left){
            head[index] = ')';
            dfs(head, left, right + 1, index + 1, n, res);
        }
    }
    vector<string> generateParenthesis(int n) {
        char *cache = new char[n*2];
        vector<string> res;
        dfs(cache, 0, 0, 0, n, res);
        delete[] cache; // 虽然对解题来说没什么意义，但是记得删掉，养成好习惯
        return res;

    }
};
```

#### tips
最好不要使用字符串拼接，效率很低
善用语言特性可以节省开销