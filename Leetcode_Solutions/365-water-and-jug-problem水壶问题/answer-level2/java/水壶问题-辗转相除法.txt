### 解题思路
闹了半天原来就他妈是个辗转相除法

### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(y<x)
        {
            int temp=x;
            x=y;
            y=temp;
        }
        if(z>x+y)
            return false;
        if(z==0)
        {
            return true;
        }
        if(x==0)
        {
            if(y==z)
                return true;
            else
                return false;
        }
        if(y==0)
        {
            if(x==z)
                return true;
            else
                return false;
        }
/*
        if(z%x==0)
            return true;
        if(z==y)
            return true;
        int a=1,b=1;
        int result=1;
        for(int i=1;result<=x+y;i++)
        {
            result = i*y-i*x;
            for(int j=0;result+j*x<=x+y||result-j*x>0;j++)
            {
                if(result-j*x==z||result+j*x==z)
                    return true;
            } 
        }   
        for(int i=1;result+y>0;i++)
        {
            result=(i+1)*x-i*y;
            for(int j=0;result+j*x<=x+y;j++)
            {
                if(result+j*x==z)
                return true;
            }
            if(result+y==z)
                return true;
            a++;            
        }
       return false;

    */
        if(z%gcd(x,y)==0)
        {
            return true;
        }
        else
            return false;
    }
    public int gcd(int a,int b)
    {
        if(a%b==0)
        {
            return b;
        }
        else
        {
            return gcd(b,a%b);
        }
    }
}
```