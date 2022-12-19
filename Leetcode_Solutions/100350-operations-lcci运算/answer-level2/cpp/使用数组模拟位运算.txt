### 解题思路

对于减法来说，只要加上其相反数就可以了。

乘法和除法都要使用位运算的方法来解决。但是，题目中又规定了不可以使用位运算。

怎么办呢，我们可以使用查找表的方法来模拟位运算。

建立二进制的查找表，剩下的事情就已经很简单了。

要注意的是，本题的测试数据非常的刁钻。我也是试错了很多次。

### 代码

```cpp
class Operations {
public:
    Operations() {
        
    }
    
    int minus(int a, int b) {
        return a+(-b);
    }
    
    int multiply(int a, int b) {
        int sign=1;
        if(a==0||b==0)
            return 0;
        if(a==1)
            return b;
        if(b==1)
            return a;
        if(a < 0)
        {
            sign=-sign;
            a=-a;
        }
        if(b<0)
        {
            sign=-sign;
            b=-b;
        }
        int ans=0;
        fill(a);
        for(int i=30;i>=0;i--)
        {
            if(b+count[i]<0)
            {
                
                //cout<<"b "<<b<<" i "<<i<<" count "<<count[i]<<endl;
                continue;
            }
            //cout<<"i "<<i<<" table[i] "<<table[i]<<" b "<<b<<" count[i] "<<count[i]<<" ans "<<ans<<endl;
            b+=count[i];
            ans+=table[i];
        }
        if(sign==1)
            return -ans;
        return ans;
    }
    
    int divide(int a, int b) {
        if(b == 1)
            return a;
        else if(b==-1)
            return -a;

        int sign=1;
        if(a==0)
            return 0;
        if(a < 0)
        {
            sign=-sign;
            a=-a;
        }
        if(b<0)
        {
            sign=-sign;
            b=-b;
        }

        int ans=0;
        fill(b);
        
        for(int i=30;i>=0;i--)
        {
            if(a+table[i]<0)
                continue;
            //cout<<"i "<<i<<" table[i] "<<table[i]<<" a "<<a<<" count[i] "<<count[i]<<endl;
            a+=table[i];
            ans+=count[i];
        }
        if(sign == 1)
            return -ans;
        return ans;
    }

    void fill(int a)
    {
        if(a>0)
            a=-a;
        int i=0;
        table[0]=a;
        while(table[i] >= halfmax)
        {
            i++;
            table[i]=table[i-1]+table[i-1];
            //cout<<"i "<<i<<"table "<<table[i]<<" half "<<halfmax<<endl;
        }
        i++;
        for(;i<31;i++)
        {
            table[i] = -2147483648;
        }
        //for(i=0;i<31;i++)
        //    cout<<"i "<<i<<"table "<<table[i]<<" count "<<count[i]<<endl;
    }
        
private:
    int halfmax=-1073741824;
    int table[32];
    int count[32]={-1,-2,-4,-8,-16,-32,-64,-128,-256,-512,-1024,-2048,-4096,
                   -8192,-16384,-32768,-65536,-131072,-262144,-524288,
                   -1048576,-2097152,-4194304,-8388608,-16777216,-33554432,
                   -67108864,-134217728,-268435456,-536870912,-1073741824};
};
```