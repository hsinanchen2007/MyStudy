### 解题思路
本题最开始想岔了，准备直接原地处理的，后来发现return的vector不算在额外的空间中。就好解很多。
**方法一：swap大法：**
再一次迭代中交换对应的值，将其放在对应的下标上。这个时候，只需要找和下标+1不匹配的数值就可以了。
**样例：**
[4,3,2,7,8,2,3,1];
swap之后：
[1,2,3,4,2,3,7,8];
这个时候发现下标4和5处对应的值不匹配，因此，重复的数据为2和3。

**方法二：自身取反**
每次都对其当前的值取绝对值，作为要使用的下标索引；
如果值为反，则说明之前已经被遍历过，放入vector中，这样就可以了。
**样例：**
[4,3,2,7,8,2,3,1];
取反操作：
数据展示顺序为：迭代次数；当前处理的值，当前处理值对应的索引；自身取反操作后的值。   
0: 4 7 -7
1: 3 2 -2
2: 2 3 -3
3: 7 1 -1
4: 8 1 -1
5: 2 -3 3
6: 1 4 -4
7: 1 -4 4
可以看到再第五次和第七次操作中，对应的值都是负数，分别再第二次和第六次迭代中被处理过。
因此，2和1就是本次数据中的重复数据。

### 代码

```cpp
class Solution {
public:
    //方法一：swap
    vector<int> findDuplicates(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            while(nums[i] != nums[nums[i]-1] && i+1 != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != i+1) res.push_back(nums[i]);
        }
        return res;
    }

    //方法二：自身取反
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            int temp = abs(nums[i]);
            if(nums[temp-1] < 0) res.push_back(temp);
            nums[temp-1] = -nums[temp-1];
        }
        return res;
    }
};
```

