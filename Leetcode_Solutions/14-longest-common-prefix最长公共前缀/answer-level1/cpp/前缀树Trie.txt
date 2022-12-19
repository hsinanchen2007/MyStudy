### 解题思路
普通的前缀树，加了2个变量，分别存储子节点个数，最新一个子节点下标。

### 代码

```cpp
class Solution {
    bool flag;
    int  single;//判断子节点个数
    int index;//子节点下标
    Solution * child [26] = {nullptr};
public:
    Solution():flag(false),single(0){};
    void push(string & str)
    {
        Solution * cur = this;
        for(char x : str)
        {
            if(cur->child[x-'a'] == nullptr)
            {
                (cur->single)++;//子节点+1，或者if((cur->single)++) break; 不存储，但single++,
                cur->index = x-'a'; //记录最新的子节点下标，当只有一个子节点 single == 1 时，就是唯一的一个子节点下标
                cur->child[x-'a'] = new Solution();
            }
            cur = cur->child[x-'a'];
        }
        cur->flag = true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        for(int i=0;i<strs.size() && this->single < 2;i++) // 只判断了第一个字母是否唯一，第一次push时single==0
            push(strs[i]);
        string s;
        if(this->flag) return s; // “”空字符串时，flag == true;
        for(Solution * cur = this; cur->single == 1;cur = cur->child[cur->index])
        {
            s.push_back('a'+ cur->index);
            if (cur->child[cur->index]->flag) // 当前是否字符串尾部
                break;
        }  
        return s;
    }
};
```