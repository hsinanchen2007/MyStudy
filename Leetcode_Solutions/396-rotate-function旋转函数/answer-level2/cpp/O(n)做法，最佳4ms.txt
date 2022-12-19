#### 题意

给定个向量，比如{4,3,2,6},定义右旋操作(其实就是循环数组的右移)
> 4,3,2,6--->6,4,3,2--->2,6,4,3--->3,2,6,4.

F(0)就是(4,3,2,6)和(0,1,2,3)的内积。F(1),F(2),F(3)以此类推。求F(n)的最大值

#### 思路

第一种想法是遍历每种右旋排列，然后求其与(0,1···,n-1)的内积，时间复杂度是O(n²)的。可能会超时就没写。

如果考虑如何用F(0)得到F(1)这样我们就不必每次求内积，相当于省了一层遍历，时间复杂度是O(n)的

递推表达式是这样的:
> F(i)=F(i+1)+(total-A[i+1])-(n-1)* A[i+1]

我们用一个例子研究这个式子。考虑从F(0)->F(1)。

```
4,3,2,6  -->  6,4,3,2
0,1,2,3  -->  0,1,2,3
```
+ 实际上就是尾部的元素6从乘3变成了乘0，即减少了(n-1)* A[i+1].
+ 而其他元素所乘的数字都各自加了1，即增加了total-A[i+1].其中total表示A的累加。

进一步优化，递推表达式可以化简为：
> F[i]=F[i+1]+(total-n* A[i+1]);

#### 注意
+ 求累加的时候acumulate的第三个参数是要强制转换为long的，改了好久......才找见
#### 代码
时间4ms-24ms内浮动。内存就别骂了(抱紧狗头~(￣▽￣)~)
```c++
int maxRotateFunction(vector<int>& A) {
        long ans=0,total=0,n=A.size();
        if(n==0||n==1) return 0;
        vector<long> a(n,0);
        total=accumulate(A.begin(),A.end(),(long)0);
        
        for(int i=0;i<n;i++)
            a[n-1]+=i*A[i];
        
        ans=a[n-1];
        
        for(int i=n-2;i>=0;i--){
            a[i]=a[i+1]+(total-n*A[i+1]);
            ans=max(a[i],ans);
        }
        return ans;
    }
```
---
2019.11.10更新

用一个变量tmp代替数组。
```c++
int maxRotateFunction(vector<int>& A) {
        long ans=0,tmp=0,total=0,n=A.size();
        if(n==0||n==1) return 0;
        //vector<long> a(n,0);
        total=accumulate(A.begin(),A.end(),(long)0);
        
        for(int i=0;i<n;i++)
            tmp+=i*A[i];
        
        ans=tmp;
        for(int i=n-2;i>=0;i--){
            tmp+=(total-n*A[i+1]);
            ans=max(tmp,ans);
        }
        return ans;
    }

```