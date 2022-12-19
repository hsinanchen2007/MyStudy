### 解题思路
将int转为string，从左边第一个‘6’改成‘9’，在转回int。

![image.png](https://pic.leetcode-cn.com/d87e43e7d85592adcb6405bdb51791533e7a3208ecfa507f3c2bb86bb7926b23-image.png)

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        string str = to_string(num);
        for(int i=0;i<str.length();i++)
        {
            if(str[i] == '6'){
                str[i] = '9';
                break;
            }
        }
        return stoi(str);
    }
};
```