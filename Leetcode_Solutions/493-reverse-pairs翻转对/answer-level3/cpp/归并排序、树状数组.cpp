### 解题思路
1、归并排序：在排序的过程中比较左边的数是否大于右边的数2倍就行了，比较简单
2、树状数组：
- 先调用tolink函数打印出排序表，即每个数在整个数组中排多少位（最小的为第1位，包括每个数*2产生的数也一起排）
- 然后倒序遍历nums数组，每次求tree数组中比其小的数有多少个（tree数组里的数都是在其左边的数的两倍），求完后将nums[i]*2更新到树状数组中去。
- 这题和315题基本一样[https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)，可以去做一下

### 代码
归并排序
```cpp
class Solution {
public:
    vector<int>temp;
    int reversePairs(vector<int>& nums) {
        int res=0;
        temp.resize(nums.size());
        mergesort(nums,0,nums.size()-1,res);
        return res;
    }
    void mergesort(vector<int> &nums,int l,int r,int &res){
        if(l>=r) return;
        int mid=l+r>>1;
        mergesort(nums,l,mid,res);
        mergesort(nums,mid+1,r,res);
        for(int i=l;i<=r;i++){
            temp[i]=nums[i];
        }
        int li=l,ri=mid+1,start=mid+1;
        while(li<=mid||ri<=r){
            if(li>mid){
                nums[l]=temp[ri];
                ri++;
            }
            else if(ri>r||temp[li]<temp[ri]){
                int k=start;
                while(k<=r&&(long)temp[k]*2<temp[li]) k++;
                start=k;
                res+=k-mid-1;
                nums[l]=temp[li];
                li++;
            }
            else{
                nums[l]=temp[ri];
                ri++;
            }
            l++;
        }
    }
};
```
树状数组
```
class Solution {
public:
    vector<int>tree;
    int reversePairs(vector<int>& nums) {
        vector<long>vec;
        map<long,int>mp;
        for(int num : nums){
            vec.push_back(num);
            vec.push_back((long)num*2);
        }
        tree.resize(vec.size(),0);
        tolink(vec,mp);
        int res=0;
        for(int i=nums.size()-1;i>=0;i--){
            res+=getsum(mp[nums[i]]-1);
            updata(mp[(long)nums[i]*2]);
        }
        return res;
    }
    void tolink(vector<long> &vec,map<long,int> &mp){
        sort(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++){
            mp[vec[i]]=i+1;
        }
    }
    int getsum(int pos){
        int sum=0;
        while(pos){
            sum+=tree[pos];
            pos-=lowbit(pos);
        }
        return sum;
    }
    void updata(int pos){
        while(pos<tree.size()){
            tree[pos]+=1;
            pos+=lowbit(pos);
        }
    }
    int lowbit(int x){
        return x&(-x);
    }
};
```
