### 解题思路
参考别人的思路，写一下自己的理解。首先采用的是顺序排序法二分法的思想。但是这个题不是单一的顺序，而是两个顺序数组的叠加。所以从找最小点的思路，转换成了排除哪些点不是最小点。
1.如果numbers[mid]大于了numbers[right]，那么mid本身肯定不是最小点，同时，最小点应该在[mid+1,right]。
2.如果numbers[mid]小于了numbers[right]，那么mid本身有可能是最小点，所以，最小点应该在[left，mid]。
3.如果numbers[mid]等于了numbers[right]，那么最小点位于哪里未知。right--排除不可能点。
   

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
    int mid , left=0 , right=numbers.size()-1;
    while(left < right)
    {
        mid = (right+left)/2;
        if(numbers[mid] > numbers[right])
            left=mid+1;
        else if(numbers[mid] < numbers[right])
            right=mid;
        else
            right--;
    }
    return numbers[right];
    }
};
```