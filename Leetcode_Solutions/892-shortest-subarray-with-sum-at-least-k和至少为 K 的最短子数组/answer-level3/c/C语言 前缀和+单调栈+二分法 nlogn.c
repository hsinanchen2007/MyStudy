本题涉及子数组(连续的序列)的和 故可以用前缀和之差来表示子数组的和
若采用前缀和的方法 用暴力法应写成：
for(i=0;i<len;i++)
for(j=0;j<i;j++)
if(s[i]-s[j]>=k) {minlen=min(minlen,i-j+1);break;}
return minlen;
时间复杂度o(n^2)
   由暴力法可以看出 若要保证s[i]-s[j]>=k(k>=1)的前提是s[i]>s[j] 所有对小于s[i]的s[j]的讨论都是多余的 故可以采用单调栈的数据结构来处理 将s[i]逐个放入单调栈中 维护栈的单调递增性
  但是这样仍具有较高复杂度 时间复杂度仍为o(n^2) 如何进一步降低时间复杂度呢
继续分析可以发现 暴力法中第二层循环的实质是在区间j∈[0,i]中找到s[j]<=s[i]-k,且这个j最靠近i
又因为这是一个单调栈 所以满足s[j]<=s[i]-k的s[j]应构成一个连续的区间 找到最靠近i的j实际上是找到这个区间的右边界 这个右边界应满足如下性质：
1.s[border]<=s[i]-k;
2.s[border+1]>s[i]-k;
当某个s[j]满足上述两条性质时 j即为区间的右边界 j=border
又因为这是一个单调栈 故我们可以采取二分法来寻找这个右边界
常规的二分法寻找某个元素找到的标志是等于目标元素
而这里的二分法寻找某个元素找到的标志是满足上述两个性质
分三步
首先看s[mid]是否满足两个性质 满足 更新minlen的值 跳出循环
mid=(left+right)/2
if(s[mid]<=s[i]-k&&s[mid+1]>s[i]-k) {minlen=min(minlen;i-mid+1);break;}
若不满足 则看s[mid]和s[i]-k的x大小关系来进行二分
1.if(s[mid]<=s[i]-k) left=mid+1;//右边界大于mid 向右二分
2.if(s[mid]>s[i]-k) right=mid;//右边界小于mid 向左二分
外循环为o(n) 内循环栈的进栈入栈为常数时间o(1) 二分查找为o(logn)
时间复杂度： o(nlogn)
空间复杂度： o(n)
代码:
```

int min(int a,int b){
if(a<b) return a;
return b;}
int shortestSubarray(int* A, int ASize, int K){
int i,j,k;
int minlen=50005;
int len=ASize;
for(i=0;i<len;i++)
if(A[i]>=K) return 1;
struct Stack{int loc;int num;}stack[len+1];
int s[len];
s[0]=A[0];
for(i=1;i<len;i++)
s[i]=s[i-1]+A[i];
int base=0;
int top=0;
stack[top].num=0;
stack[top].loc=-1;
int left;
int right;
int mid;
for(i=0;i<len;i++)
{while(base<=top) {if(base<top&&s[i]<stack[top].num) top--;else {top++;stack[top].num=s[i];stack[top].loc=i;break;}}
left=base;
right=top;
while(left<right)
{mid=(left+right)/2;
if(stack[mid].num<=stack[top].num-K&&stack[mid+1].num>stack[top].num-K) break;
if(stack[mid].num<=stack[top].num-K) left=mid+1;
else right=mid;}
if(left<right){minlen=min(minlen,stack[top].loc-stack[mid].loc);
}
}
if(minlen==50005) return -1;
return minlen;
```

运行结果
![捕获.PNG](https://pic.leetcode-cn.com/6da987f8e33628313b8b80baca55d7b623f644d8008c79811a3848b0ec92a2a7-%E6%8D%95%E8%8E%B7.PNG)

从运行时间上看显然不是最优的 最优的解法应该是官方题解中的单调队列解法 时间复杂度为o(n)
但思维难度较高 不易想到