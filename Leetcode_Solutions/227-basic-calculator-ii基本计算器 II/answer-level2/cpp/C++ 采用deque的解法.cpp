虽然本题可以用stack解决。但deque双端插入、删除的性质使得想法更加直接和简单。上代码：
```
class Solution {
public:
    int calculate(string s) {
        deque<char> opors;
        deque<int> opands;
        
        int len = s.size();
        bool tag = false;
        for(int i=0;i<len;i++){
            if(s[i] == '+' || s[i] == '-'){
                opors.push_back(s[i]);
            }else if(s[i] == ' '){
                continue;
            }else if(s[i] == '*' || s[i] == '/'){
                tag = true;
                opors.push_back(s[i]);
            }else{
                int num = s[i] - '0';
                for(int j=i+1;j<len;j++){
                   if(isalnum(s[j])){
                       num = num * 10 + (s[j]-'0');
                       i = j;
                   }else{
                       i = j - 1;
                       break;
                   }
                }
                
                if(tag){
                    char op = opors.back();
                    opors.pop_back();
                    int num2 = opands.back();
                    opands.pop_back();
                    int ret = op == '*' ? num2 * num : num2 / num;
                    opands.push_back(ret);
                    tag = false;                    
                }else{
                    opands.push_back(num);
                }
                
                
            }
        }
        
        while(!opors.empty()){
            char op = opors.front();
            opors.pop_front();
            int num1 = opands.front();
            opands.pop_front();
            int num2 = opands.front();
            opands.pop_front();
            int ret = op == '+' ? num1 + num2 : num1 - num2;
            opands.push_front(ret);
        }
        
        return opands.back();
    }
};
```
