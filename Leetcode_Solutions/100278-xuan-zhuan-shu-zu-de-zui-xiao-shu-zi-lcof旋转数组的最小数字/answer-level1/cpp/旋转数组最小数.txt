### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int l = 0; 
        int r = numbers.size()-1;

        while(l < r){
        int mid = (l + r) / 2;
        if(numbers[r] < numbers[mid]){
            l = mid + 1;
        }else if(numbers[r] > numbers[mid]){
            r = mid;
        }else{
            r--;
        }
        }
        return numbers[l];
    }
};
```
其实就是查找数组中最小的数，但是有一点特别，他的原始数组是递增数组，可以利用这个特点，在结合二分的思想，来解题，注意边界问题；