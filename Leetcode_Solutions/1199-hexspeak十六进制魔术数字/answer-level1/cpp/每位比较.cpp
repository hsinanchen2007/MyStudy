### 解题思路
一开始把事情想复杂了-以为是转换成123的数字，然而并不是就只是判断
还把O打成了0
笑哭
### 解题
- 用long long 保存string转换来的字符串不然会越界
- 用1对可能成为合法数据的数据进行转换(2,3,4,5)
- 如果一定是非法数据(6,7,8,9)返回"ERROR"
- 依次弹出每位数据
### 代码

```cpp
class Solution {
public:
    string toHexspeak(string num) {
        // 转换为十六进制的字符串
        // 假设仅有0和1是合法数字
        // 2 3 4 5 6 7 8 9
        // 2 3 4 5 可以变成合法数字
        // 6 7 8 9为非法数字
        // 1,B是个神奇的数字可以把非法变为合法
        long long n = atoll(num.c_str()); //转换
        string rst;
        int x, y;
        //stringstream ss;
        //cout<< std::hex << 747823223228 << endl;
        while(n>0)
        {
            x = n%16;
            if(x > 5 && x < 10) return "ERROR";
            else if(x == 0) {rst += 'O';n/=16;}
            else if(x == 1) {rst += 'I';n/=16;}
            else if(x > 9) {rst += getnumbertostr(x);n/=16;}
            else{
                n /= 16;
                y = n%16;
                if(y == 1)
                {
                    rst += getnumbertostr(x + y*10);
                }
                else return "ERROR";
                n /= 16;
            }
            
        }// 逆序       
        reverse(rst.begin(), rst.end());
        return rst;
    }
    string getnumbertostr(int x)
    {
        switch(x)
        {
            case 10: return "A";
            case 11: return "B";
            case 12: return "C";
            case 13: return "D";
            case 14: return "E";
            case 15: return "F";
            default: return "ERROR";
        }
    }
};
```