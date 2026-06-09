### 解题思路
此处撰写解题思路
想法与冒泡排序一样,冒泡排序是将最大的元素与最后的元素进行交换,这道题是将与val相等的元素与最后的与val不相等的元素进行交换
### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        //双指针法(寻找要删除的值,把它和最后的不是要删除的元素进行交换,思想类似于冒泡排序)
        int begin,end=nums.size()-1;
        for(begin=0;begin<end;begin++){
            //判断下标为begin的元素是否是要找的
            if(nums[begin]==val){
                //找到最后一个不是val的元素
                while(end>begin){
                    if(nums[end]!=val) break;
                    end-=1;                
                }
                if(end==begin && begin==0) return 0;
                if(end==begin) return begin;
                swap(nums[begin],nums[end]);
            }
        }
        if(begin==0 && nums[begin]!=val) return 1;
        if(nums[begin]!=val) return begin+1;
        //if(begin==end) return begin+1;
        return begin;
    }
};
```