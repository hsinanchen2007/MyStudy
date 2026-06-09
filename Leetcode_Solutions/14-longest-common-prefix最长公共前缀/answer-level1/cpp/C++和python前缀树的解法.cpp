```C++ []
class treeNode  //前缀树节点
{
public:
    treeNode()
    {
        data = vector<treeNode*>(26,nullptr);
        isword = false;
    }
    vector<treeNode*> data;
    bool isword;  //这个在这儿是判断诸如 输入  【“aaa”,“a”】的情况的，不过没有会输出“aaa”
};

class preTree
{
private:
    treeNode* root;
public:
    preTree()
    {
        root = new treeNode();
    }
    void insert(string str)   //这里和标准前缀树一样
    {
        treeNode* temp = root;
        for(int i = 0;i<str.size();i++)
        {
            if(temp->data[str[i]-'a']==nullptr)
            {
                temp->data[str[i]-'a'] = new treeNode();
                //cout << 1;
            }

            temp = temp->data[str[i]-'a'];
        }
        temp->isword = true;
    }
    
    string find()  //这里改了，因为我们不需要其他的信息
    {
        string res = "";
        treeNode* temp = root;
        while(temp!=nullptr)  //就是找26个节点里面是不是只有一个节点存在，如果不是就证明下面出现了分支，直接返回res
        {
            if(temp->isword)//这里的解释见上面
                return res;
            int index = 0;  //出现的节点的坐标
            int count = 0;  //节点个数
            for(int i =0;i<26;i++)
            {
                //cout << i <<" ";
                if(temp->data[i]==nullptr)
                    continue;
                
                count++;
                index = i;
            }
            if(count!=1)  //如果有多个节点，证明分支了，返回即可
                return res;
            //cout << res;
            res += ('a'+index);
            temp = temp->data[index];
        }
        return res;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if(len<1) return "";
        preTree tree;
        for(auto& ins : strs)
        {
            if(ins.empty())  //如果有“”输入，不可能有前缀
                return "";
            tree.insert(ins);
        }
            
        return tree.find();
        
    }
};
```
```python []
class treeNode:
    def __init__(self):
        self.isWord = False;
        self.data = [None for i in range(26)];
        

class preTree:
    def __init__(self):
        self.root = treeNode();
    
    def insert(self,word):
        node = self.root;
        for i in range(len(word)):
            if node.data[ord(word[i])-ord('a')] is None:
                node.data[ord(word[i])-ord('a')] = treeNode();
            node = node.data[ord(word[i])-ord('a')];
        node.isWord = True;
    
    def find(self) -> str:
        res = "";
        node = self.root;
        while node is not None:
            if node.isWord:
                return res;
            count = 0;
            index = 0;
            for i in range(26):
                if node.data[i] is not None:
                    count = count +1;
                    index = i;
            if count != 1:
                return res;
            res += chr(ord('a')+index);
            node = node.data[index];
        return res;
    

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        length = len(strs);
        self.tree = preTree();
        if length <1:
            return "";
        for ins in strs:
            if len(ins) == 0:
                return "";
            self.tree.insert(ins);
        return self.tree.find();
```


