### 代码

```cpp
class Solution {
public:
    //找规律法
    //0-9，1的个数为1
    //0-99，1的个数为20
    //0-999，1的个数为300
    //0-9999,1的个数为4000
    //...
    int countDigitOne(int n) {
        if(n==0)
            return 0;
        if(n<10)
            return 1;
        vector<int> bit;
        int nn=n;
        while(nn)
        {
            bit.push_back(nn%10);
            nn/=10;
        }
        int l=bit.size();
        int res=0;
        int temp=n;
        for(int i=l-1;i>0;i--)
        {
            res+=min((int)pow(10,i),max((int)(temp-pow(10,i)+1),0));
            res+=bit[i]*i*pow(10,i-1);
            temp=temp-bit[i]*pow(10,i);
        }
        if(temp>0)
            res+=1;
        return res;
    }
};
```