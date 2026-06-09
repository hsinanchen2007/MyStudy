```

/***
*
step1: 找出重复数
  每遍历数组一个数，判断数组中以这个数为下标 - 1对应的数是否小于0，如果小于0，该数即为重复数。否则，将以此数为下标的数变乘以-1 
step2: 找出丢失的数
  在step1的基础上遍历数组，找到值大于0的元素的下标，即为缺失的数
1th run: 24ms
2th run: 36ms
3rd run: 28ms
 
*/
class Solution1 {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ret(2);
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[abs(nums[i]) - 1] < 0)
                ret[0] = abs(nums[i]);
            else 
                nums[abs(nums[i]) - 1] *= -1;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0){
                ret[1] = i + 1;
                break;
            }
        }
        return ret;
    }
};


/**
该方法在Solution1的基础上，
运用数列求和的数学技巧，直接求出1到n的数列和，再减去错误集合除去非重复数的所有数的和，即得到丢失的数的和

1th run: 36ms
2th run: 36ms
3rd run: 28ms
*/

class Solution {

public:
    vector<int> findErrorNums(vector<int> & nums){
        vector<int> ret(2);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[abs(nums[i]) - 1] < 0)
            {
                ret[0] = abs(nums[i]);
            }
            else 
            {
                nums[abs(nums[i]) - 1] *= -1;
                sum += abs(nums[i]); 
            }
        }
        ret[1] = (((nums.size() + 1) * nums.size()) /2) - sum;
        return ret;
    }
};
```
