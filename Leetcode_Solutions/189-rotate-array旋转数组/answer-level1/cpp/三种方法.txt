方法一 暴力，超时
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int nsize=nums.size(),prev;
        for(int i=0;i<k;i++) {
            prev=nums[nsize-1];
            for(int j=0;j<nsize;j++) swap(nums[j],prev);
        }
    }
};
```
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k==0) return;
        int nsize=nums.size(),tmp=nums[nsize-1];
        for(int j=nsize-1;j>0;j--) nums[j]=nums[j-1];
        nums[0]=tmp;
        rotate(nums,k-1);
    }
};
```
方法二 需要额外的vector
 1.大小和nums一样
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> newvec(nums.size(),0);
        for(int i=0;i<nums.size();i++) newvec[(i+k)%nums.size()]=nums[i];
        for(int i=0;i<nums.size();i++) nums[i] = newvec[i];
    }
};
```
 2.大小为k
```
class Solution {
public:
     void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        k %=nums.size();
        for(vector<int>::iterator it=nums.begin()+nums.size()-k;it!=nums.end();){
            tmp.emplace_back(*it);
            it=nums.erase(it);
        }
        vector<int>::iterator it=nums.begin();
        for(int j=tmp.size()-1;j>=0;j--) it=nums.insert(it,tmp[j]);    
    }
};
```
方法三 反转
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k%nums.size());
        reverse(nums.begin()+k%nums.size(),nums.end());
    }
};
```


