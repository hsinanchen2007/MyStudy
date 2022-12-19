### 解题思路
排序 + 双指针

两数之和 可能会整数溢出  可改为求差  
如 [INT_MIN, 1, 2, INT_MAX] target = 1   
INT_MIN + 2 + INT_MAX = 1 等于 target， 但 2 + INT_MAX溢出


### 代码

```cpp
int threeSumClosest(vector<int>& nums, int target) {

    if (nums.size() < 3)
        return 0;

    sort(nums.begin(), nums.end());

    int abs_diff_min = INT_MAX; //target - c - b - a的绝对值最小值  绝对值最小 即最接近
    int sum = nums.at(0) + nums.at(1) + nums.at(2);

    for (int i = 0; i < nums.size() - 2; ++i)
    {
        if (nums.at(i) > 0 && nums.at(i) > target) //c > 0 且 c > target  a、b都大于c
            break;

        int target2 = target - nums.at(i); //两数之和的目标  target - c

        int left = i + 1;
        int right = (int)nums.size() - 1;

        while (left < right)
        {
            int target_a = target2 - nums.at(right); //target - c - b
            if (target_a == nums.at(left)) //相等 即 a + b + c == target 直接返回target
            {
                return target;
            }

            int abs_diff = abs(target_a - nums.at(left)); //target - c - b - a

            if (abs_diff < abs_diff_min)
            {
                abs_diff_min = abs_diff;
                sum = nums.at(i) + nums.at(left) + nums.at(right);
            }

            if (target_a > nums.at(left))
            {
                //++left;

                //a去重
                int tmp = nums.at(left);
                while (left < right && nums.at(left) == tmp)
                {
                    ++left;
                }
            }
            else
            {
                //--right;

                //b去重
                int tmp = nums.at(right);
                while (left < right && nums.at(right) == tmp)
                {
                    --right;
                }
            }
        }

        //c去重
        while (i < nums.size() - 2 && nums.at(i + 1) == nums.at(i))
        {
            ++i;
        }
    }

    return sum;
}
```