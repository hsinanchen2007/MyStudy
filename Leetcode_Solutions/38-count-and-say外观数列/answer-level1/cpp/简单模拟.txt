**题意已经很明显了，第i行就是依次输出第i-1行的数字个数**
n <= 30 直接模拟就没得问题
一个pre变量记录上一个字符，如果当前字符等于前一个字符，记录个数的变量sum++,
不相等的时候就是当前字符串加上个数sum,再加上上一个字符
需要注意当循环结束后需要把最后一个加上

```
class Solution {
public:
    string countAndSay(int n) {
        string x[35];
        x[1] = "1";
        x[2] = "11";
        int i,j;
        for(i = 3; i <= n; i++)
        {
            char pre;
            int sum = 1;
            for(j = 0; j < x[i-1].length(); j++)
            {
                if(j == 0)
                   pre = x[i-1][0];
                else if(x[i-1][j] == pre){
                    sum++;  //如果当前字符等于前一个字符，记录个数的变量sum++
                }
                else{
                    //不相等的时候就是当前字符串加上个数sum,再加上上一个字符
                    //然后更新pre,并将sum记为1
                    string temp = to_string(sum);
                    x[i] += temp;
                    x[i] += x[i-1][j-1];
                    pre = x[i-1][j];
                    sum = 1;
                }
            }
            string temp = to_string(sum);
            x[i] += temp;
            x[i] += x[i-1][j-1];
        }
        return x[n];
    }
};

```
