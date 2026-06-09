### 解题思路
我们把下标按照z字形排列之后，可以发现一个规律：

0        8                     16
1      7   9                15    17 
2    6       10          14          18  
3  5             11   13          
4                  12         

可以发现规律：

第 i 行两个下标的元素之间的距离在（2 * numRows - （i+1）* 2） 和 （i * 2）之间摇摆。
（i 从0开始）

用奇数偶数来模拟摇摆。

### 代码

```cpp
class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        if(numRows == 1) return s;
        
        string ans = "";

        for(int i = 0; i < numRows; i++)
        {
            int odd = 2 * numRows - i * 2 - 2,  even = i * 2;

            int current = i, last = -1, accum = 1;
            
            while(current < s.length())
            {
                if(current != last)
                    ans += s[current];

                last = current;

                if(accum++ & 1)
                    current += odd;
                else
                    current += even;
                
            }
        }

        return ans;
    }
};
```