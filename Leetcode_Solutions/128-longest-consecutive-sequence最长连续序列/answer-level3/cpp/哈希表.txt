### 解题思路
O(N)的时间复杂度，说明查找的时间复杂度必须是O(1)。  
第一时间想到的就是哈希表。  
两次循环，第一次把数组值都塞进哈希表里面。  
第二次开始统计长度，从哈希表里面随意取一个值出来，向左右分别延伸，取到过的就直接从哈希表里面删除。  
哈希表里面没东西的时候最后的结果就出来了。  
16ms，马马虎虎吧。

### 代码

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> inList;
        for(size_t i=0;i<nums.size();i++){
            inList.insert(nums[i]);
        }
        int max = 0;
        int length = 0;
        int start = 0;
        int cur = 0;
        unordered_set<int>::iterator pos;
        while(inList.size()>0){
            length = 1;
            pos = inList.begin();
            start = *pos;
            inList.erase(pos);
            cur = start+1;
            pos = inList.find(cur);
            while(pos!=inList.end()){
                cur = *pos;
                inList.erase(pos);
                length++;
                pos = inList.find(cur+1);
            }
            cur = start-1;
            pos = inList.find(cur);
            while(pos!=inList.end()){
                cur = *pos;
                inList.erase(pos);
                length++;
                pos = inList.find(cur-1);
            }
            if(length > max){
                max = length;
            }
        }
        return max;
    }
};
```