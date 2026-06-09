### 解题思路
1.因为数组是有序的，所以使用双指针是非常高效的方法。
2.low指向数组的第一个元素，high指向数组中的最后一个元素。
3.若两个指针指向的元素相加的值小于target就使low指针向后进一位，反之则让high指针向前退一位。
4.当相加值等于target就返回两个指针加一的位置。
5.当low比high指针大时表明遍历了所有数字的结果依然没有找到结果因此返回[-1,-1]。

### 代码

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while(low < high){
            int sum = numbers[low] + numbers[high];
            if(sum == target){
                vector<int> result_yes = {low + 1,high + 1};
                return result_yes;
            }
            else if(sum < target){
                low++;
            }
            else{
                high--;
            }
        }
        
        vector<int> result_no(-1,2);
        return result_no;
    }
};
```