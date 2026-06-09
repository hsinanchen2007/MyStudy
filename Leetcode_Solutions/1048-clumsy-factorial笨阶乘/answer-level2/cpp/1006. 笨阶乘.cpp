确定这是中等难度不是小儿科？
```
class Solution {
public:
    int clumsy(int N) {
        if(N>=4)
        {
            int res=N*(N-1)/(N-2)+(N-3);
            N-=4;
            while(N>=4)
            {
                res+=(-N*(N-1)/(N-2)+(N-3));
                N-=4;
            }
            switch(N)
            {
                case 0:
                return res;
                case 1:
                return res-1;
                case 2:
                return res-2;
                case 3:
                return res-6;
            }
        }
        else if(N==1)return 1;
        else if(N==2)return 2;
        else if(N==3)return 6;

        return 0;
    }
};
```
