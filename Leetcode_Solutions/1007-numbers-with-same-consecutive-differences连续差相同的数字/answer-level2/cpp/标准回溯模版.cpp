### 解题思路
先填前一个数-k,不符合就填前一个数+k,都不能填就回溯，长度等于N时加入答案即可

### 代码

```cpp
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==1)return {0,1,2,3,4,5,6,7,8,9};
        vector<int>ans,a(n),b(n,-1);//a是遍历数组，b是标记数组
        for(int i=1;i<=9;i++){
            a[0]=i;
            int t=1;
            while(t<n){
                if(a[t-1]-k>=0&&a[t-1]-k>b[t]){
                    b[t]=a[t]=a[t-1]-k;t++;
                }
                else if(a[t-1]+k<=9&&a[t-1]+k>b[t]){
                    b[t]=a[t]=a[t-1]+k;t++;
                }
                else{
                    b[t]=-1;t--;//b代表当前位置可以填的最小数
                    if(t<1)break;//退出循环
                }
                if(t==n){
                    int s=0;
                    for(int j=0;j<n;j++)s+=a[j]*pow(10,n-1-j);
                    ans.push_back(s);//统计答案
                    t--;
                }
            }
        }
        return ans;
    }
};
```