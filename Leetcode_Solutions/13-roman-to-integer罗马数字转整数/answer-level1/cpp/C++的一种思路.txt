### 解题思路
![Annotation 2020-03-31 165604.png](https://pic.leetcode-cn.com/d658ed1342c6b4c1d6d7c7ab783e905f6f7b1dd5002bcb90f3deb30efb76ad0b-Annotation%202020-03-31%20165604.png)
利用switch语句对每种情况判断返回相应的数值，循环遍历字符串，比较当前字符和后面一个字符所对应的数字大小，如果前者小于后者那么就用总值减去当前值，否则就加上当前值。
另外switch语句比Map要快得多。

### 代码

```cpp
class Solution {
public:
    int convert(char c){
        switch(c){
            case 'I': return 1;
            break;
            case 'V': return 5;
            break;
            case 'X': return 10;
            break;
            case 'L': return 50;
            break;
            case 'C': return 100;
            break;
            case 'D': return 500;
            break;
            case 'M': return 1000;
            default: return 0;
        }
    }
    int romanToInt(string s) {
        int curr = 0, next = 0,res = 0;
        //建立映射
        if(s.length() < 2) return convert(*(s.begin()));
        for(auto it = s.begin() + 1; it != s.end(); it++)
        {
            curr = convert(*(it-1));
            next = convert(*(it));
            curr < next ? res -= curr : res += curr;
        }
        return res + next;
    }
};
```