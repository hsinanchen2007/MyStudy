```C++ []
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if(k<=nums.size()&&k>0){
            reverse(nums,0,nums.size()-1-k);
            reverse(nums,nums.size()-k,nums.size()-1);
            reverse(nums,0,nums.size()-1);
        }
    }
    public:
    void reverse(vector<int>&m,int a,int b){
        while(a<b){
            int temp=m[a];
            m[a]=m[b];
            m[b]=temp;
            ++a;--b;
        }
    }
};
```