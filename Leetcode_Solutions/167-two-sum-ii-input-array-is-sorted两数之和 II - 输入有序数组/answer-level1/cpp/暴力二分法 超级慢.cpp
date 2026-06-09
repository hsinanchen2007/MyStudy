![image.png](https://pic.leetcode-cn.com/8123661903a819a2d737482b8a5991ddd8433da24f2eb72784ed03e27798882b-image.png)

### 解题思路
1、因为是有序，所以可以用二分法
2、定一个数作为index1，在这个数后面用二分法查找index2，找不到的话换一个index1，循环直到找到结果。

###代码思路
1、循环遍历整个数组，将当前遍历的这个数定为index1，在index1后的数字用二分法寻找index2；
2、如果当前二分找不到合适的index2，更新index1；
3、若找到index2，标志flag变为true，跳出while和for循环，得出结果。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if(numbers.size() == 0) return result;

        int index1;
        int index2;
        for(int i = 0; i < numbers.size() - 1; i++){
            index1 = i;
            int begin = i + 1;
            int end = numbers.size() - 1;
            bool flag = false;
            while(begin <= end){
                int mid = (begin + end) / 2;
                if(numbers[index1] + numbers[mid] == target){
                    flag = true;
                    index2 = mid;
                    break;
                }
                if(numbers[index1] + numbers[mid] > target) end = mid - 1;
                if(numbers[index1] + numbers[mid] < target) begin = mid + 1;
            } 
            if(flag) break;
        }
        result.push_back(index1 + 1);
        result.push_back(index2 + 1);

        return result;
    }
};
```