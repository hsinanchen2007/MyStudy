**核心思想：维护当前效率最小值和最小效率值小于等于当前最小效率值的当前最大速度值总和 **
选择至多k个工程师 求他们团队的最大团队表现值
问题可以这样得到转化:
遍历每个工程师 再找到k-1个其他工程师
使得该工程师在这k个工程师中效率值最小 且这k个工程师的速度值总和最大
于是尝试维护这样一组结构：
1.当前最小效率值
2.当前最大速度值总和
具体步骤如下：
将效率值数组从小到大排序
将速度值数组从大到小排序
先将速度值数组前k项相加得到初始sum值
并对前k项速度值数组元素做标记
并设置j=k+1;j为候选人
由于速度值数组是从大到小排序的
sum表示的是最小效率值小于等于当前最小效率值的当前最大速度值总和 
接下来遍历效率值数组
由于效率值数组是从小到大排序的
所以所遍历的当前效率值数组元素表示的是当前最小效率值
首先看当前遍历的效率值数组元素表示的工程师是否在k个被标记的速度值数组元素表示的工程师之中
若在:sum表示最小效率值小于等于当前最小效率值的当前最大速度值总和 所以对于e[i]来说 这是他做最小值时的最大表现值 
所以 MAX=max(MAX,e[i]*sum);
之后 由于e[i]是当前的效率最小值 为了迎接下一个当前次小值 应把e[i]所代表的工程师的速度值从
sum中删去 sum-=s[i];为了维持k个工程师 在没有选完人的情况下 把候选人的速度值加入 并做标记 sum+=s[j];j++;
若不在 则sum应该减去所选k个工程师的中的最小值而应该加上e[i]所对应的工程师的速度值 而最终sum的值不应该变 因为原有所选工程师中并没有包含当前最小效率值的工程师 不影响迎接下一个次小值
但应该对当前效率最小值的工程师做标记 让他不会成为候选人 影响后面更大的效率值
MAX=max(MAX,(sum-s[j-1]+s[i])*e[i]) 



完整代码

```
int mod;
long long max(long long a,long long b){
if(a>b) return a;
return b;}
struct Engineer{int num;int loc;};
void upsort(struct Engineer * e,int left,int right)
{if(left>=right) return;
int l=left;
int r=right;
int key=e[l].num;
while(l<r)
{while(l<r&&e[r].num>=key) r--;
while(l<r&&e[l].num<=key) l++;
if(l<r)
{struct Engineer temp=e[l];
e[l]=e[r];
e[r]=temp;}}
struct Engineer temp=e[l];
e[l]=e[left];
e[left]=temp;
upsort(e,left,l-1);
upsort(e,l+1,right);
}
void downsort(struct Engineer * s,int left,int right)
{if(left>=right) return;
int l=left;
int r=right;
int key=s[l].num;
while(l<r)
{while(l<r&&s[r].num<=key) r--;
while(l<r&&s[l].num>=key) l++;
if(l<r)
{struct Engineer temp=s[l];
s[l]=s[r];
s[r]=temp;}}
struct Engineer temp=s[l];
s[l]=s[left];
s[left]=temp;
downsort(s,left,l-1);
downsort(s,l+1,right);
}
int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k){
mod=1000000007;
int i,j;
long long MAX=0;
int vis[n];
memset(vis,0,sizeof(vis));
struct Engineer s[n];
struct Engineer e[n];
for(i=0;i<n;i++)
{s[i].num=speed[i];
s[i].loc=i;
e[i].num=efficiency[i];
e[i].loc=i;}
upsort(e,0,n-1);
downsort(s,0,n-1);
long long sum=0;
for(i=0;i<k;i++)
{sum+=s[i].num;
vis[s[i].loc]=1;}
j=k;
long long temp;
for(i=0;i<n;i++)
{if(vis[e[i].loc]) {temp=sum;temp*=e[i].num;MAX=max(MAX,temp);while(j<n-1&&vis[s[j].loc]==2) j++;sum-=speed[e[i].loc];if(j<=n-1&&vis[s[j].loc]==0){sum+=s[j].num;vis[s[j].loc]=1;j++;}}
else{temp=sum-s[j-1].num+speed[e[i].loc];temp*=e[i].num;MAX=max(MAX,temp);vis[e[i].loc]=2;}
}
return MAX%mod;
}
```
时间复杂度:o(nlogn) 主要是两次快排的时间复杂度 核心处理部分时间复杂度为o(n) 故总的时间复杂度为o(nlogn)
空间复杂度 o(n) 开了两个长度为n的结构体数组 故空间复杂度为o(n)


运行结果：
![捕获.PNG](https://pic.leetcode-cn.com/ba5e5978cff0202b09da619cb2236bb48d394f614da757837571439de42444ef-%E6%8D%95%E8%8E%B7.PNG)