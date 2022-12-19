### 解题思路
我们定义一个一个字符串数组，用来存放每行的数字。最后将字符串数组连接起来输出。
存放的思路：
    首先外循环遍历每个字符串中的字符{
        将第一个字符串存放到第一个字符串中。
        如果当前的行数是第一行或最后一行，转向。
            如果是第一行，往后的行应该+1；
            如果是最后一行，往后的行应该-1；
            可以通过设置一个bool值转向。没次遇到第一行或最后一行，布尔值取反。并让下一次的行树根据bool值的真假执行+1或-1操作。
    }


### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) { 
        //应该取值字符串和行数的最小值。最多能提供字符串个数个行，这个时候是一个n*1维的值。
        int n = numRows < s.size()? numRows :s.size();
        //如果行数为1的话直接返回。
        if(n == 1) return s;

        vector<string> res(n);
        //用来确定转向
        bool down = false;
        //用来确定转向后的行数        
        int row = 0;
        //关键代码段
        for(int i = 0; i < s.size(); i++){   
            //首先将第一个元素装如res[0]的第一个位置。
            res[row].push_back(s[i]);   
            //判断转向    
            if(row== 0 || row == n-1){
                down = !down;                
            }
            //判断转向后的行数。
            row += down?1:-1;
        }
        //定义一个ret用来存放最终的数组。
        string ret = "";
        for(int i = 0; i < n; i++){
            //输出ret。
            ret += res[i];
        }
        return ret;

    }
};
```