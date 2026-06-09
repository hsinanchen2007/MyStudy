### 解题思路
1.使用m_nums存储需要检索求和的数组，使用m_partial存储数组的前缀和。
2.因为需要包含i，j值，所以区间和只需要减去前缀在加上nums[i]的值即可。

### 代码

```cpp
class NumArray {
private:
    vector<int> m_nums;
    vector<int> m_partial;
public:
    NumArray(vector<int>& nums) : m_nums(nums){
        
        for (auto n : m_nums){
            if (m_partial.empty()){
                m_partial.push_back(n);
            }
            else{
                m_partial.push_back(n + m_partial.back());
            }
        }
    }

    int sumRange(int i, int j){
        return m_partial[j] - m_partial[i] + m_nums[i];
    }
};

```