### 解题思路
1. 用栈来存储**相邻但是不重复**的项
2. 初始时，栈为空，将第一个元素入栈，后面的每个元素都和栈顶比较，若和栈顶相同，将栈顶元素出栈，直到扫描结束
3. 扫描结束后，将栈中的剩余元素出栈，得到的是结果字符串的反转字符串。只要把当前字符串反转即得结果

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string S) {
        stack<int> sk;
        string ans = "";
        for(auto c: S){
            if(!sk.empty()){
                if(sk.top() == c) sk.pop();
                else sk.push(c);
            }
            else sk.push(c);
        }
        while(!sk.empty()){
            ans += sk.top(); sk.pop();
        }
        int len = ans.size(); int mid = len / 2;
        int i = 0;
        while(i<mid){
            char temp = ans[i];
            ans[i] = ans[len-i-1];
            ans[len-i-1] = temp;
            i++;
        }
        return ans;
    }
};
```