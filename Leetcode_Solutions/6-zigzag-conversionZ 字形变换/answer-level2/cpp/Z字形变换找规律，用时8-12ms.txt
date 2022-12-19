
初次写题解，有些做的不好的地方多多包涵。大神轻喷。以下是我智商触顶所能想到的解题思路了。

### 解题思路
首先手工将numRows=1,2,3,4的情况下，字符对应Z字形图案的哪一行写下来。

![436104357346232952.jpg](https://pic.leetcode-cn.com/541ad76f95fcf80fcccef59364b3c463815113819690fb69fe2ce347bdde8e35-436104357346232952.jpg)




在这里，我先将Z字形图案的行号定义为两种，
1. 无状态数，0和numRows-1，它们在数列中相隔固定的距离;例如上图中numRows=4时，0和3为无状态数，与下一个相同的数的距离是固定的。
2. 有状态数，非1情况的都是有状态数。例如上图中numRows=4时，1和2为有状态数。此处状态又分为上升状态和下降状态。图中的①和②箭头分别代表上升状态和下降状态的范围。


# 观察可以知道，有状态数的状态初始都是上升态，然后切换到下降态，不断互相变换。
位于上升态时，下一同行数与自身的位置的距离为(numRows-row-1)*2；
位于下降态时，下一同行数与自身的位置的距离为2n；

# 对于无状态数，分析很简单。
位于无状态时，下一同行数与自身的位置的距离是(numRows-1)*2；

到最后还得处理特殊情况numRows==1的情况，直接return s即可。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {

        int i;
        int row=0;
        string result;

        if(numRows==1)return s;

        i=0;
        while(i<s.length()){
            result+=s[i];
            i+=(numRows-1)*2;
        }

        for(row=1;row<numRows-1;row++){
            i=row;
            while(i<s.length()){
                result+=s[i];
                i+=(numRows-row-1)*2;

                if(i<s.length()){
                    result+=s[i];
                    i+=row*2;
                }
                    
            }
        }

        i=numRows-1;
        while(i<s.length()){
            result+=s[i];
            i+=(numRows-1)*2;
        }




        return result;


    }
};
```