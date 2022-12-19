### 解题思路
找出字符串数组中最小的那个元素的角标MinFootMark和元素字符串长度MinLength。之后比较都基于这两个数。

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int VectorLength = strs.size();//定义字符串数组的长度
    if(VectorLength == 1)
    {
        return strs[0];
    }//当字符串数组中只有一个字符串的时候直接输出该字符串

    int MinFootMark = 0; int MinLength = 0;

    for (int i = 0; i < VectorLength; i++)
    {
        if (i > 0)
        {
            MinLength = MinLength < strs[i].length() ? MinLength : strs[i].length();
            MinFootMark = MinLength < strs[i].length() ? (i-1) : i;
        }
        else
        {
            MinLength = strs[i].length();
            MinFootMark = i;
        }
    }
    //找出字符串数组中最小的那个元素的角标MinFootMark和元素字符串长度MinLength。

    int CountNum = 0;//统计比较到了第几个字符
    string Result = "";
    while (CountNum < MinLength)
    {
        bool IsAllCharSame = true;//标记当前的一轮比较中是否字母完全一致
        char CurrentCompareChar = strs[MinFootMark][CountNum];//将用于比较的标志字符初始化为最小字符串中的第CountNum个字符
        for (int i = 0; i < VectorLength ; i++)
        {
            
            if (CurrentCompareChar == strs[i][CountNum])
            {
                //IsAllCharSame = true;
                continue;
            }
            else
            {
                IsAllCharSame = false;
                break;
            }
               
        }//遍历strs用每个元素的第CountNum个字符与CurrentCompareChar标志字符比较，一旦有不同就会将IsAllCharSame设置为false
        if (IsAllCharSame)
        {
            Result += CurrentCompareChar;
        }else
        {
            break;
        }
        //如果IsAllCharSame为True则把该字符添加到结果字符串中

        CountNum++;
    }
    return Result;
    }
};
```