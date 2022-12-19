### 解题思路
1、直接排序
2、计数排序的思想（不排序）
3、桶排序的思想（不排序）

### 代码

```cpp

//桶
class Bucket
{
public:
    Bucket() : m_min(INT_MAX), m_max(0), m_empty(true) {}

    void min(int min_val)
    {
        m_min = std::min(m_min, min_val);
        m_empty = false;
    }

    int min() const
    {
        return m_min;
    }

    void max(int max_val)
    {
        m_max = std::max(m_max, max_val);
        m_empty = false;
    }

    int max() const
    {
        return m_max;
    }

    bool empty() const
    {
        return m_empty;
    }


private:
    int m_min;
    int m_max;

    bool m_empty;
};


class Solution {
public:
    //方法1、排序
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int max_gap = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            max_gap = std::max(nums.at(i + 1) - nums.at(i), max_gap);
        }
        return max_gap;
    }


    //方法2：计数排序的思想  注意：有测试用例超出内存限制
    int maximumGap(vector<int>& v) {

        if (v.empty())
          return 0;

        auto min_max = std::minmax_element(v.begin(), v.end());
        int min = *min_max.first;
        int max = *min_max.second;

        if(max == min)
            return 0;

        std::vector<int> v_new(max - min + 1);
        for (int i = 0; i < v.size(); ++i)
        {
            ++v_new.at(v.at(i) - min);
        }

        //相邻元素之间最大的差值 = 0值连续出现次数的最大值 + 1
        int count = 0;
        int max_count = 0;
        for(int i = 0; i < v_new.size(); ++i)
        {
            if(v_new.at(i) != 0)
            {
                max_count = std::max(count, max_count);
                count = 0;
            }
            else
            {
                ++count;
            }
        }

        return max_count + 1;
    }


    //方法3：桶排序的思想
    int maximumGap(vector<int>& v) {

        if (v.size() < 2)
            return 0;

        auto min_max = minmax_element(v.begin(), v.end());
        int min_val = *min_max.first;
        int max_val = *min_max.second;

        if (min_val == max_val)
            return 0;

        int bucket_count = v.size();  // n个桶
        vector<Bucket> buckets(bucket_count); 

        double interval = (double)(max_val - min_val) / (bucket_count - 1);

        //确定每个桶的最大、最小值
        for (int i = 0; i < v.size(); ++i)
        {
            // (int) (元素 - min) / 间隔
            int index = (int)(v.at(i) - min_val) / interval;

            buckets.at(index).max(v.at(i));
            buckets.at(index).min(v.at(i));
        }

        //找右侧非空桶中最小值
        int max_gap = 0;
        int left_max = buckets.at(0).max();

        for (int i = 1; i < bucket_count; ++i)
        {
            if(buckets.at(i).empty())
                continue;

            max_gap = std::max(buckets.at(i).min() - left_max, max_gap);
            left_max = buckets.at(i).max();
        }

        return max_gap;
    }
};
```