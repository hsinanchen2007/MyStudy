### 解题思路
![2020-03-31 16-35-32屏幕截图.png](https://pic.leetcode-cn.com/66c9ff7dfc521e9a2f191d5c3eea5d036c1a48aa93de144e6ecd88a70197bd16-2020-03-31%2016-35-32%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)

优化点：
1.根据长度的奇偶
2.减少size()的执行次数
3.若栈顶元素不匹配，返回false

### 代码

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> k;
        if(s.size() % 2 != 0){
            return false;
        }
        int len = s.size();
        for(int i=0; i<len; i++){
            if(k.empty()){
                k.push(s[i]);
            }else{
                char top = k.top();
                if(s[i] == ')'){
                    if(top != '('){
                        return false;  
                    }
                    k.pop();
                }else if(s[i] == '}'){
                    if(top != '{'){
                        return false;
                    }
                    k.pop();
                }else if(s[i] == ']' ){
                    if(top != '['){
                        return false;
                    }
                    k.pop();
                }else{
                    k.push(s[i]);
                }
            }
        }        
        return k.empty();
    }
};
```