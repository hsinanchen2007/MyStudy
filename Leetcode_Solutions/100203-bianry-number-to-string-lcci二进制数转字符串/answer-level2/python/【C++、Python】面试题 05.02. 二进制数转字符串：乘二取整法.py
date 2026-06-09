### 乘二取整法 ###
#### 思路 ####
- 本题考察的知识点是十进制小数转二进制小数，应用常规方法乘二取整即可求解
#### 算法 ####
- `res`初始化为`"0."`
- 在满足位数要求的情况下，当`num`大于`0`时，循环
  - 先将`num`乘以`2`，将乘积赋值给`num`
  - 取`num`的个位（`0`或`1`），将对应的字符加入`res`的末尾
  - 截取`num`的小数部分，作为`num`的新值
- 最后判断，当`num`为`0`时（即`res`已经精确地表达了`num`），返回`res`
- 否则，返回`"ERROR"`
#### 代码 ####
```cpp []
class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        int i = 30; // 若 "0." 计为两位，i 初始化为 30，若计为 1 位，初始化为 31
        while (num > 0 && i--) {
            num *= 2;
            if (num >= 1) {
                res.push_back('1');
                --num;
            }
            else res.push_back('0');
        }
        return num != 0 ? "ERROR" : res;
    }
};
```
```python []
class Solution:
    def printBin(self, num: float) -> str:
        res, i = "0.", 30
        while num > 0 and i:
            num *= 2
            if num >= 1:
                res += '1'
                num -= 1
            else:
                res += '0'
            i -= 1
        return res if not num else "ERROR"
```
#### 复杂度分析 ####
- 时间复杂度 $O(1)$，循环次数上限是常数
- 空间复杂度 $O(1)$，只使用常数级的辅助空间
