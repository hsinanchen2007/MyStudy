### 解题思路
很简单的思路：
1.把string型的罗马字符转换成对应的值，放在一个int型数组里。
2.遍历数组：
    1.没有异常值，直接将数组求和，返回结果。
    2.有异常值（比如：IV，前一个数比后一个数小的情况），找到异常值的位置，然后对异常值的位置和位置+1的数进行特殊的处理即可。（具体看代码吧，有注释很容易了解）。

### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) {
        
        int romansize = s.size();       //获得string s的大小
        int intnum[100];                //创造一个足够大的int型数组用来装罗马数字对应的值

        //把罗马数字转换为对应的数值
        for (int i = 0; i < romansize; i++)         
        {
            switch (s[i])
            {
            case 'I':
            case 'i':	intnum[i] = 1;	break;
            case 'V':
            case 'v':	intnum[i] = 5;	break;
            case 'X':
            case 'x':	intnum[i] = 10;	break;
            case 'L':
            case 'l':	intnum[i] = 50;	break;
            case 'C':	
            case 'c':	intnum[i] = 100;	break;
            case 'D':
            case 'd':	intnum[i] = 500;	break;
            case 'M':
            case 'm':	intnum[i] = 1000;	break;
            default:
                break;
            }

        }
        
        int count = 0;              //设置一个计数器
        int locate[100];            //设置一个异常值（比如：IV这种）位置数组

        //获得异常值个数及位置
        for (int i = 1; i < romansize; i++)
        {
            if (intnum[i-1] < intnum[i])
            {
                locate[count] = i-1;
                count++;
            }
        }

        int result = 0;             //存放最终结果

        //没有异常值的情况处理
        if(!count)
        {
            for (int i = 0; i < romansize; i++)
            {
                result = result + intnum[i];
            }
        }

        //有异常值的情况处理
        int start_loc = 0;      //设置一个开始相加的开始位置
        if (count)
        {
            for (int j = 0; j < count; j++)
            {
                int i = start_loc;
                for (; i < locate[j]; i++)
                {
                    result = intnum[i] + result;
                }
                if (i < romansize - 1)
                {
                    result = result + intnum[i + 1] - intnum[i];
                    i += 2;
                }
                start_loc = i;
            }
            for (; start_loc < romansize; start_loc++)
		    {
			    result = result + intnum[start_loc];
		    }
            
        }
    return result;
    }
};