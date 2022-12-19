用时0ms,内存6.5MB，先附上代码：
```
#include <stack>

struct Node {
    int layer;
    int idx_str;
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int n_layers = digits.length();
        if (n_layers == 0) return res;

        vector<string> dict = {"", 
                                "", "abc", "def", 
                                "ghi", "jkl", "mno", 
                                "pqrs", "tuv", "wxyz"};
        // 初始化字符串
        string str(n_layers, '0');

        // 初始化栈
        stack<Node> s;

        // 先使第一层的所有节点依次入栈
        int d = digits[0] - '0';
        for (int i = 0; i < dict[d].length(); ++i) 
            s.push({0, i});
        

        while (!s.empty()) {
            // 取出栈顶节点
            int cur_layer = s.top().layer;
            int cur_idx_str = s.top().idx_str;
            s.pop();
            // 根据节点中的层次信息和字符坐标信息，为字符串当前位置赋值
            int cur_d = digits[cur_layer] - '0';
            str[cur_layer] = dict[cur_d][cur_idx_str];
            // 若还有下一层，则把下一层所有的节点都入栈
            if (cur_layer < n_layers - 1) {
                int new_layer = cur_layer + 1;
                int new_d =  digits[new_layer] - '0';
                for (int i = 0; i < dict[new_d].length(); ++i) {
                    s.push({new_layer, i});
                }
            }
            // 否则当前已经处于最后一层，输出字符串即可
            else {
                res.push_back(str);
            }
        }
        return res;
    }
};
```


主要思路：
1. 将字符串纵向排列，每一个字符可以拓展为一层，这样就相当于有3个（或4个）节点为起始节点的单向图。
2. 设计Node结构体，方便保存当前的“位置”，即哪一层哪个字符。

草图：
![image.png](https://pic.leetcode-cn.com/42186a1d00b1e34107e1c563325da6a639e2c7aeb3bf7308104d47479e0f6143-image.png)

算法步骤：
1. 最开始使第一层（编号为0）的节点入栈
2. 开始进行dfs非递归遍历，这里不需要visited变量记录，因为需要列举所有情况，不担心重复，且路径是一层一层往下传播，不会有回路。
3. 每取出一个节点，就按照节点描述的坐标信息为预先定义好的字符串赋值。若当前不是最后一层，就把下一层的所有节点都入栈。

思路梳理（乱绕）：
对于第i层来说：取出事先入栈的最后一个节点时，为字符串第i个位置进行赋值，而当前层其他的可能性（节点）还在栈里。只有当前节点的下一层所有节点都遍历完之后，才会再取出第i层入栈的倒数第二个节点，此时会根据节点中保存的层次信息，为字符串的第i个位置重新赋值。

