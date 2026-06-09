### 解题思路
一开始用递归没通过，转而想到其实是概率与统计的问题，我们可以将其转化为a步中走b步步长为2的次数，其中n的取值为[0,n/2],下面的问题转化为求C(b,a)的问题，代码如下，有一个坑点就是不能用long 或者int来保存分子与分母，换成double即可
执行结果：通过
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :7.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    /*
    int res=0,maxs;
    void recursion(int current){
        if(current==maxs){
            res++;
            return;
        }
        if(current<maxs){
            recursion(current+1);
            recursion(current+2);
        }
    }*/
    int climbStairs(int n) {
       
       if(n==1){
           return 1;
       }
       int max2=n/2;
       int res=1;
       for(int i=1;i<=max2;i++){
           // i 为2的数目;
           //每轮循环 去求C(b,a);
           int numsOne=n-2*i;
           int mins=min(i,numsOne);
           int maxs=numsOne+i;
           double fenmu=1,fenzi=1;
           for(int i=mins;i>=1;i--){
               fenmu*=maxs;
               maxs--;
               fenzi*=i;
               
           }
           res+=fenmu/fenzi;
       }
       return res;
    }
};
```