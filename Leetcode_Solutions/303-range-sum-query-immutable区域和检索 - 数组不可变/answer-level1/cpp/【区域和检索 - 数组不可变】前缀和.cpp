### 思路
1. 因为要多次查询，所以保存一个前缀和数组
2. 需要查询 `i - j`时，结果等于 `总和 - i 之前 - (总和 - j 之后)` → `j 之后 - i 之前`
3. 因为包含 `i` 和 `j` ，注意加上 `i` 的值 → `j 之后 - i 之前 + i`

### 答题
```C++
class NumArray {
public:
    NumArray(vector<int>& nums) : m_nums(nums)
    {
        partial_sum(m_nums.begin(), m_nums.end(), back_inserter(m_partial));
    }
    
    int sumRange(int i, int j) 
    {
        return m_partial[j] - m_partial[i] + m_nums[i];
    }
    
private:
    vector<int> m_nums;
    vector<int> m_partial;
};
```

如果要自己实现前缀和
```C++
class NumArray {
public:
    NumArray(vector<int>& nums) : m_nums(nums)
    {
        //partial_sum(m_nums.begin(), m_nums.end(), back_inserter(m_partial));
        for (auto n : m_nums)
        {
            if (m_partial.empty())
            {
                m_partial.push_back(n);
            }
            else
            {
                m_partial.push_back(n + m_partial.back());
            }
        }
    }
    
    int sumRange(int i, int j) 
    {
        return m_partial[j] - m_partial[i] + m_nums[i];
    }
    
private:
    vector<int> m_nums;
    vector<int> m_partial;
};
```


### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

