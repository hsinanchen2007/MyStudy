### 解题思路
此处撰写解题思路

### 代码

```cpp
class KthLargest {
private:	
	multiset<int, greater<int>> m_ordered_set;
	int m_k;
public:
    KthLargest(int k, vector<int>& nums) {
    	m_k = k;
    	for(auto& iter:nums){
    		m_ordered_set.insert(iter);
    		if(m_ordered_set.size() > static_cast<size_t>(m_k)){
    			auto iter = m_ordered_set.begin();
    			std::advance(iter, m_ordered_set.size()-1);
    			m_ordered_set.erase(iter);
    		}
    	}
    }
    int add(int val) {
    	m_ordered_set.insert(val);
    	auto iter = m_ordered_set.begin();
    	std::advance(iter, m_k-1);
    	return *iter;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
```