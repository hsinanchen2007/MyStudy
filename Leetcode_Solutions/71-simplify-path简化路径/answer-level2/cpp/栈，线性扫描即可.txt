### 解题思路
使用栈简化路径，通过下标，依次扫描每个字符，根据规则，进行简化！具体做法如下：
1. 若当前下标的字符为`/`，判断栈顶的字符否也为`/`,若是，则说明`/`重复，跳过，否则将该`/`入栈
2. 若当前下标的字符为`.`，看以该字符开头的串是`.`，`..`，还是`...hidden`这样的路径名，对应各自规则处理
3. 其他字符则入栈
4. 将栈中所有字符出栈，得到结果字符串的反转字符串。再经过反转之后即可得到原始字符串

### 代码

```cpp
class Solution {
public:
    string simplifyPath(string path) {
        stack<char> sk;
        string res;
        int i = 0;
        while(i<path.size()){
            // 斜杠，如果能和栈顶组成两个斜杠，则多余，否则入栈
            if(path[i] == '/'){
                if(!sk.empty() && sk.top() == '/'){
                    i++;
                    continue;
                }
                sk.push(path[i++]);
            }
            // 判断是为.这样的当前路径，还是..这样的上一层路径，或是 ...hidden这样的一个合法路径
            else if(path[i] == '.'){
                int j = i;
                string temp =  ".";
                while(j + 1< path.size() && path[j+1] != '/'){
                    j++;
                    temp += path[j];
                }

                // 为当前路径.
                if(j-i == 0) i++;
                // 为上一层路径..
                else if(j-i == 1){
                    if(sk.size() > 1) sk.pop();
                    while(sk.size() > 1 && sk.top() != '/') sk.pop();
                    i = j+1;
                }
                // 一个合法子路径
                else{
                    for(char c: temp) sk.push(c);
                    i=j+1;
                }
            }
            //其他字符，入栈
            else{
                sk.push(path[i++]);
            }
        }
        if(sk.size() > 1 && sk.top() == '/') sk.pop();
        while(!sk.empty()) {
            res += sk.top();
            sk.pop();
        }
        //反转得到结果字符串
        int len = res.size();
        int mid = len / 2;
        i = 0;
        while(i < mid){
            char temp = res[i];
            res[i] = res[len-i-1];
            res[len-i-1] = temp;
            i++;
        }
        return res;
    }
};
```