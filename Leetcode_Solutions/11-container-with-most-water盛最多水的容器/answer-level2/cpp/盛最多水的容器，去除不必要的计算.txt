### 解题思路
用两个指针从两边向中间逼近，直到两个指针相交，每次取两者指向元素小的那一个作为桶高，
如果左边（k）小，计算出面积，然后向右依次遍历，直到找到比k角标上值大的，然后再继续后续操作

### 代码

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int begin =0;
        int end = height.size() -1;
        int max = 0;
        int temp = 0;
        int k = 0;
        while (begin < end) {
            max = max > temp ? max : temp;
            if (height[begin] > height[end]) {
                k = end;
                temp = height[end] * (end - begin);
// 找到比height[k]大的值，并且end必须大于begin
                do {
                    end--;
                }while(height[end] <= height[k] && end > begin);   
            } else {
                k = begin;
                temp = height[begin] * (end - begin);
// 找到比height[k]大的值，并且end必须大于begin
                do {
                    begin++;
                }while(height[begin] <= height[k] && begin < end);
            } 
        }
        max = max > temp ? max : temp;
        return max;
    }
};
```