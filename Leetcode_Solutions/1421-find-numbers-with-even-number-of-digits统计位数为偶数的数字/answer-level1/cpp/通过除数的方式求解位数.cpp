### 解题思路
题目要求是十进制数求位数,所以最先想到的思路就是依次除进制数10取商,然后再除,获取到做除法的次数即为位数,
此处可以使用递归,也可以使用for循环, 如果是其他进制数,只需要修改结束条件和除数.
题目给的条件 1< num < 10^5, 所以最多循环五次,不用考虑性能问题导致时间超时.
默认位数是值1 递归结束条件就是 是否 < 10,递归体就是将当前位和之前的位数求和.求解即可 

### 代码

```cpp
class Solution {
public:

    int getLengthOfNumber (int num) {
    int lenght = 1;
    if (num < 10) {
        return lenght;
    }

    num = num / 10;
    lenght =  getLengthOfNumber(num) + lenght;
    return lenght;
}

    int findNumbers(vector<int>& nums) {
        int num = 0;
        
        int length = (int)nums.size();
        for (int i = 0 ; i < length; i++) {
            int length = getLengthOfNumber(nums[i]);
            if (length % 2 == 0) {
                num++;
            }
        }
        
        return num;
    }
};
```