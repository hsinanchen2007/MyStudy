### 解题思路
- 核心要点：从1开始的第一个i位数是pow(10,i-1)，i位数所占位数=9\*firstNum\*i，用n迭代减一位数、二位数…的占位，找到n对应的是几位数，然后firstNum+n/i求出对应是哪个i位数，n%i找出它是这个i位数的第几位数字
- 执行用时 :4 ms, 在所有 C++ 提交中击败了48.39%的用户
- 内存消耗 :6 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        n--;
        for(int i=1;i<11;i++){
            long firstNum=pow(10,i-1);
            if(n<9*firstNum*i){
                return (int)to_string(firstNum+n/i)[n%i]-'0';
            }
            n-=9*firstNum*i;
        }
        return 0;
    }
};
```