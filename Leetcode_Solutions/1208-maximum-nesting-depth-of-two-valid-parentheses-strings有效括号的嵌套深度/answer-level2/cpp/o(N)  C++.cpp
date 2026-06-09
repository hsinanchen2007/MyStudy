### 解题思路
首先应该想到的是，如果要求max(depth(A), depth(B))取值最小，则符合条件的最直观的划分，是**将那些嵌套深度大于1的有效括号子串对半分**。

按照嵌套深度从低到高，将匹配的左右括号对划分层次（第1层、第2层、...第depth层）。然后第1层的括号对分配给A，第2层的分配给B，第3层的再分配给A，第4层分配给B....依次类推。

如此这般的效果类似于，将有深度的括号对序列一分成两半，奇数层序的属于A，偶数层序的属于B。

实现上，用栈来匹配括号对，用一个flag变量记录层序信息。
需要注意的是，每成功匹配一对括号后，flag中记录的信息需要转变。

时间复杂度: O(N);
空间复杂度：O(N);

### 代码

```cpp

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(), 0);
        stack<int> sk;

        unsigned flag=0; //flag 记录当前栈顶左括号的层序信息     0：奇数层 1：偶数层
        for(int i=0; i<seq.size(); ++i){
            if(seq[i]=='('){ //此时的左括号与栈顶左括号 肯定属于不同的层 （层次增加）
                if(sk.empty()) flag=0;
                else flag=1-flag;
                sk.push(i);
                
            } 
            else{ // 右括号与栈顶左括号 属于同一层 （层次减少）
                int temp=sk.top();
                sk.pop();
                res[i]=flag;
                res[temp]=flag;

                flag=1-flag; //恢复上一层的层序信息
            }
        }

        return res;
    }
};
```