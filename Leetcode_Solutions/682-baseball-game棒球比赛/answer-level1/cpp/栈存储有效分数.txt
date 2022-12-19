### 解题思路
1. 用一个栈保存有效的分数
2. 对栈中的分数求和

### 代码

```cpp
class Solution {
public:
    int calPoints(vector<string>& ops) {
        int ans = 0;
        stack<int> sk;
        int pre, cur;
        for(int i=0;i<ops.size();i++){
            if(ops[i] == "+") {
                pre = sk.top(); sk.pop();
                cur = pre + sk.top();
                sk.push(pre);
                sk.push(cur);
            }
            else if(ops[i] == "D"){
                sk.push(sk.top()*2);
            }
            else if(ops[i] == "C"){
                sk.pop();
            }
            else{
                sk.push(stoi(ops[i]));
            }
        }
        while(!sk.empty()){
            ans += sk.top();
            sk.pop();
        }
        return ans;
    }
};
```