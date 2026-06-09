### 解题思路

#### 模拟二进制操作

根据题目要求模拟二进制的除2，加1操作

1. 将数字反转，下标index = 0开始
2. 当前位为0时，index++，ans++
3. 当前位为1时，将当前位变为0，并且将下一位加1，直到下一位为1。例： 110 ===> 001
4. 重复2,3直到结束
5. 答案：ans + 最后一位的进位


### 代码

```cpp
class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(),s.end());
        int len = s.length();
        s[len] = '0';
        int ans = 0;
        int index = 0;
        while(index < len - 1)
        {
            if(s[index] == '0'){
                ans += 1;
                index ++;
            }else if(s[index] == '1'){
                int i = index;
                s[index] = '0';
                while(i < len && s[i+1] == '1'){ //找到下一位为0的数
                    s[++i] = '0'; //将  1 都变成 0
                }
                s[i+1] = '1'; //进1
                ans += 1;
            }
        }
        return ans + s[len] - 48;
    }
};
```

![WX20200405-150335.png](https://pic.leetcode-cn.com/a26943d312190d2de5f87153977c4f55e712021f51eb7ceacbf1811cdb967569-WX20200405-150335.png)
