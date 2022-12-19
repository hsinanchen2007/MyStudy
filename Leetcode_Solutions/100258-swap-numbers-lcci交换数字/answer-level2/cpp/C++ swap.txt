```c++
class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        swap(numbers[0], numbers[1]);
        return numbers;
    }
};
```