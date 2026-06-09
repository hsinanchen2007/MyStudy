1、最短子数组的长度为元素x最后一次出现的索引lastIdx-第一次出现的索引firstIdx + 1
2、使用哈希映射存储数组元素x，以及其出现的次数cnt，第一次出现的索引firstIdx，以及其所在的子数组的长度length（通过lastIdx - firstIdx + 1获得）
3、遍历数组，更新cnt， firstIdx， 和length
4、遍历数组的过程中，不断比较cnt和length，比较最大cnt对应的最小length，就是最终需要的结果

```
struct valueNum {
    int cnt = 0;
    int firstIdx = -1;
    int length = 0;
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums)
    {
        unordered_map<int, valueNum> hashMap;
        int len = nums.size();
        int shortestLen = len;
        int maxCnt = 0;
        for (int i = 0; i < len; i++) {
            hashMap[nums[i]].cnt++;
            if (hashMap[nums[i]].firstIdx == -1) {
                hashMap[nums[i]].firstIdx = i;
            }
            hashMap[nums[i]].length = i - hashMap[nums[i]] + 1;

            if (maxCnt < hashMap[nums[i]].cnt) {
                maxCnt = hashMap[nums[i]].cnt;
                shortestLen = hashMap[nums[i]].length;
            } else if (maxCnt == hashMap[nums[i]].cnt) {
                shortestLen = min(shortestLen, hashMap[nums[i]].length);
            } else {
                continue;
            }
        }

        return shortestLen;
    }
};
```
