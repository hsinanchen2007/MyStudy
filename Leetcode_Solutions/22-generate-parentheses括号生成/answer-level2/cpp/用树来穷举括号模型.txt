### 解题思路
用树来穷举括号模型
节点以结构体记录最新的数据
根据规则剔除不符合的字符串
耗时和内存消耗占用较大，后续再想想优化空间 
### 代码

```cpp
class Solution {
public:
    struct BracketTreeNode {
        char *bracket;
        int bracketValue;
        BracketTreeNode *leftChildNode;
        BracketTreeNode *rightChildNode;
        string resultString;
        int resultCount;
    };

    vector<string> generateParenthesis(int n) {
        vector<string> vaildBrackets;
        
        BracketTreeNode *rootNode = new BracketTreeNode();
        rootNode->bracket = "(";
        rootNode->bracketValue = 1;
        rootNode->leftChildNode = NULL;
        rootNode->rightChildNode = NULL;
        rootNode->resultString = rootNode->bracket;
        rootNode->resultCount = rootNode->bracketValue;

        createBracketTreeNodeWithRoot(rootNode, n * 2 - 1, vaildBrackets);
        
        return vaildBrackets;
    }

    void createBracketTreeNodeWithRoot(BracketTreeNode *rootNode, int nodeLevel, vector<string> & vaildBrackets) {
        

        BracketTreeNode *leftNode = new BracketTreeNode();
        leftNode->bracket = "(";
        leftNode->bracketValue = 1;     
        leftNode->leftChildNode = NULL;
        leftNode->rightChildNode = NULL;
        leftNode->resultString = rootNode->resultString + leftNode->bracket;
        leftNode->resultCount = rootNode->resultCount + leftNode->bracketValue;

        BracketTreeNode *rightNode = new BracketTreeNode();
        rightNode->bracket = ")";
        rightNode->bracketValue = -1;     
        rightNode->leftChildNode = NULL;
        rightNode->rightChildNode = NULL;
        rightNode->resultString = rootNode->resultString + rightNode->bracket;
        rightNode->resultCount = rootNode->resultCount + rightNode->bracketValue;
        
        if (nodeLevel == 1) { 
            if (leftNode->resultCount == 0 && leftNode->bracketValue != 1) {
                vaildBrackets.push_back(leftNode->resultString);
            }

            if (rightNode->resultCount == 0) {
                vaildBrackets.push_back(rightNode->resultString);
            }

            return ;
        }

        nodeLevel --;

        createBracketTreeNodeWithRoot(leftNode, nodeLevel , vaildBrackets);
        
        if (rootNode->resultCount != 0) {
            createBracketTreeNodeWithRoot(rightNode, nodeLevel, vaildBrackets);      
        }
        
    }


};
```