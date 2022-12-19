### 解题思路
这是我目前做过的中等题中，最简单的一道了，有个小坑就是要注意的就是op两边操作数的方向。
另外利用stringstream来进行string到int的转换。

执行用时 24ms 内存消耗 10.6MB


### 代码

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty()) return 0;
        stack<int> numst;
        stringstream ss;
        

        for(int i = 0;i<tokens.size();++i)
        {
            string c = tokens[i] ;
            if(c == "+"||c == "-"||c == "*"||c == "/" ) 
            {
                int temp1 = numst.top(); numst.pop();
                int temp2 = numst.top(); numst.pop();
                int temp3 = 0;
                if(c == "+") {temp3 = temp1+temp2; numst.push(temp3);}
                else if(c == "-") {temp3 = temp2-temp1; numst.push(temp3);}
                else if(c == "*") {temp3 = temp1*temp2; numst.push(temp3);}
                else{temp3 = temp2/temp1; numst.push(temp3);}
            }
            else
            {
            int number;
            ss.clear();
            ss<<c;
            ss>>number;
            
            numst.push(number);
            }
        }
        return numst.top();

        

    }
};
```