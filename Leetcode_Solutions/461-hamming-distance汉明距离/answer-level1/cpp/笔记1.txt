```c []
int hammingDistance(int x, int y){
int a;
a=x^y;  
int res=0;
while(a>0)
{
    if(a%2!=0) res++;     //判断二进制最后一位是否为1
    a=a/2;                //二进制右移1
}
return(res);
}
```
```c++ []
class Solution {
public:
    int hammingDistance(int x, int y) {
        int res=0,a;
        a=x^y;
        while(a)
        {
            if(a&1!=0) res++;  //用与判断最后一位是否为1
            a>>=1;
        }
        return res;
    }
};
```
```py []
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x^y).count("1")
```

