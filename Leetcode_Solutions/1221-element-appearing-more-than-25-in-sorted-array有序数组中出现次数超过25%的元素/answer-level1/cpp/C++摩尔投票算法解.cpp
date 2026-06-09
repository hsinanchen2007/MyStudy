### 解题思路
分析：题目说有一个数出现的次数是整个数组的25%，也就是这个数是整个数组出现次数
最多的数，我们可以采用摩尔投票法统计数组元素个数 

### 代码

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
    	// 注意题目给出的数组长度范围 
        if (arr.size() == 1) return arr[0];
        int vo = 0, num, aLen = arr.size();
        // 开始投票 
        for (int i = 0; i < aLen; i++) {
        	// 更新当前元素 
        	if (vo == 0) {
        		num = arr[i];
			}
			// 更新票数 
			vo += arr[i] == num ? 1 : -1;
			// 如果当前元素的票数已经大于数组总长度了，说明当前元素就是所求元素 
			if (vo > aLen * 0.25) break;
		}
		return num;
    }
};
```