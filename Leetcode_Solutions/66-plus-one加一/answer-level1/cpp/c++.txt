```
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //flag的作用就是检测时候已经完成加1的动作
        bool flag=true;
        for(int i=digits.size()-1;(i>=0&&flag);i--)
        {
            if(digits[i]!=9)
            {
                //找到不为9的位置加1
                digits[i]+=1;
                flag=false;
            }
            else
            {
                //为9的位置进位成0
                digits[i]=0;
            }
        }
        //如果全为9的情况，如9,99 首位变为1,最后补个0
        if(flag==true)
        {
            digits[0]=1;
            digits.push_back(0);
        }

        return digits;
    }
};
```
