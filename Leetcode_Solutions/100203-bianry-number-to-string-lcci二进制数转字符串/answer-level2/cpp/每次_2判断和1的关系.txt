循环判断num是否等于0，
在循环中每次*2，判断和1的关系，大于等于1为让num-=1，res+="1",
否则让res+="0"
```c++ []
class Solution {
public:
    string printBin(double num) {
        string res="0.";
        while(num!=0)
        {
            if(res.size()==32)
                return "ERROR";
            num*=2;
            if(num>=1)
            {
                num-=1;
                res+="1";
            }
            else res+="0";
        }
        return res;
    }
};
```