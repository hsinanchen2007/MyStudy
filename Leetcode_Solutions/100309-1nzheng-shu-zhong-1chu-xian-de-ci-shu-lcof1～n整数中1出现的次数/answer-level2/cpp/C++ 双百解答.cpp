### 解题思路
参考的是Java最高赞的思路，用C++实现，大佬轻喷

### 代码

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        int res=0;
        if (n>=1 && n<=9) {
            return 1;
        }
        else if(n==0)
        {
            return 0;
        }
        int temp=n, high=0, pow=1, last=0;
        int cnt=0;
        while (temp)
        {
            cnt++;
            if(cnt==1)
            {
                pow=1;
            }
            else
            {
                pow=pow*10;
            }
            temp=temp/10;
        }
        temp=n;
        high=temp/pow;
        last=temp-high*pow;
        
//        cout<<"temp="<<temp<<endl;
//        cout<<"high="<<high<<endl;
//        cout<<"pow="<<pow<<endl;
//        cout<<"last="<<last<<endl;
        if (high==1)
        {
            res=countDigitOne(pow-1)+(last+1)+countDigitOne(last);
        }
        else
        {
            res=high*countDigitOne(pow-1)+countDigitOne(last)+pow;
        }
        return res;
    }
};
```