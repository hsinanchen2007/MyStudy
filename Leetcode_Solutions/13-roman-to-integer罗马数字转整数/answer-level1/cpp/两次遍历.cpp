### 解题思路
创建一个int类型数组，大小和字符串一样大。第一次遍历先将所有字符对应的大小存储在int数组里面。
然后第二次遍历，如果某个值比它下一个值要小，那么这个值就要减去。
### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        int length = s.size();
        int a[length];
        if(length == 0)
            return 0;
        int num = 0;
        for(int i = 0; i < length; i++){
            if(s[i] == 'I')
                a[i] = 1;
            else if(s[i] == 'V')
                a[i] = 5;
            else if(s[i] == 'X')
                a[i] = 10;
            else if(s[i] == 'L')
                a[i] = 50;
            else if(s[i] == 'C')
                a[i] = 100;
            else if(s[i] == 'D')
                a[i] = 500;
            else
                a[i] = 1000;
        }
        for(int i = 0; i < length; i++){
            if(i+1 < length && a[i+1] > a[i])
                a[i] *= -1;
            num += a[i];
        }
    return num;
    }
};
```