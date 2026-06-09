### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int add(int a, int b) {
        while(b != 0)  //b==0说明已经无法进位了
        {
            int temp = (a ^ b);  //相加
            b = ((unsigned int)(a & b) << 1);  //进位，注意：C++不支持负值左移！！这里要加上unsigned int
            a = temp;
        }
        return a;
    }
};
```