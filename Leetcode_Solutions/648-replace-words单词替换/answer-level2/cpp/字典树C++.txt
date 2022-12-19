```
#include<vector>
#include<string>
using namespace std;

class Solution {
    struct TreeNode {
        TreeNode* childs[26] = { NULL };
        int index = -1;
    };

    void buildTree(TreeNode* root, const string& str,int index) {
        for (int i = 0; i < str.length(); ++i) {
            int index = str[i] - 'a';
            if (root->childs[index] == NULL)
                root->childs[index] = new TreeNode();
            root = root->childs[index];
        }
        root->index = index;
    }

    int findIndex(TreeNode* root, const string& str, int begin, int end) {
        for (int i = begin; i < end; ++i) {
            int index = str[i] - 'a';
            if (root->index!=-1||root->childs[index] == NULL)
                break;
            root = root->childs[index];
        }
        return root->index;
    }

public:
    string replaceWords(vector<string>& dict, string sentence) {
        TreeNode* root = new TreeNode();
        for (int i = 0; i < dict.size(); ++i)
            buildTree(root, dict[i], i);
        string res = "";
        for (int i = 0; i < sentence.length(); ++i) {
            if (sentence[i] == ' ') {
                res += ' ';
                continue;
            }
            int j = i + 1;
            for (; j < sentence.length(); ++j) 
                if (sentence[j] == ' ') break;
            int index = findIndex(root, sentence, i, j);
            if (index == -1)
                res += sentence.substr(i, j - i);
            else
                res += dict[index];
            i = j - 1;
        }
        return res;
    }
};
```
