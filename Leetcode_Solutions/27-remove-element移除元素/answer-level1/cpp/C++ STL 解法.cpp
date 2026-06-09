### 解题思路
用的是STL的函数，注意点是不要进入erase()的陷阱，就是注意迭代器的失效。具体可以参考https://www.cnblogs.com/skyofbitbit/p/3648841.html

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	if(nums.size()==0){
    		return 0;
		}
        for(vector<int>::iterator it=nums.begin();it!=nums.end();){
        	if(*it==val){
        		it=nums.erase(it);
			}
			else{
				++it;
			}
		}
		return (nums.size());
    }
};
```