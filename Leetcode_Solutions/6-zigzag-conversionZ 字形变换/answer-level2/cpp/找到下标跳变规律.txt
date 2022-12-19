### 解题思路
列上字符：Z字排列中组成列的字符
列间字符：Z字排列中组成斜线的字符
其他见注释

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        int full_step, side_step, mid_step;
        string str_ret;
        int b_side, j;
        int len=s.length();

        if(numRows==1){                //若只有一行，直接输出原字符串
            str_ret = s;
            return str_ret;
        }

        full_step=2*numRows-2; 

        j=0;                           //第一行，此行上没有列间字符，全是列上
        while(j<len){
            str_ret+=s[j];
            j+=full_step;              //下标跳变距离即为两列间的跳变距离
        }

        for(int i=1; i<numRows-1; i++){          //中间的行
            mid_step=2*i;                        //列间的字符下一跳应该前进的距离，只与当前行号有关
            side_step=full_step-mid_step;        //列上的字符下一跳距离
            j=i;
            b_side=1;
            while(j<len){
                str_ret+=s[j];
                if(b_side){            //标识此轮取的字符是列上的还是列间的
                    j+=side_step;
                    b_side=0;
                }
                else{
                    j+=mid_step;
                    b_side=1;
                }
            }
        }

        j=numRows-1;                   //最后一行，同第一行
        while(j<len){
            str_ret+=s[j];
            j+=full_step;              //同第一行
        }
        return str_ret;
    }
};
```