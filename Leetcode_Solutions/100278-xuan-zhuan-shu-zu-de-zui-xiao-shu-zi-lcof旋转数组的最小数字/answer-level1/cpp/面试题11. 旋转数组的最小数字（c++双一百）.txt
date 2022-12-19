### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minArray(vector<int>& numbers) {
        // 这个思路真的牛批，贼好理解
        int left = 0, right = numbers.size()-1;
        while(left < right)
        {
            int mid = (left + right) >> 1;
            // 如果mid大于right，那么乱序的一定在又半段，同时mid肯定不是最小的，所以left = mid+1
            if(numbers[mid] > numbers[right])
                left = mid + 1;
            // 如果mid小于right，那么乱序的一定在前半段，而mid有可能是最小的，所以right = mid
            else if(numbers[mid] < numbers[right])
                right = mid;
            // 这个else是mid == right的情况，所以让right-1，缩小范围，就是原来right的值为最小也没事，因为mid还保留着另一个最小值。
            else
                right = right - 1;
        }
        当循环退出时，left>=right, 而此时的left就是就小的那个数。
        return numbers[left];

        //这个代码可读性太差
        // int size = numbers.size();
        // if(size == 1)
        //     return numbers[0];
        // int left = 0, right = size - 1;
        
        // while(left < right)
        // {
        //     if(numbers[left] < numbers[right])
        //         return numbers[left];
        //     if(left + 1 == right)
        //         return numbers[left] < numbers[right] ? numbers[left] : numbers[right];
                
        //     int mid = (left + right) / 2;
        //     if(numbers[left] > numbers[mid])
        //     {
        //         if(left+1 == mid)
        //             return numbers[mid];
        //         right = mid;
        //         continue;
        //     }
        //     if(numbers[mid] > numbers[right])
        //     {
        //         if(mid+1 == right)
        //             return numbers[right];
        //         left = mid;
        //     }
        //     else
        //     {
        //         left = left + 1;
        //         right = right -1;
        //     }
        // }
        // return 0;

        //暴力法太慢了
        // for(int i = 0; i < numbers.size()-1; ++i)
        //     if(numbers[i] > numbers[i+1])
        //         return numbers[i+1];
        // return numbers[0];
    }
};
```