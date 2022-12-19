二分查找
----------
* while循环结束标志
* 中间的判断
```cpp
class Solution {
public:
    //二分查找
    char nextGreatestLetter(vector<char>& letters, char target) {
        int nums=letters.size();
        int low=0,high=nums-1;
        
        //循环结束时low>high
        //循环中不返回值，所以结束时的low一定指向比target稍大的值
        //high指向偏小的值
        while(low<=high){
            int mid=low+(high-low)/2;
            //偏小或相等时
            if(letters[mid]<=target){
                low=mid+1;
            //相等或偏大
            }else{
                high=mid-1;
            }
        }

        //letters中都是比target小的，则low会一直加到结尾
        return low<nums?letters[low]:letters[0];
    }
};
```