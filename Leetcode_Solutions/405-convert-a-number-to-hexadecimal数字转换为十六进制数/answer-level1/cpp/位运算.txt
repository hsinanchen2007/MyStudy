### 解题思路
+ 将参数num强转为unsigned int类型 n ，每次右移4位，并和0x0f做与运算（&），获取最后四个二进制位，并转换为 '0' - 'f' 之间的字符，并不断拼接

+ 结束条件为 最大右移8次,且n等于0（这个条件可以去掉前缀0）
### 代码

```cpp
class Solution {
  public:
    string toHex(int num) {
        unsigned int n = (unsigned int)n;
        char arr[] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string str;
        for(int i = 0; i < 8; ++i) {
            unsigned char ret = num & 0x0f;
            num >>= 4;
            str = arr[ret] + str;
            if(num == 0) {
                break;
            }
        }
        return str;
    }
};

```