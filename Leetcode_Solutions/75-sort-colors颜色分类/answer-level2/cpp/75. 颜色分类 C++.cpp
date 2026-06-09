### 解题思路
此处撰写解题思路

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

    //快排 partition
    void sortColors(vector<int>& nums) {

        int less = -1;  //小于区域
        int greater = nums.size(); //大于区域

        int i = 0;

        while(i < greater) //抵达大于区域即停止
        {
            if (nums.at(i) < 1)
            {
                swap(nums.at(++less), nums.at(i));
                ++i;
            }
            else if (nums.at(i) > 1)
            {
                swap(nums.at(--greater), nums.at(i)); //交换后的nums.at(i) 与 1的关系  需要重新考察
            }
            else
            {
                ++i;
            }
        }
    }

};
```