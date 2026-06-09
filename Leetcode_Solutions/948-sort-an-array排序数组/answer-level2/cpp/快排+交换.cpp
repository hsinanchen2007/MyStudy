### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        myqsort(nums,0,nums.size()-1);
        return nums;
    }
    void myqsort(vector<int> & nums,int l , int r){
        if(l<r){//递归边界
            int key = nums[l];
            int i = l,j = r;
            while(i<j){//只要i！=j 就一直做对比
                while(i<j&&key<=nums[j]) j--;//向左移动，找比key小的值，找到后交换
                    swap(nums[i],nums[j]);
                while(i<j&&key>=nums[i]) i++;
                    swap(nums[j],nums[i]);
            }

            myqsort(nums,l,i-1);//比key小的左半部分
            myqsort(nums,i+1,r);//比key大的右半部分
        }
    }
    void swap(int &a,int &b){
        int temp = a; a = b; b = temp;
    }
};
```