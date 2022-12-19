### 解题思路
跟前面那个题基本一样，就是用一个map记录数组里每个数的次数，
然后再用一个map实时记录填到第k位置时已经填的数的次数，要求
它不超过原本数组里对应数的次数。
相当于就是多了个判断条件而已。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int i,j,k=0,n=nums.size(),v[n];
        if(n==0)return {{}};
        map<int,int>m,p;
        vector<int>a(n);
        vector<vector<int>>s;
        memset(v,0,sizeof(v));
        sort(nums.begin(),nums.end());
        for(i=0;i<n;i++){
            if(m.count(nums[i]))m[nums[i]]++;
            else m[nums[i]]=1;
            p[nums[i]]=0;
            v[i]=-9999999;
        }
        while(k<n){
            for(i=0;i<n;i++){
                if(p[nums[i]]<m[nums[i]]&&nums[i]>v[k]){
                    a[k]=nums[i];v[k]=nums[i];
                    p[nums[i]]++;k++;
                    break;
                }
            }
            if(i==n){
                v[k]=-9999999;
                k--;
                if(k<0)break;
                p[a[k]]--;
            }
            if(k==n){
                k--;
                s.push_back(a);
                p[a[k]]--;
            }
        }
        return s;
    }
};
```