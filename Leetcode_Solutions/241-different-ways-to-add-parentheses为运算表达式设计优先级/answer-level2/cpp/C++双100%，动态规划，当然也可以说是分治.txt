### 解题思路
$caculate$函数用来进行运算，输入符号，第一个数，第二个数。
$symbol$数组用来存储符号，$number$数组用来存储数字，$n$表示所有数字的数量。
状态方程$f[i][j]$表示从第$i$个数字开始，到第$j$个数字的表达式当中所有组合的结果。
对于$i \in [0,n-1]$，$f[i][i]=number[i]$。
状态转移可以简单写成$f[i][j]=\sum_{k=i}^{j}caculate(symbol[k],f[i][k],f[k+1][j])$

动态规划的时间复杂度$O(n^3)$，合并两个结果的时间复杂度是$O(n!^2)$
最终的时间复杂度是$O(n!^{2}n^3)$

### 代码

```cpp
class Solution {
private:
    inline int caculate(char symbol,int a,int b){
        if(symbol == '+'){
            return a+b;
        }
        if(symbol == '-'){
            return a-b;
        }
        return a*b;
        
    }
public:
    vector<int> diffWaysToCompute(string input) {
        //字符串预处理
        vector<char> symbol;
        vector<int> numbers;
        unsigned int number=0;
        for(size_t i=0;i<=input.length();i++){
            if(input[i]>='0' && input[i]<='9'){
                number*=10;
                number+=input[i]-'0';
                continue;
            }
            else{
                numbers.push_back(number);
                number=0;
            }
            if(input[i]=='-'||input[i]=='+'||input[i]=='*'){
                symbol.push_back(input[i]);
            }
        }
        //状态方程
        //f[i][j]表示从第i个符号开始，到第j个符号的表达式当中所有组合的结果
        vector< vector< vector<int> > > f;
        const size_t nums=numbers.size();
        //初值
        //f[i][i] = number[i];
        for(size_t i=0;i<nums;i++){
            f.push_back(vector< vector<int> >(nums));
            f[i][i].push_back(numbers[i]);
        }
        //状态转移
        for(size_t window=1;window<nums;window++){
            for(size_t i=0,j=window;j<nums;i++,j++){
                for(size_t k=i;k<j;k++){
                    for(size_t left=0;left<f[i][k].size();left++){
                        for(size_t right=0;right<f[k+1][j].size();right++){
                            f[i][j].push_back(caculate(symbol[k],f[i][k][left],f[k+1][j][right]));
                        }
                    }
                    
                }
            }
        }
        numbers = f[0][nums-1];
        sort(numbers.begin(),numbers.end());
        return numbers;
    }
};
```