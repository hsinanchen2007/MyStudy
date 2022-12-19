C++ 利用队列的性质 简单易懂

```cpp
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        queue<int> flipQueue;
        int count = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (!flipQueue.empty() && flipQueue.front() == i)
		flipQueue.pop();
	    if (A[i] && !(flipQueue.size() & 1) || !A[i] && flipQueue.size() & 1)
		continue;
	    else if (A.size() - i >= K) {
		flipQueue.push(i + K);
		++count;
	    }
	    else
		return -1;
	}
	return count;
    }
};
```