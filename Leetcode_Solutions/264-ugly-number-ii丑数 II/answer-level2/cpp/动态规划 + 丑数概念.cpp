### 解题思路
注意丑数的求法，可以看下丑数1；
质数的概念是因数只有1和自己；
丑数的因数是只有2， 3， 5， 所以丑数只能是有2，3，5 相乘得到的。
然后通过动态规划的概念，记录当前状态值，然后推导下一个状态值。

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr;
        arr.push_back(1);
        int firstIndex = 0, secondIndex = 0, thirdIndex = 0;
        for (int i = 1; i < n; ){
            int firstNum = arr[firstIndex] * 2;
            int secondNum = arr[secondIndex] * 3;
            int thirdNum = arr[thirdIndex] * 5;
            if (firstNum <= secondNum && firstNum <= thirdNum) {
                if (std::find(arr.begin(), arr.end(), firstNum) == arr.end()) {
                    arr.push_back(firstNum);
                    i++;
                }
                firstIndex++;
            } else if (secondNum <= firstNum && secondNum <= thirdNum) {
                if (std::find(arr.begin(), arr.end(), secondNum) == arr.end()) {
                    arr.push_back(secondNum);
                    i++;
                }
                secondIndex++;
            } else if (thirdNum <= firstNum && thirdNum <= secondNum) {
                if (std::find(arr.begin(), arr.end(), thirdNum) == arr.end()) {
                    arr.push_back(thirdNum);
                    i++;
                }
                thirdIndex++;
            }
        }
        return arr[n - 1];
    }
};
```