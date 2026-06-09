# C++数字电路解法
**阅读本题解需要拥有的先验知识：数字电路（主要是一位全加器）**
本解法暂无实用价值，仅仅为了showing off。

值得注意的点是：写电路时大部分时间都会写非阻塞赋值，而编程语言逻辑执行顺序类似阻塞赋值，所以需要注意在循环中提前记录下会变化的值。

```c++
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
            string tmp=b;
            b=a;
            a=tmp;
        }
        
        int i = a.size()-1;
        int j = b.size()-1;
        int carryin = 0;
        while(j >= 0){
            int ai = a[i]-'0';
            int bj = b[j]-'0';
            a[i] = ai ^ bj ^ carryin + '0';
            carryin = (ai & bj) | (ai & carryin) | (carryin & bj);
            
            i-=1;
            j-=1;
        }
            
        while(i >= 0){
            int ai = a[i]-'0';
            a[i] = ai ^ carryin + '0';
            carryin = ai & carryin;
            
            i-=1;
        }
        
        return carryin == 1 ? to_string(carryin) + a : a;
    }
};
```
