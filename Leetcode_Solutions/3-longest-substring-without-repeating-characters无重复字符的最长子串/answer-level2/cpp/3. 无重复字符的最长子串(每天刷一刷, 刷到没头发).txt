### 解题思路
此处撰写解题思路
解题思路(官方): 滑动窗口(发现使用指针相比int类型做索引和边界, 指针速度要快一些.)
### 代码

```cpp
class Solution {
public:
        
    int lengthOfLongestSubstring(string s) {

        //检查参数
        if(s.size() <= 1)
        {
            return s.size();
        }

        const char* str = s.data();//披着C++的外衣, 该程序本质是C语言

        //解题思路(官方): 滑动窗口(发现使用指针相比int类型做索引和边界, 指针速度要快一些.)

        int count = 0;//结果子串长度
        const char* end = str + s.size();//结束标记
        const char* left = str;//窗口左侧索引(包括)
        const char* right = str + 1;//窗口右侧索引(不包括)
        bool isFind = false;//标记是否向右扩大窗口范围
        const char* p = 0;//循环用指针

        //条件表示是否允许继续向右滑动
        while (right < end)
        {

            //寻找left ~ right + 1这段子串是否合法(这里+1是预先判断, 即可以保证left ~ right这段永远处于合法状态)
            p = left;
            while (p < right)
            {
                if (*p++ == *right)//如果有相同的字符(*right表示子串的下一个字符)
                {
                    left++;//窗口左侧收缩
                    isFind = true;//标记, 子串现在不合法
                    break; //java中使用break+标签的特殊用法, C++可以用goto语句, 直接跳到 p = left;这句执行, 这样就不需要isFind变量, 每次循环就可以省略一个if.
                }
            }
            
            if (isFind)//不合法
            {
                isFind = false;
                continue;//开始下个循环
            }

            right++;//向右滑动(程序到达这里表示从left一直到right自增后的这段是合法的)

            if (count < right - left)//如果当前记录的长度比现有合法长度短
            {
                count = right - left;//记录当前长度
            }
        }

        return count;
    }
};
```