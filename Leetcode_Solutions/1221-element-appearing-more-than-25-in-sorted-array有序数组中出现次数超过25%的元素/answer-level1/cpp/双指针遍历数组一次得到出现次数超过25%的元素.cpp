### 解题思路
利用有序条件，使用双指针遍历一遍数组，对每个相等的子数组计数，如果大于25%则满足题意返回结果，否则再从该子数组右端重新开始计数。

后期补充:这个题我写得不好，对于有序的数组，涉及到查找，就应该去思考二分查找，降低时间复杂度，依次枚举太笨了。
### 复杂度
时间复杂度：$O(N)$
空间复杂度：$O(1)$

### 代码

```cpp
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int i = 0, j = 0;
        int n = arr.size();
        int limit = n >> 2;
        int count = 0;
        // 看似两个while，实际因为双指针，对每个元素只会遍历一次
        while(i < n){
            while(j < n && arr[i] == arr[j]){
                count++;
                j++;
            }
            if(count > limit){
                return arr[i];
            }else{
                i = j + 1;
                j = i;
                count = 0;
            }
        }
        return arr[i];
    }
};
```