由题意可得，每一个合法比特串构造方式必定是唯一的，所以线性扫描即可

如果能扫描到最后一个元素，则必定为1比特字符，反之不是

代码：
```
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int len = bits.size();
        int flag = 0;
        while(flag < len) {
            if(flag == len - 1)
                return true;
            if(bits[flag])
                flag += 2;
            else
                flag++;
        }
        return false;
    }
};
```
