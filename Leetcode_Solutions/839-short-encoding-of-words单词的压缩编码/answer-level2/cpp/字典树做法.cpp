### 解题思路
借鉴官方题解，使用字典树解决问题

注意在构建出字典树之后的做法，，，并不是统计结点个数，这样会有错误，比如用例 {"time", "atime", "btime"}

最好是像题解一样，用个map来存下树末端结点，省得后面还得去遍历树，节约时间。然后在结点类中加个flag标记是否可以复用后缀，在每次添加的时候如果结点有了向下的指向，说明结点已经被用了，可以与后面共用后缀，就修改flag，当然代码用的是count标记。

记得处理#信息，在遍历叶子结点时，实际上每个叶子结点代表一个单词，所以遍历每个叶子节点，如果发现可以复用就直接不管，不能复用就加word的长度，再加#的信息

walk实现的是统计结点个数，，，实际这个题用不到，就先保留着吧

### 代码

```cpp
int num = 0;
class treenode
{
public:
    treenode *next[26];
    int count=0;
    treenode()
    {
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
    treenode* insert(string word)
    {
        treenode *ptr = this;
        for (int i = word.length() - 1; i >= 0; i--)
        {
            if (ptr->next[word[i] - 'a'] == NULL)
            {
                ptr->next[word[i] - 'a'] = new treenode();
                ptr->count++;
            }
            ptr = ptr->next[word[i] - 'a'];
        }
        return ptr;
    }
    void walk()
    {
        treenode *ptr;
        int flag = 0;
        for (int i = 0; i < 26; i++)
        {
            if (this->next[i] != NULL)
            {
                ptr = this->next[i];
                num++;
                ptr->walk();
                flag = 1;
            }
        }
        if (flag == 0)
        {
            num++;
        }
    }
};
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        treenode *root = new treenode();
        unordered_map<treenode*,string> list;
        int ans=0;
        treenode* ptr;
        for (auto str : words)
        {
            ptr=root->insert(str);
            list[ptr]=str;
        }
        for(auto iter=list.begin();iter!=list.end();iter++){
            if(iter->first->count==0){
                ans+=(iter->second.size()+1);
            }
        }
        return ans;
    }
};
```