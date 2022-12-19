### 解题思路
问：解决问题需要几步
答：统共分三步
第一步：把arr1整理进map（key代表arr1元素，value代表其数量）
第二步：遍历arr2，并查找元素在map中的数量，并把这些数量的元素放入结果数组
第三步：遍历map，由于map在auto遍历时，本身就是有序的，还是按key增序，与题目相符，直接遍历非0的value即可

总结：
也就是使用map存储arr1的元素，再遍历arr1，按顺序把所有的arr1中相同的元素存入结果数组；
存完后，再把map中非0的元素再存一遍即可。此处还利用了map的有序性，不需要做其他操作。

### 时间复杂度
这样时间复现度类似2n的感觉，遍历arr1和arr2各一遍，遍历map一遍；

### 执行结果
最后执行结果双百：
执行用时 : 0 ms, 在所有 C++ 提交中击败了 100.00% 的用户
内存消耗 : 8 MB, 在所有 C++ 提交中击败了 100.00% 的用户


### 代码

```cpp
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        // 定义 “值：数量” 的map
        map<int, int> mp;
        int len1 = arr1.size();
        int len2 = arr2.size();
        // pos用于指示结果数组中的位置
        int pos = 0;
        vector<int> retArr = vector<int>(len1, 0);
        // 1.先把arr1整理进map，map默认会按key的值排列
        for (auto ar : arr1) {
            if (mp.find(ar) == mp.end()) {
                mp[ar] = 0;
            }
            mp[ar]++;
        }
        // 2.遍历arr2，然后查找map，如果找出来是多个，则存储多个即可
        // 同时已经遍历过的map，归0
        for (auto ar : arr2) {
            // 找出arr2的当前元素，在arr1中的数量
            int count = mp[ar];
            for (int j = 0; j < count; j++) {
                retArr[pos] = ar;
                pos++;
            }
            mp[ar] = 0;
        }
        // 3.此时，所有arr1中的元素已经按arr2的顺序排好，然后再排剩下的即可
        for (auto m : mp) {
            // 如果map中value为0，说明是arr2中的元素，忽略即可
            if (m.second == 0) {
                continue;
            }
            for (int k = 0; k < m.second; k++) {
                retArr[pos] = m.first;
                pos++;
            }
        }
        return retArr;
    }
};
```