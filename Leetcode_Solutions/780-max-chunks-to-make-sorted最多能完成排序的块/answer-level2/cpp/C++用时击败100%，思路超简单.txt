### 解题思路
详见代码注释

### 代码

```cpp
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	int len = arr.size();
    	int ans = 0;
    	int ma = arr[0]; // 记录当前的最大值
    	for (int i = 1; i < len; ++i) {
    		if (ma < i) { // 如果前面的最大值小于下标，说明可以分为一段
    			ans++;
    			ma = arr[i];
    		}
    		else {        // 否则更新最大值
    			ma = max(ma, arr[i]);
    		}
    	}
    	ans++;       // 别忘了加一，因为i只截止到len-1，所以len还没有算
    	return ans;
    }
};
```