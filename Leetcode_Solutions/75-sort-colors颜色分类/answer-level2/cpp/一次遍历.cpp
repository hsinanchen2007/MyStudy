方法二只需一次遍历

方法一 计数排序
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int m=0,n=0,p=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) m++;
            else if(nums[i]==1) n++;
            else p++;
        }
        for(int i=0;i<nums.size();i++){
            if(i<m) nums[i]=0;
            else if(i<m+n) nums[i]=1;
            else nums[i]=2;
        }
    }
    // void sortColors(vector<int>& nums) {
    //     sort(nums.begin(),nums.end());
    // }
};
```
方法二
0总是应该在最左边，2总是应该在最右边，d0,d2记录前一次0，2的位置。
从最开始遍历：
1.若遇到0则i处数与前一次0后面的数交换位置。
2.若遇到2则i处数与前一次2前面的数交换，交换完需判断i处数是否为0，为0则需1步骤。若前一次2前面的数也为2，则d2--，直到遇到不为2的数，同时要保证d2>i。
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int d0=-1,d2=nums.size();
        for(int i=0;i<d2;i++){
            if(nums[i]==0) swap(nums[++d0],nums[i]);
            if(nums[i]==2){
                --d2;
                while(nums[d2]==2&&d2>i) d2--;
                swap(nums[d2],nums[i]);
                if(nums[i]==0) swap(nums[++d0],nums[i]);
            } 
        }
    }
};
```

