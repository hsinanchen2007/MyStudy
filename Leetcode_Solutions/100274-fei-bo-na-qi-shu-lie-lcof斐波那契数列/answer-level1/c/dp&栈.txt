### 解题思路
递归总是超时；溢出问题需要处理；
dp过程中需要注意，两个变量的更新是两步。

### 代码

```cpp
//动态规划
class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int i=2;
        int a=0;
        int b=1;
        while(i<=n){
            a=(a+b);
            if(a>1000000007) a=a-1000000007;
            b=(a+b);
            if(b>1000000007) b=b-1000000007;
            i+=2;
            }
        return n%2==0?a:b;
        }

};

//牺牲空间
class Solution {
public:
    int fib(int n) {
        long int arr[101];
        for(int i=0;i<=n;i++){
            if(i<=1) arr[i]=i;
            else arr[i]=arr[i-1]+arr[i-2];
                if (arr[i]>1000000007) arr[i]-=1000000007;

        }
        return arr[n];



    }
};