最大长度501位，远远超过了整数能表示的范围。用bitset代替整数模拟，每次判断最低位即可。

```
class Solution {
public:

    int numSteps(string s) 
    {
        int n = s.size() - 1;
        bitset<501> dd(s.c_str());
        int step = 0;
        while(n > 0)
        {
            if(dd[0])
            {
                dd[0] = 0;
                //进位
                int i = 1;
                for(; i <= n + 1; i++)
                {
                    if(!dd[i]){
                        dd[i] = 1;
                        break;
                    }
                    dd[i] = 0;
                }
                if(dd[n + 1])
                    n++;
            }
            else{
                dd >>= 1;
                n --;
            }
            step ++;
        }
        return step;
    }
};
```
