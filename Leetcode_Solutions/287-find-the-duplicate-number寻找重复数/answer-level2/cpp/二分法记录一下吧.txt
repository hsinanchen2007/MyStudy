违反规定一的代码。。。。开始做的时候忘记只读了
```
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         for(int i=0;i<nums.size();i++){
//             if(nums[abs(nums[i])]<0)return abs(nums[i]);
//             else nums[abs(nums[i])]=0-nums[abs(nums[i])];
//         }
//         return 0;
//     }
// };

```

二分法，不多说了，就是记录一下，题解区有大佬已经写的很好了。
```

class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while (left < right) {
            int mid = (left + right) >> 1;
            int counter = 0;
            for (int num:nums) {
                if (num <= mid) {
                    counter++;
                }
            }

            if (counter > mid) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
```
