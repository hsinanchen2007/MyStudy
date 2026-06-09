### 解题思路
类似快速排序 partition的单边循环法 设定小于1的界，大于1的界

### 代码

```cpp
class Solution {
public:

    // void sortColors(vector<int>& nums) {

    //     sort(nums.begin(), nums.end());
    // }


    //计数排序
    // void sortColors(vector<int>& nums) {

    //     vector<int> v(3);
    //     for(int i = 0; i < nums.size(); ++i)
    //     {
    //         ++v.at(nums.at(i));
    //     }

    //     int i = 0;
    //     while(v.at(0) > 0)
    //     {
    //         nums.at(i++) = 0;
    //         --v.at(0);
    //     }

    //     while(v.at(1) > 0)
    //     {
    //         nums.at(i++) = 1;
    //         --v.at(1);
    //     }

    //     while(v.at(2) > 0)
    //     {
    //         nums.at(i++) = 2;
    //         --v.at(2);
    //     }
    // }


    void sortColors(vector<int>& nums) {

        int left = -1;
        int right = nums.size();

        int i = 0;

        while(i < right)
        {
            if (nums.at(i) < 1)
            {
                ++left;
                swap(nums.at(left), nums.at(i));
            }
            else if (nums.at(i) > 1)
            {
                --right;
                swap(nums.at(right), nums.at(i));

                //交换后的nums.at(i) 与 1的关系  需要重新考察
                continue;
            }
            ++i;
        }
    }

};
```