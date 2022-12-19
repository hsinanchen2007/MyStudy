### 解题思路
将数组二分，乱序=乱序+顺序||顺序加顺序，顺序=顺序加顺序，由此可见不管事乱序还是顺序数组，进行二分操作总是相同的。那么重点是最小值可能在哪？首先如果中间值大于最后值，那么一定在后半段（乱序子数组必含有最小值），反之一定在前半段（顺序子数组必然必然不可能在后段获得较小值）。那么就只有一个问题，相等怎么办？其实没有办法，相等的话无法判断，最小值的位置，但是可以明确的是最后的元素是无用的。为什么呢？若最后的元素是最小值，则中间元素也是最小值，信息未丢失。若最后元素不是最小值，那么最小值还在原数组内，无影响。所以相同元素果断去掉就行了。
再说下为什么叫减治变形，这个是二分法取右边界的写法，好处是大大减少了边界判断。(我在写题解的时候觉得左边界可能更好，让我试一下，等会发到后面)

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left=0;
        int right=numbers.size()-1;
        while(left<right){
            int mid=left+(right-left)/2;
            if(numbers[mid]>numbers[right]){
                left=mid+1;
            }
            else{
                if(numbers[mid]==numbers[right]) right--;
                else
                right=mid;
            }
        }
         return numbers[left];
    }
};
```