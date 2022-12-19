### 解题思路
最高位是6的直接替换

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        int a,b,c,d;
        if(num<10) return 9;
        if(num<100){
            a=num/10;
            b=num-a*10;
            if(a==6) a=9;
            else if (b==6) b=9;
            return a*10+b;
        }
        if(num<1000){
            a=num/100;
            b=(num-a*100)/10;
            c=num-a*100-b*10;
            if(a==6) a=9;
            else if (b==6) b=9;
            else if (c==6) c=9;
            return a*100+b*10+c;
        }
        if(num<10000){
            a=num/1000;
            b=(num-a*1000)/100;
            c=(num-a*1000-b*100)/10;
            d=num-a*1000-b*100-c*10;
            if(a==6) a=9;
            else if (b==6) b=9;
            else if (c==6) c=9;
            else if (d==6) d=9;            
            return a*1000+b*100+c*10+d;
        }                
        return a*10+b;
    }
};
```