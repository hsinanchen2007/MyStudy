排序后用双指针，如果数组元素个数为偶数n则一个指针指向中间一个指针指向最后(例如 1 2 3 4 5 6则一个指向3 一个指向6)然后依次填数即可(先填左指针的数再填右指针的数保证增减增减的顺序)
若为奇数个,仔细分析可以发现序列的倒数第二个元素到最后一个元素必然是递减的所以可以考虑将排序后的第一元素放到最后，这样就又变成了元素个数为偶数的问题了。
```c++
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();
        for(auto c:nums)temp.push_back(c);
        sort(temp.begin(),temp.end());
        if(!(n&1))done(nums,temp,(n-1)/2,n-1,0);
        else{
            done(nums,temp,n/2,n-1,1);
            nums[n-1]=temp[0];
        }
    }
    void done(vector<int>& nums,vector<int>& temp,int l,int r,int lowbond){
        int i=0;
        while(l>=lowbond){
            nums[i++]=temp[l--];
            nums[i++]=temp[r--];
        }
    }
};
```