### 解题思路
/*二分法的精髓：如何根据实际条件移动左右指针---》本题中就是low_position和high_positon
1、本题的关键：如果target == nums[mid]时如何移动左右指针，----》本题中是通过提供一个参数direction来决定此时如何移动左右指针。
2、详细思路请见代码注释
*/

### 代码

```cpp
/******************二分法解题思路*********************/
/*二分法的精髓：如何根据实际条件移动左右指针---》本题中就是low_position和high_positon
1、本题的关键：如果target == nums[mid]时如何移动左右指针，----》本题中是通过提供一个参数direction来决定此时如何移动左右指针。
2、详细思路请见代码注释
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ret(2,-1);
        if(size == 0){
            return ret;
        }else if(size == 1){
            if(nums[0] != target){
                return ret;
            }else{
                return {0,0};
            }
        }

        int leftposition = getPosition(nums,target,true);//获取最左侧的位置      
        if(leftposition == -1 || leftposition == nums.size()  || nums[leftposition] != target){//这里根据求出来的最左的位置做第一次判断，决定是否进行最右位置的获取
            return ret;
        }

        ret[0] = leftposition;
        ret[1] = getPosition(nums,target,false) - 1;//获取最右侧的位置
        return ret;
    }

    int getPosition(vector<int>& nums, int target,bool direction){//direction == true 则求最target位于nums中的最左侧的位置，否则就是求最右侧的位置。
        int size = nums.size();

        if(nums[size - 1] < target || nums[0] > target){
            return -1;
        }

        int low_position = 0;//target元素位于nums数组中最左侧的位置，初始化为0
        int high_position = size;//target元素位于nums数组中最左侧的位置，初始化为nums数组的长度，但是这是为什么呢？==这里的highposition为什么从size开始？
        int mid_positon = 0;

        while(low_position < high_position){//如果最左的位置小于最有的位置，则一直循环下去。
            mid_positon = (low_position + high_position) / 2;//求取中间位置，二分法的精髓
            if(nums[mid_positon] > target || (direction && nums[mid_positon] == target)){
                //1、如果target小于中间位置(low_positon和high_position的中间位置)的元素，则将high_position移动到mid_position的位置。
                //2、如果target等于中间位置(low_positon和high_position的中间位置)的元素，则根据我们要求取的是最左还是最右(dirction参数决定)的位置来确定如何移动low_positon和high_position。如果是求最左，则移动high_position；否则移动low_position
                high_position = mid_positon;
            }else{
                //1、如果target大于中间位置(low_positon和high_position的中间位置)的元素，则将low_position移动到mid_position+1的位置。
                low_position = mid_positon + 1;
            }
        }
        return low_position;
    }
};


/************************以下是暴力法******************************/
/*
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> resultRange(2,-1);
        int length = nums.size();
        if(length == 0){
            return resultRange;
        }
        for(int i = 0;i < length;i++){
            if(nums[i] == target){
                resultRange[0] = i;
                break;
            }
        }

        if(resultRange[0] == -1){
            return resultRange;
        }

        for(int i = length-1;i >= 0;i--){
            if(nums[i] == target){
                resultRange[1] = i;
                break;
            }
        }

        return resultRange;
        
    }
};
*/
/**********************以上是暴力法*********************************/
```