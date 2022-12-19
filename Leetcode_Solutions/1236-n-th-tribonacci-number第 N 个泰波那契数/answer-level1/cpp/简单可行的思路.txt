```
class Solution {
public:
    int tribonacci(int n) {
 //       if(n==0)    return 0;
 //       if(n==1 || n==2)    return 1;
        int a=0,b=0,c=1,d=n;
        while((--n)>0){
            d=a+b+c;
            a=b;b=c;c=d;            
            }
        return d;
    }
};
```

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8 MB, 在所有 C++ 提交中击败了100.00%的用户