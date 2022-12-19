### 解题思路
话说，如果是面试或者笔试的时候，真的有时间去用状态机解决这个问题吗？

### 代码

```cpp
class Solution {
public:
    bool isNumber(string string) {
        if(string == "") return false;
        bool decimal = false,hasE = false;
        int left = 0;int right = string.size() - 1;
        int num = 0;
        while(left <= right && string[left] == ' ') left++;
        while(left <= right && string[right] == ' ') right--;
        //字符串为空
        if(left > right) return false;
        //如果第一个是正负号 跳过
        if(string[left] == '+' || string[left] == '-') left++;

        for(int i = left;i <= right;i++)
        {
            if(string[i] >= '0' && string[i] <= '9')
            {
                num = 1;
            }else if(string[i] == '.')
            {
                if(hasE || decimal) return false;
                decimal = true;
            }else if(string[i] == 'e' || string[i] == 'E')
            {
                //只能有一个e 前后有数字一个字母 
                if(hasE || !num || (i == right) ) return false;
                if(string[i + 1] == '+' || string[i + 1] == '-') i++;
                hasE = true;
                num = 0;//e后面必须有数字
            }else  
            {
                return false;
            } 
        }
        return num;  
    }
};
```