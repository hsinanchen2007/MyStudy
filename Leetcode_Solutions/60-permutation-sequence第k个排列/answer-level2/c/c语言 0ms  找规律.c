这道题我是用的找规律的方法
拿123 来举个例子
它的按全排列排序的序列是 123 132
                        213  231
                        312 321
   我们可以把这六个序列分成三组 分别是按1开头 按2 开头 按 3开头
   而每一组的个数是fac(m=(n-1))fac代表阶乘 即2的阶乘 2个  假如我们的k是3 我们让
   a=k/fac(m）就得到了组号 。 b= k%fac(m） 就得到了 第几组的第几个 (因为这是一个循环的过程
     我把a的初始值设为了k 所以在下面的代码中我写的是b=a%fac(m） a=a/fac(m）) 
   如果b不为0的话 a应该加一 (拿k=3/fac(m）=2来说 本来第3个序列应该在第二组但是因为是整除所以 
a=1 而它在下一组还有b个说明它最终应落在a+1组) 如果b为0的话说明他是某一组的最后一个 这是我们
就直接把它修改为一组序列的个数 即fac(m）
我们维护一个flag数组      数组下标从1开始到n 现在n=3
     1 2 3
     0 0 0   初始值为0 。
 我们得到组号a=2就去找flag数组中第a个值不为0的下标 根据上面的思路 我们找到的是2 把他存到answer数组中 并把flag数组下标为2的值改为1 
                 1 2 3
                 0 1 0 
这时我们其实已经筛选出序列在213 231中(这时候我们分组就看13 和31就好了)  然后我们修改a的值 为b=1 
  m=m-1 =1  然后我们再让 b=a%fac(m） =0 得到在组中的第几个  因为b为0说明在最后一个 将b的值设为fac(m）=1
  a/fac(m）得到组号 为1 所以在flag数组中找第a=1个值不为0的数 也就是下标为1的位置 
 并把flag数组下标为1的值改为1   1 2 3
                              1 1 0
把1存入answer中  接着 修改a的值 为b=1   m=m-1 =0   b=a%fac(m =0  b为0说明在最后
一个 将b的值设为fac(m）=1      a=a/fac(m）=1找第1个flag不为0的下标 即3 把3存入
answer中 这样我们就得到了完整的答案 2 3 1


```
int fac(int n)//计算n的阶乘
{
    if(n==0||n==1)
       return 1;
    else
       return fac(n-1)*n;
}
int find(int *flags,int k,int n)//查找flag数组中第k个值为0的数
{
    int num=0;
    int re=0;
    for(int i=1;i<=n;i++)
    {
        if(flags[i]==0)
           num+=1;
        if(num==k)
        {
           re=i;
           break;
        }
    }
    return re;

}
char * getPermutation(int n, int k){
    char *answer=(char*)malloc(sizeof(char)*(n+1));
    int *flags=(int*)malloc(sizeof(int)*(n+1));
    int i=0;
    for(i=0;i<=n;i++)
        flags[i]=0;
    int m=n-1;
    int a=k;
    int b=0;
    int index=0;
    int cur=0;
    while(m!=-1)
    {
        b=a%fac(m);
        a=a/fac(m);
        if(b!=0)
           a=a+1;
        if(b==0)
           b=fac(m);
        index=find(flags,a,n);
        answer[cur]=index+'0';
        flags[index]=1;
        cur+=1;
        m=m-1;
        a=b;
    }
    answer[cur]='\0';
    return answer;
}

```

