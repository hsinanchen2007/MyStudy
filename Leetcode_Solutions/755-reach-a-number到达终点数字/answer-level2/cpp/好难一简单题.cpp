### 题意
给[1,无穷]中的整数添加符号，使其和为target。
### 思路
拿到题想就是个二叉树的深搜咯，就准备开始DFS，写完超时了，然后剪枝，还(四声)超时？一看target范围傻眼了，没得办法，看了题解写写感悟。

+ 首先是正负无关，因为得到target时，只需要之前所有符号相反即可得到-target。
+ 假设target是正的，我们可以找到累加和比target的大的第一个total(1+...+k)。
> + 如果total==target,那么我们就找到了最小k。
> + 如果diff=total-target是偶数，我们可以通过调整(1,2...k)中的某一项或者几项消除差距。所以最小还是k;
> + 如果diff=total-target是奇数，我们就需要找到与target相差为偶数的新total，以便重复上述思路。
>> 如果能保证**total(新)-total=奇数**,然后与**total-target=奇数**相加便可以得到d!ff为偶数。
>>
>> total(新)-total=(k+1)+(k+2)+...
>> + 如果k是奇数，那么k+1为偶数，2k+3为奇数。最小值为k+2
>> + 如果k是偶数，那么k+1为奇数。最小值为k+1.

叮~数学是第一生产力！

k    |   1 |  2  | 3   |4  |   5  |   6   |  7  |    8   |   9|...
---|---|---|---|---|---|---|---|---|---|---
total |  1  | 3  | 6 |  10 |   15 |   21   | 28  |  36   |   45|...

### 代码
```c++
```c++
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int k=0;
        while(target>0){
            target-=++k;
        }
        target=abs(target);
        return target%2==1?k+1+k%2:k;
    }
};
```
深搜+剪枝(未AC)
```c++
class Solution {
public:
    void dfs(int n,int& ans,int cur,int target){
        if(n>target+1||n>=ans)return;
        if(target==cur){ans=min(n,ans);return;}
        dfs(n+1,ans,cur+n,target);
        dfs(n+1,ans,cur-n,target);
        return;
    }
    int reachNumber(int target) {
        int ans=INT_MAX,n=0;
        dfs(n,ans,0,target);
        return ans-1;
    }
};
```
