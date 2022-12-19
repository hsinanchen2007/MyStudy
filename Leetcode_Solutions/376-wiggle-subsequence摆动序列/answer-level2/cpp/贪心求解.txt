### 解题思路
1.第一种使用状态机求解
2.第二种直接遍历找出波峰波谷的顶点数

### 代码

```cpp
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        /*
        if(nums.size() < 2){
            return nums.size();
        }     
        static const int begin = 0;
        static const int up    = 1;
        static const int down  = 2;
        int state = begin;
        int maxlength = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            switch(state){
                case begin:
                    if(nums[i] > nums[i-1]){
                        state = up;
                        maxlength ++;
                    }else if (nums[i] < nums[i-1]){
                        state = down;
                        maxlength ++;
                    }
                    break;
                case up:
                    if(nums[i] < nums[i-1]){
                        state = down;
                        maxlength ++;
                    }
                    break;
                case down:
                    if(nums[i] > nums[i-1]){
                        state = up;
                        maxlength ++;
                    }
                    break;

            }
        }
        return maxlength;
        */
        int n = nums.size();
        if(n < 2){
            return n;
        }
        int up = 1;
        int down = 1;
        for(int i = 1 ; i < n ;i++){
            if(nums[i] > nums[i-1]){
                up = down + 1;
            }
            if(nums[i] < nums[i-1]){
                down = up + 1;
            }
        }
        return max(up,down);
    }
};
```