***
## 解法一（规则判断）
思路：对字符串的每个字符进行检测，保证每个字符满足要求，并且满足其出现的基本规则，规则如下：
1. **正负号**，仅能出现在开头位置（整个字符串开头，或者科学表示法的指数部分开头）
2. **小数点**，仅能出现一次，且不能出现在科学表示法的指数部分
3. **e**，科学表示法仅能出现一次，且前后都要有数值
4. **数值**，需要以数值进行结尾
5. **其它任意符号**，都是异常字符

* 时间复杂度：O(n)
* 空间复杂度：O(1)

```csharp
public class Solution {
    public bool IsNumber(string s) {
        s = s.Trim();
        char t;
        bool eFlag = false,pFlag = false,numberFlag = false;
        bool startFlag = true;
        for(int i=0;i<s.Length;i++)
        {
            t = s[i];
            if(t >= '0' && t <= '9')
            {//数字标识
                numberFlag = true;
            }
            else if(t == '+' || t == '-')
            {//符号仅能出现在开头位置
                if(!startFlag)
                {
                    return false;
                }
                numberFlag = false;
            }
            else if(t == '.')
            {
                if(pFlag || eFlag)
                {//小数点仅能出现一次，且不能出现在e后面
                    return false;
                }
                eFlag = true;
            }
            else if(t == 'e')
            {
                if(!numberFlag || pFlag)
                {//e前面一定要有数值，且仅能出现一次
                    return false;
                }
                pFlag = true;
                startFlag = true;
                numberFlag = false;
                continue;
            }
            else
            {//其他任何字符出现都失败
                return false;
            }
            startFlag = false;
        }
        return numberFlag;//一定以数字结尾
    }
}
```
***
## 解法二（有限状态机）
思路：基于解法一，改用状态机的写法，不同的元素分别对应不同的状态，直到所有元素遍历完，如果状态还是正常即为有效数字，定义了以下8种状态以及状态变迁表：
1. 等待输入的起始状态
2. 起始符号状态
3. 输入数字状态
4. 起始小数点状态
5. 小数点之后输入数字状态
6. 输入指数e状态
7. 指数e之后输入符号状态
8. 指数e之后输入数字状态

之前状态|0-9|小数点|e|+-|其它字符
----- | -----| ----| ----| ---| ---
1|3|4|-1|2|-1
2|3|4|-1|-1|-1
3|3|5|6|-1|-1
4|5|-1|-1|-1|-1
5|5|-1|6|-1|-1
6|8|-1|-1|7|-1
7|8|-1|-1|-1|-1
8|8|-1|-1|-1|-1
另外，最终状态也需要根据情况进行分析，不是所有最终状态都是合格的，即8个状态中仅当结束时保持为部分状态表示有效数字，分别是3、5、8，结束时其它状态都表示无效数字。

```csharp
public class Solution {
    public int getIdx(char c)
    {
        int idx = 0;
        if(c >= '0' && c<= '9')
        {
            idx = 1;
        }
        else if(c == '.')
        {
            idx = 2;
        }
        else if(c == 'e')
        {
            idx = 3;
        }
        else if(c == '+' || c == '-')
        {
            idx = 4;
        }
        else
        {
            idx = 5;
        }
        return idx;
    }
    public bool IsNumber(string s) {
        s = s.Trim();
        int[,] statusList = new int[,]
        {   {1,3,4,-1,2,-1},
            {2,3,4,-1,-1,-1},
            {3,3,5,6,-1,-1},
            {4,5,-1,-1,-1,-1},
            {5,5,-1,6,-1,-1},
            {6,8,-1,-1,7,-1},
            {7,8,-1,-1,-1,-1},
            {8,8,-1,-1,-1,-1}
        };
        bool [] valid = new bool[8]{false,false,true,false,true,false,false,true};
        int status = 1;
        for(int i=0;i<s.Length;i++)
        {
            status = statusList[status-1,getIdx(s[i])];
            if(status < 0)
            {
                return false;
            }
        }
        return valid[status-1];
    }
}
```

***
## 解法三（分类判断）
思路：针对每一种数字类型进行单独判断，如果全部不满足即为不满足，数据类型有三类，整数、小数和指数。
1. **正整数**，可以用于判断，也可以仅用于中间状态，所有字符全是0-9的数字
2. **整数**，第一个是符号，其他全是正整数
3. **小数**，如果有符号，则只能在第一位，其他内容分小数点前后两部分，前后都是正整数，且可以有一边的内容为空
4. **指数**，以e为分界点分为前后两部分，两面可以是小数和整数，后面只能是整数
* 时间复杂度：O(n)
* 空间复杂度：O(1)
```csharp
public class Solution {

    public bool IsPositiveNumber(string s)
    {//仅有数字的正整数
        if(s.Length == 0) 
        {
            return false;
        }
        for(int i=0;i<s.Length;i++)
        {
            if(s[i]> '9' || s[i] < '0')
            {
                return false;
            }
        }
        return true;
    }

    public bool IsIntegral(string s)
    {//整数
        if(s.Length > 0 && (s[0] == '+' || s[0] == '-'))
        {
            return IsPositiveNumber(s.Substring(1));
        }
        
        return IsPositiveNumber(s);
    }

    public bool IsDecimal(string s)
    {//小数
        if(s.Length > 0 && (s[0] == '+' || s[0] == '-'))
        {
            s= s.Substring(1);
        }
        int idx = s.IndexOf('.');
        if(idx>=0)
        {//小数点前后都不带符号，且不同时为空
            return (idx==0 || IsPositiveNumber(s.Substring(0,idx))) 
                && (idx+1 == s.Length || IsPositiveNumber(s.Substring(idx+1))) 
                && (idx!= 0 || idx+1 != s.Length);
        }
        return false;
    }

    public bool IsExponent(string s)
    {//指数
        int idx = s.IndexOf('e');
        if(idx >= 0)
        {//前可以是小数或整数，后只能是整数
            string preStr = s.Substring(0,idx), postStr = s.Substring(idx+1);
            return (IsDecimal(preStr) || IsIntegral(preStr)) 
                && (IsIntegral(postStr));
        }
        return false;
    }
    public bool IsNumber(string s) {
        s = s.Trim();
        return IsIntegral(s) || IsDecimal(s) || IsExponent(s);
    }
}
```
