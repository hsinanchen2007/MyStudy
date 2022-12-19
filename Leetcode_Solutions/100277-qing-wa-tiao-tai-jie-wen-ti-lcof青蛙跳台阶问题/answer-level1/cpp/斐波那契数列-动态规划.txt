### 解题思路
1.当i>=3时，登上最后一级台阶必须先登上第i-1级（然后迈一级上去）或第i-2级台阶（然后迈两级），所以总的登顶方式way[i]=way[i-1]+way[i-2];

2.由于我们只需要way[i]，且每步计算只涉及前两级，所以我们没必要开一个大小为i的数组，只要不断更新三个变量，记录前两级的值。

3.计算过程中会出现值大于long long,所有在计算中就要取模。
公式：（a+b）%c=(a%c+b%c)%c,证明：a=k1c+x1,b=k2c+x2,带入即证。
例：a4?
a3=a1+a2
a4=a2+a3
result=a4%c=(a2+a1+a2)%c

a3=(a1+a2)%c
a4=(a2+a3)%c=(a2+(a1+a2)%c)%c=(a2%c+(a1+a2)%c)%c=(a2+(a1+a2))%c=result，其中已知a1,a2小于c，故a2=a2%c;


### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if(n==0)return 1;
        if(n<=2)return n;
        int p1=1;
        int p2=2;
        int sum;
        for(int i=3;i<=n;i++){
            sum=(p1+p2)%1000000007;
            p1=p2;
            p2=sum;
        }
        return sum;
    }
};

```