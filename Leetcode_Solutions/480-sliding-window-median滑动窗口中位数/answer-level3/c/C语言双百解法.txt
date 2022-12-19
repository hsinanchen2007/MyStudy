思路：先用partition算法将下标为0到k-1的nums数组中的中位数找出 此步骤复杂度为o(k);
以此中位数为基准手写建立大小堆 前大后小 将窗口以大小堆的数据结构存储 再左出右进 滑动窗口
在此过程维护大小堆 此步骤的算法思想可见官方题解 具体细节可见代码 此步骤复杂度为o(nlogk)
故最终时间复杂度为o(nlogk);
空间复杂度为o(n);

![捕获.PNG](https://pic.leetcode-cn.com/fcf3b7938e20444825e3aa289d266c13a6d6d4983bb9ce3e3c48da153e5fdbca-%E6%8D%95%E8%8E%B7.PNG)

完整代码如下：

 ```
struct TOP{int loc;int num;};
void insertmin(struct TOP * mintop,int k1,int num,int loc)
{if(k1==1) {mintop[1].loc=loc;mintop[1].num=num;return;}
struct TOP temp;
mintop[k1].loc=loc;
mintop[k1].num=num;
while(k1>1)
{if(mintop[k1].num<mintop[k1/2].num)
{temp=mintop[k1];
mintop[k1]=mintop[k1/2];
mintop[k1/2]=temp;
k1/=2;}
else break;}
}
void insertmax(struct TOP * maxtop,int k2,int num,int loc)
{if(k2==1) {maxtop[1].loc=loc;maxtop[1].num=num;return;}
struct TOP temp;
maxtop[k2].loc=loc;
maxtop[k2].num=num;
while(k2>1)
{if(maxtop[k2].num>maxtop[k2/2].num)
{temp=maxtop[k2];
maxtop[k2]=maxtop[k2/2];
maxtop[k2/2]=temp;
k2/=2;}
else break;}
}


void mindelete(struct TOP * mintop,int k1)
{mintop[1]=mintop[k1];
int kk=1;
struct TOP temp;
while(kk<k1)
{if(2*kk>=k1) break;
if(2*kk+1>=k1)
{if(mintop[kk].num>mintop[2*kk].num)
{temp=mintop[kk];
mintop[kk]=mintop[2*kk];
mintop[2*kk]=temp;
kk*=2;}
else break;}
else
{if(mintop[kk].num<=mintop[2*kk].num&&mintop[kk].num<=mintop[2*kk+1].num) break;
if(mintop[2*kk].num>mintop[2*kk+1].num)
{temp=mintop[kk];
mintop[kk]=mintop[2*kk+1];
mintop[2*kk+1]=temp;
kk=2*kk+1;}
else
{temp=mintop[kk];
mintop[kk]=mintop[2*kk];
mintop[2*kk]=temp;
kk=2*kk;}
}
}
}

void maxdelete(struct TOP * maxtop,int k2)
{maxtop[1]=maxtop[k2];
int kk=1;
struct TOP temp;
while(kk<k2)
{if(2*kk>=k2) break;
if(2*kk+1>=k2)
{if(maxtop[kk].num<maxtop[2*kk].num)
{temp=maxtop[kk];
maxtop[kk]=maxtop[2*kk];
maxtop[2*kk]=temp;
kk*=2;}
else break;}
else
{if(maxtop[kk].num>=maxtop[2*kk].num&&maxtop[kk].num>=maxtop[2*kk+1].num) break;
if(maxtop[2*kk].num<maxtop[2*kk+1].num)
{temp=maxtop[kk];
maxtop[kk]=maxtop[2*kk+1];
maxtop[2*kk+1]=temp;
kk=2*kk+1;}
else
{temp=maxtop[kk];
maxtop[kk]=maxtop[2*kk];
maxtop[2*kk]=temp;
kk=2*kk;}
}
}
}


double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
int i,j,len;
len=numsSize;
if(k==1)
{double* middle = (double *)malloc(sizeof(double) *(len));
for(i=0;i<len;i++)
middle[i]=1.0*nums[i];
*returnSize=len;
return middle;
}
if(k==2)
{double* middle = (double *)malloc(sizeof(double) *(len-1));
for(i=0;i+1<len;i++)
middle[i]=(1.0*nums[i]+1.0*nums[i+1])/2;
*returnSize=len-1;
return middle;
}
j=0;
double* middle = (double *)malloc(sizeof(double) *(len-k+1)); 
struct TOP maxtop[len];
struct TOP mintop[len];
int hash[len];
memset(hash,0,sizeof(hash));
int bal[3]={0};
int MID1,MID2;
int numsk[k];
for(i=0;i<k;i++)
numsk[i]=nums[i];
int left=0;
int right=k-1;
int mid=(left+right)/2;
int l;
int r;
int key;
while(left<right)
{l=left;
r=right;
key=numsk[left];
while(l<r)
{while(l<r&&numsk[r]>=key) {r--;}
while(l<r&&numsk[l]<=key) {l++;}
if(l<r)
{int temp=numsk[r];
numsk[r]=numsk[l];
numsk[l]=temp;}
}
int temp=numsk[l];
numsk[l]=numsk[left];
numsk[left]=temp;
if(mid==l) {MID1=numsk[l];break;}
else if(l>mid) right=l;
else if(l<mid) left=l+1;
}
if(k%2==1) middle[0]=MID1*1.0;
else 
{left=0;
right=k-1;
mid=(left+right+1)/2;
while(left<right)
{l=left;
r=right;
key=numsk[left];
while(l<r)
{while(l<r&&numsk[r]>=key) {r--;}
while(l<r&&numsk[l]<=key) {l++;}
if(l<r)
{int temp=numsk[r];
numsk[r]=numsk[l];
numsk[l]=temp;}
}
int temp=numsk[l];
numsk[l]=numsk[left];
numsk[left]=temp;
if(mid==l) {MID2=numsk[l];break;}
else if(l>mid) right=l;
else if(l<mid) left=l+1;
}
middle[0]=(1.0*MID1+1.0*MID2)/2;
}

int k1=0;
int k2=0;
if(k%2==0)
{for(i=0;i<k;i++)
{if(nums[i]<=MID1) {hash[i]=1;k1++;bal[1]++;insertmax(maxtop,k1,nums[i],i);}
else if(nums[i]>=MID2){hash[i]=2;k2++;bal[2]++;insertmin(mintop,k2,nums[i],i);}}}
else
{for(i=0;i<k;i++)
{if(nums[i]<=MID1) {hash[i]=1;k1++;bal[1]++;insertmax(maxtop,k1,nums[i],i);}
else {hash[i]=2;k2++;bal[2]++;insertmin(mintop,k2,nums[i],i);}}}
left=0;
right=k-1;
while(right<len-1)
{if(hash[left]==1) bal[1]--;
if(hash[left]==2) bal[2]--;
hash[left]=-1;
while(k1>0&&hash[maxtop[1].loc]==-1)
{maxdelete(maxtop,k1);k1--;}
while(k2>0&&hash[mintop[1].loc]==-1)
{mindelete(mintop,k2);k2--;}
left++;
right++;
if(k1==0&&nums[right]<=mintop[1].num) {k1++;bal[1]++;hash[right]=1;insertmax(maxtop,k1,nums[right],right);}
else if(k2==0&&nums[right]>=maxtop[1].num) {k2++;bal[2]++;hash[right]=2;insertmin(mintop,k2,nums[right],right);}
else if(nums[right]<maxtop[1].num) {k1++;bal[1]++;hash[right]=1;insertmax(maxtop,k1,nums[right],right);}
else if(nums[right]>mintop[1].num) {k2++;bal[2]++;hash[right]=2;insertmin(mintop,k2,nums[right],right);}
else{if(bal[1]<=bal[2]) {k1++;bal[1]++;hash[right]=1;insertmax(maxtop,k1,nums[right],right);}
else {k2++;bal[2]++;hash[right]=2;insertmin(mintop,k2,nums[right],right);}}
if(bal[1]<bal[2]) {k1++;bal[1]++;hash[mintop[1].loc]=1;insertmax(maxtop,k1,mintop[1].num,mintop[1].loc);mindelete(mintop,k2);k2--;bal[2]--;}
else if(bal[1]>bal[2]+1) {k2++;bal[2]++;hash[maxtop[1].loc]=2;insertmin(mintop,k2,maxtop[1].num,maxtop[1].loc);maxdelete(maxtop,k1);k1--;bal[1]--;}
while(k1>0&&hash[maxtop[1].loc]==-1)
{maxdelete(maxtop,k1);k1--;}
while(k2>0&&hash[mintop[1].loc]==-1)
{mindelete(mintop,k2);k2--;}
if(k%2==0) middle[++j]=(1.0*maxtop[1].num+1.0*mintop[1].num)/2;
else middle[++j]=1.0*maxtop[1].num;
}
*returnSize=len-k+1;
return middle;
}
```
