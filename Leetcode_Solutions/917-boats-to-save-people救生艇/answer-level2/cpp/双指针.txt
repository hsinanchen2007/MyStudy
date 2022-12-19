### 解题思路
由于一艘船最多可坐两个人，使用双指针代码简单。首先将数组进行排序，指针left下标为0，指针right指向数组末尾，对left和right进行比较，如果left和right数值相加不大于limit，则船数加一，left右移；然后将不小于right左移，船数加一。最后要判断left和right的关系，如果相等，表示还剩一个人，船数只能加一。

### 代码

```cpp
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int len = people.size(), count = 0;
        if(len < 2) //如果人数小于2，直接输出
        return len;
        sort(people.begin(), people.end());
        if(people[1] >= limit)  //如果倒数第二重的人的重量大于等于船的承重量，只能一人坐一艘
        return len;
        int left = 0, right = len - 1;
        while(left < right)
        {
            if(people[left] + people[right] <= limit)  
                left ++;
            right --;  //不论两人重量和与船承重量的关系，right指针都要左移
            count ++;
        }
        if(left == right)  //表示还有一个人没坐船
        count ++;
        return count;
    }
};
```