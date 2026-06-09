### 解题思路
感谢题解区的同学们！！！

### 代码

```cpp
struct Node {
    Node *next[26];
    bool flag;     //标记字段，本地中并没有用到该字段
    Node() {
        for(int i = 0 ; i < 26; i++) {
            next[i] = nullptr;
        }
        flag = false;
    }
};

const int MAXN = 2000*7+1;
//Node pool[MAXN];  //定义一个结点池，结合 placement new 实现内存复用。
class Solution {
    int poolPtr;
    inline Node *getNodePtr() {//内联函数，节省空间和时间
        //return new (&pool[poolPtr++]) Node();
        return new Node();
    }
    void Insert(Node *root, string str, int pos) {
        if(pos < 0) {
            root->flag = true; //记录有 str 到此结束了。
            return ;
        }
        int ind = str[pos]-'a';
        if(root->next[ind] == nullptr) {
            root->next[ind] = getNodePtr(); //记录 str 在 pos 处的字符。
        }
        Insert(root->next[ind], str, pos-1);
    }
    int Count(Node *root, int edgeCnt) {
        bool isLeaf = true;
        int sum = 0;
        for(int i = 0; i < 26; i++) {
            if(root->next[i] != nullptr) {
                isLeaf = false;
                sum += Count(root->next[i], edgeCnt+1);
            }
        }
        if(isLeaf) {
            return edgeCnt + 1; // 1 是 '#' 的长度
        }
        return sum;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        poolPtr = 0;
        auto root = getNodePtr();
        for(int i=0; i<words.size(); i++) {
            Insert(root, words[i], words[i].size()-1);
        }
        return Count(root, 0);
    }
};
```