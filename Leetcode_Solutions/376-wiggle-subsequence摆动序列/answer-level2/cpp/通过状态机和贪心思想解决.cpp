```
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) { //利用贪心的思想，如果有持续一段的上升或下降，只有当状态变换时，最长序列++
        if(nums.size() < 2){
            return nums.size();
        }
        static const int BEGIN = 0; //设置状态机，当状态变换时，最长序列max_length++
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_length = 1; //设置最长子序列，最小值为1
        for(int i = 1; i < nums.size(); i++){ //遍历数组
            switch(STATE){
                case BEGIN:
                    if(nums[i] > nums[i-1]){ //Begin状态时，如果当前数比前一个数大，变换状态为Up最长序列+1
                        STATE = UP;
                        max_length++;
                    }
                    else if(nums[i-1] > nums[i]){ //变换状态为Down，进入下降段
                        STATE = DOWN;
                        max_length++;
                    }
                    break;
                case UP:
                    if(nums[i] < nums[i-1]){ //上升状态变换下降状态
                        STATE = DOWN;
                        max_length++;
                    }
                    break;
                case DOWN:
                    if(nums[i] > nums[i-1]){ //下降状态变换上升状态
                        STATE = UP;
                        max_length++;
                    }
                    break;
            }
        }
        return max_length;
    }
};
```
