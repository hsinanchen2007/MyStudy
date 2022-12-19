### 解题思路
（1）除去字符串中空格
```
        auto it  = find(s.begin(), s.end(), ' ');
        while(it!=s.end()){
            s.erase(it);
            it  = find(s.begin(), s.end(), ' ');
        }
```
（2）用两个容器 ：vector<char> op; vector<int> num; 分别保存数，和符号
    其中需要注意一点：需要判断数是否大于计算机能表示的最大数！
```
        int temp = 0;
        for(char i:s){
            if(i=='+'||i=='-'||i=='*'||i=='/'){
                op.emplace_back(i);
                num.emplace_back(temp);
                temp = 0;
            }
            else{
                if(temp>INT_MAX/10||(temp==INT_MAX/10&&i-'0'>INT_MAX%10)){
                    temp = INT_MAX;
                }else{
                    temp = temp * 10 + (i - '0');
                }
                 
            }
        }
        num.emplace_back(temp);
```
（3）根据运算法则，先计算乘/除的结果，
```
        auto it_mul = find(op.begin(),op.end(),'*');
        auto it_div = find(op.begin(),op.end(),'/');
        while(it_mul!=op.end()||it_div!=op.end()){
            // 注意需要判断*和/的先后出现的位置，先出现的先计算
            int div = distance(op.begin(), it_div);
            int mul = distance(op.begin(), it_mul);
            if(mul>div){
                int div_result = num[div] / num[div+1];
                num.erase(num.begin()+div, num.begin()+div+2);
                num.insert(num.begin()+div, div_result);
                op.erase(op.begin()+div);
            }else{
                int mul_result = num[mul] * num[mul+1];
                num.erase(num.begin()+mul, num.begin()+mul+2);
                num.insert(num.begin()+mul, mul_result);    
                op.erase(op.begin()+mul);          
            }   
         it_mul = find(op.begin(),op.end(),'*');
         it_div = find(op.begin(),op.end(),'/');                    
        }
```
（4）之后容器op中只有加/减号，可以从左到右依次计算：
```
        int sum = num[0];
        for(int i=0;i<op.size();i++){
            switch(op[i]){
                case '+':
                    sum += num[i+1];
                    break;
                case '-':
                    sum -= num[i+1];
                    break;
            }
        }
        return sum;
```



### 代码

```cpp
class Solution {
public:
    int calculate(string s) {
        auto it  = find(s.begin(), s.end(), ' ');
        while(it!=s.end()){
            s.erase(it);
            it  = find(s.begin(), s.end(), ' ');
        }
        vector<char> op;
        vector<int> num;
        int temp = 0;
        for(char i:s){
            if(i=='+'||i=='-'||i=='*'||i=='/'){
                op.emplace_back(i);
                num.emplace_back(temp);
                temp = 0;
            }
            else{
                if(temp>INT_MAX/10||(temp==INT_MAX/10&&i-'0'>INT_MAX%10)){
                    temp = INT_MAX;
                }else{
                    temp = temp * 10 + (i - '0');
                }
                 
            }
        }
        num.emplace_back(temp);

        auto it_mul = find(op.begin(),op.end(),'*');
        auto it_div = find(op.begin(),op.end(),'/');
        while(it_mul!=op.end()||it_div!=op.end()){
            int div = distance(op.begin(), it_div);
            int mul = distance(op.begin(), it_mul);
            if(mul>div){
                int div_result = num[div] / num[div+1];
                num.erase(num.begin()+div, num.begin()+div+2);
                num.insert(num.begin()+div, div_result);
                op.erase(op.begin()+div);
            }else{
                int mul_result = num[mul] * num[mul+1];
                num.erase(num.begin()+mul, num.begin()+mul+2);
                num.insert(num.begin()+mul, mul_result);    
                op.erase(op.begin()+mul);          
            }   
         it_mul = find(op.begin(),op.end(),'*');
         it_div = find(op.begin(),op.end(),'/');                    
        }
      
        int sum = num[0];
        for(int i=0;i<op.size();i++){
            switch(op[i]){
                case '+':
                    sum += num[i+1];
                    break;
                case '-':
                    sum -= num[i+1];
                    break;
            }
        }
        return sum;
    }
};
```