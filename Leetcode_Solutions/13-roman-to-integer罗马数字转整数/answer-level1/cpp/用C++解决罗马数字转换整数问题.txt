### 解题思路
此处撰写解题思路
使用for循环将每相邻的两个罗马数字进行比较：
（1）如果第一个数字小于第二个数字，则为题目中的6种特殊情况，则需要用大的数字减去小的数字；
     并且需要注意下标需要增加1。
（2）如果第一个数字大于第二个数字，则直接相加即可。

注意：当罗马字符串的长度为奇数或者偶数时结果也是不相同。
（1）当长度为偶数时，最后一个数无法配对，则直接相加即可；
（2）当长度为奇数时，则可以进行两两比较。

具体请阅读代码，比较清晰。
### 代码

```cpp
class Solution {
public:
    int romanToInt(string s) 
    {
        int size = s.size();
        int sum = 0;
        for(int i=0; i<size; i++)//每两个罗马数进行比较
        {
            char a = s[i];
            int num, num_1;
            switch(a)
            {
                case 'I': num = 1;break;
                case 'V': num = 5;break;
                case 'X': num = 10;break;
                case 'L': num = 50;break;
                case 'C': num = 100;break;
                case 'D': num = 500;break;
                case 'M': num = 1000;break;
            }
            if(i+1 == size) num_1 = 0;//当罗马数字长度为偶数时，最后一个数直接相加即可
            else
            {
                char b = s[i+1];
                switch(b)
                {
                    case 'I': num_1 = 1;break;
                    case 'V': num_1 = 5;break;
                    case 'X': num_1 = 10;break;
                    case 'L': num_1 = 50;break;
                    case 'C': num_1 = 100;break;
                    case 'D': num_1 = 500;break;
                    case 'M': num_1 = 1000;break;
                }
            }
            if(num<num_1)//如果小的数在前面，则为题目中的6种特殊情况之一
            {
                sum = sum + num_1 - num;
                i++;
            }
            else//否则，直接相加
                sum += num;
        }
        return sum;
    }
};
```