使用一个栈来保存操作数，遇到操作符号就弹出栈顶元素和次栈顶元素，进行算术操作，将计算结果入栈。

```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        std::stack<int> _opnum;
        for(auto& c : tokens){
            // 正数
            if((0x30 <= c[0]) & (c[0] <= 0x39)) {
                int sum = 0;
                for(char& d : c) sum = sum*10 + (d-0x30);
                _opnum.push(sum);
            }
            //负数，但不是负号
            else if(c[0] == '-' & c.size() != 1) {
                int val =0;
                for(int i=1; i<c.size(); i++) val = val*10 + c[i]-0x30;
                _opnum.push(0-val);
            }
            else
            {
                //在这里就要执行相应的操作，由于都是二元操作数，
               // 因此都需要弹出栈中的两个元素
                int _2rd = _opnum.top(); _opnum.pop(); //第二个操作数
                int _1st = _opnum.top(); _opnum.pop(); //第一个操作数
                // 判断是哪个算术操作
                switch(c[0]){
                    case '+' : _opnum.push( _1st + _2rd); break;
                    case '-' : _opnum.push( _1st - _2rd); break;
                    case '*' : _opnum.push( _1st * _2rd); break;
                    case '/' : _opnum.push( _1st / _2rd); break;
                }
            }
        }
        return _opnum.top();
    }
};
```
