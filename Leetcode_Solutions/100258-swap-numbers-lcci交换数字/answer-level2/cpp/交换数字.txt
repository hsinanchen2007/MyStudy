### 解题思路
简单思路。
判断语句是防止溢出

### 代码

```cpp
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        if(numbers[0]>0 && numbers[1]>0 || numbers[0]<0 && numbers[1]<0)
        {
            numbers[0]=-numbers[0];
            numbers[0]=numbers[0]+numbers[1];
            numbers[1]=numbers[1]-numbers[0];
            numbers[0]=numbers[0]+numbers[1];
        }
        else{
            numbers[0]=numbers[0]+numbers[1];
            numbers[1]=numbers[0]-numbers[1];
            numbers[0]=numbers[0]-numbers[1];
        }
        return numbers;
    }
};
```