```
class Solution {
    int gcd(int a, int b){
        return !b ? a : gcd(b, a%b);
    }
    void cal(int& l_val, int& l_x, const string& equation, int l, int r){//求左边或者右边的系数和常数
        for(int i  = l; i < r; ++i){
            int val = 0, f_n = 0;
            if(equation[i] == '+' || equation[i] == '-'){
           //如果符号开头，则该常数项或者一次项的符号由负号的个数决定
                while(i < equation.size()){
                    if(equation[i] == '+');
                    else if(equation[i] == '-')++f_n;
                    else break;
                    ++i;
                }
                f_n &= 1; //负负得正
            }
            if(isdigit(equation[i])){//后面先跟了数字
                while(i < equation.size() && isdigit(equation[i])){//求出该数值
                    val = val * 10 + equation[i] - '0';
                    ++i;
                }
                if(f_n)val = -val;//前面的符号为－
                if(i < equation.size() && isalpha(equation[i]))l_x += val;//系数后面跟了x
                else {//只是常数项
                    l_val += val;
                    --i;
                }
            }
            else {//后面直接跟的x
                l_x += f_n ? -1 : 1;
            }
        }
    }
public:
    string solveEquation(string equation) {
        int n = equation.size(), i = 0;
        int l_val = 0, r_val = 0, l_x = 0, r_x = 0;
        while(equation[i] != '=')++i;//找到等号位置
        cal(l_val, l_x, equation, 0, i);//求解等式左边部分系数与常数
        cal(r_val, r_x, equation, i + 1, n);//求解等式左边部分系数与常数
        l_x -= r_x; //移项
        r_val -= l_val;
        if(!l_x && !r_val)return "Infinite solutions";//恒等式，有无穷解
        if(!l_x)return "No solution";//等式不成立
        if(l_x < 0){//保证x系数为正
            l_x = -l_x;
            r_val = -r_val;
        }
        r_x = gcd(l_x, abs(r_val));//求系数与常数的最大公约数，化简
        l_x /= r_x;
        r_val /= r_x;
        string lx;
        if(l_x != 1)lx = to_string(l_x);//x系数不为1，就要显示出来
        return  lx + "x=" + to_string(r_val); 
    }
};
```
