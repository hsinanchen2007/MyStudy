## 思路
1. 从后向前遍历
2. 找到第一个不是9的数
3. 这个数后面所有数置0
4. 若这个数存在，自己加一
5. 若不存在，代表全是9,则最前面置1

## 代码
+ C++ 代码
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while (i >= 0 && digits[i] == 9 )
            i--;
        for (int j = i + 1; j < digits.size() ; j++ )
            digits[j] = 0;
        if (i == -1) digits.insert(digits.begin(),1);
        else digits[i] += 1;
        return digits;
    }
};
```
+ Python3 代码
```
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        i = len(digits) - 1
        while digits[i] == 9 and i >= 0:
            i = i - 1
        for j in range(i + 1,len(digits)):
            digits[j] = 0 
        if i == -1:
            digits.insert(0,1)
        else:
            digits[i] += 1
        return digits
```