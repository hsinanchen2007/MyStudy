### 解题思路
执行用时 :208 ms, 在所有 C++ 提交中击败了28.74%的用户
内存消耗 :55.5 MB, 在所有 C++ 提交中击败了100.00%的用户

### 代码

```cpp
	class MaxQueue {
		list<int> m_que;
		list<int> m_sorted_que;
		int m_max = -1;
	public:
		MaxQueue() {
		}
		int max_value() {
			m_max = !m_sorted_que.size() ? -1 : m_sorted_que.front();//O(1)
			return m_max;
		}
		void push_back(int value) {
			m_que.push_back(value);
			if (!m_sorted_que.size()) {
				m_sorted_que.insert(m_sorted_que.begin(), value);
				return;
			}
			bool insert_done = false;
			for (size_t i = 0; i < m_sorted_que.size(); ++i) {
				auto ind = m_sorted_que.begin();
				std::advance(ind, i);
				if (value > *ind) { //Best: O(1); Worst: O(N)
					m_sorted_que.insert(ind, value);
					insert_done = true;
					break;
				}
			}
			if (!insert_done) {
				m_sorted_que.insert(m_sorted_que.end(), value);
			}
		}
		int pop_front() {
			if (!m_que.size()) {
				return -1;
			}
			int front_val = m_que.front();
			m_que.pop_front();
			//Best: O(1); Worst: O(N)
			auto ind = std::find(m_sorted_que.begin(), m_sorted_que.end(), front_val);
			m_sorted_que.erase(ind);
			return front_val;
		}
	};
/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */
```