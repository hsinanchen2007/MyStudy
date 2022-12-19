1.每一轮遇到运算符，则优先计算* /，在deque后端计算
2.从deque前端计算+ -
```
class Solution {
public:
    int calculate(string s) { 
        for (int i = 0 ; i < s.size(); ++i) {
            if (s.at(i) == '+') {
                calcOp();
                ops.push_back('+');
            } else if (s.at(i) == '-') {
                calcOp();
                ops.push_back('-');
            } else if (s.at(i) == '*') {
                calcOp();
                ops.push_back('*');
            } else if (s.at(i) == '/') {     
                calcOp();
                ops.push_back('/');
            } else if (s.at(i) >= '0' && s.at(i) <= '9') {
                ss << s.at(i);
            }
        }
        calcOp();
        
        while (!ops.empty()) {
            char op = ops.front();
            ops.pop_front();
            
            int data = opDatas.front();
            opDatas.pop_front();
            int anotherData = opDatas.front();
            opDatas.pop_front();
            switch (op) {
                case '+' :
                    {
                        int result = anotherData + data;
                        opDatas.push_front(result);
                        break;
                    }
                case '-' :
                    {
                        int result = data - anotherData;
                        opDatas.push_front(result);
                        break;
                    }
                case '*' :
                    {
                        int result = anotherData * data;
                        opDatas.push_front(result);
                        break;
                    }
                case '/' :
                    {
                        int result = data / anotherData;
                        opDatas.push_front(result);
                        break;
                    }
            }
        }
        
        return opDatas.front();
    }
    
private:
    void calcOp() {
        int data = 0;
        ss >> data;
        opDatas.push_back(data);
        ss.clear(); 
        cout << data << endl;
        
        if (!ops.empty() && (ops.back() == '*' || ops.back() == '/') && opDatas.size() >= 2) {
            char op = ops.back();
            ops.pop_back();

            int data = opDatas.back();
            opDatas.pop_back();
            int anotherData = opDatas.back();
            opDatas.pop_back();
            if (op == '*') {
                int result = anotherData * data;
                cout << "result *:" << result << endl;
                opDatas.push_back(result);
            } else {
                int result = anotherData / data;
                cout << "result /:" << result << endl;
                opDatas.push_back(result); 
            }
        }
    }
private:
    deque<int> opDatas;
    deque<char> ops;
    stringstream ss;
};
```
