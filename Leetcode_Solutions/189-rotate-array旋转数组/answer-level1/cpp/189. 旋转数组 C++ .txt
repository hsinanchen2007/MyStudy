

```cpp
class Solution {
public:

    //方法1： 每次向右旋转1个位置，旋转k次
    //时间复杂度 O(n * k) 空间复杂度 O(1)  超出时间限制
    void rotate(vector<int>& nums, int k) {

        if (nums.size() <= 1)
            return;

        if (k >= nums.size())
            k %= nums.size();

        if (k == 0)
            return;

        //原地旋转 一次一次的旋转 旋转k次
        for (int i = 0; i < k; ++i)
        {
            int last = nums.at(nums.size() - 1);
            int n = nums.size() - 1;
            for (int j = nums.size() - 2; j >= 0; --j)
            {
                nums.at(n) = nums.at(j);
                --n;
            }
            nums.at(n) = last;
        }
    }


    //方法2： 对数组进行拷贝，然后覆盖原数组
    //时间复杂度 O(n)  空间复杂度 O(n)
    void rotate(vector<int>& nums, int k) {

        if (nums.size() <= 1)
            return;

        if (k >= nums.size())
            k %= nums.size();

        if (k == 0)
            return;

        vector<int> tmp = nums;

        int index = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            index = i + k;
            if (index >= nums.size())
                index %= nums.size();
            nums.at(index) = tmp.at(i);
        }
    }


    //方法3：分三次反转  
    //时间复杂度 O(n)  空间复杂度 O(1)
    void reverse(vector<int>& nums, int begin, int end)
    {
        while (begin < end)
        {
            swap(nums.at(begin), nums.at(end));
            ++begin;
            --end;
        }
    }

    void rotate(vector<int>& nums, int k) {

        if (nums.size() <= 1)
            return;

        if (k >= nums.size())
            k %= nums.size();

        if (k == 0)
            return;

        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

    //调用C++ std::reverse
    void rotate(vector<int>& nums, int k) 
    {
        if(nums.size() <= 1)
        {
            return;
        }

        if (k >= nums.size())
            k %= nums.size();

        if(k == 0)
        {
            return;
        }

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    //方法 4：使用环状替换
    //时间复杂度 O(n)  空间复杂度 O(1)
    void rotate(vector<int>& nums, int k) {

        if (nums.size() <= 1)
            return;

        if (k >= nums.size())
            k %= nums.size();

        if (k == 0)
            return;

        int count = 0; //移动总次数 当移动总次数等于nums.size()即旋转结束

        for (int start = 0; count < nums.size(); start++) {
            int current = start; //每轮起始索引

            int prev = nums[start]; //每轮起始值

            do 
            {
                int next = (current + k) % nums.size();
                int temp = nums[next];
                nums[next] = prev;

                prev = temp;
                current = next;
                count++;
            } while (start != current); //本轮移动结束
        }
    }
};
```