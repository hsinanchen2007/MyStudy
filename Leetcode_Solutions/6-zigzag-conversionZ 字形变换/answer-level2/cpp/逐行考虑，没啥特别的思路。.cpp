### 解题思路
最后的排列应该是这样子的“|/|/|/|/|”；
1.找到周期，应该是“|/”，注意到第一行和最后一行为一个，其他行两个，故周期step=(numRows x 2-2);
2.第一行：起始位置是0，每周期输出一个；
3.第二至倒数第二（numRows-1）行：起始位置是numRows-1，每周期输出两个，可以理解为一个step分成tmpstep和step-tmpstep交替;第一个tmpstep应该是numRows+step-(numRows x 2);
4.第numRows行：起始位置是起始位置是numRows-1，每周期输出一个。
完事。大家多多指点 :)
### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
            return s;
        int n=s.size();
        string ret="";
        int i=0;
        int step=(numRows*2-2);

        //line 1
        while(i<n){
            ret+=s[i];
            i+=step;
        }
        //line2 to numRows-1
        for(int j=1;j<numRows-1;j++){
            i=j;
            int tmpstep=step-2*j;
            while(i<n){
                ret+=s[i];
                i+=tmpstep;
                tmpstep=step-tmpstep;
            }
        }
        //line numRows
        i=numRows-1;
        while(i<n){
            ret+=s[i];
            i+=step;
        }

        return ret;
    }
};
```