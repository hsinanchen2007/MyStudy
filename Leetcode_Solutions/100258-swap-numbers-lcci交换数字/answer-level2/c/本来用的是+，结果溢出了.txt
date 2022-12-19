### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/7a1bd78d99072c2c27429d3c9059c6f7c832642561dd8168ad378793de70cb88-image.png)

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* swapNumbers(int* numbers, int numbersSize, int* returnSize){
    numbers[0] = numbers[0] ^ numbers[1];
    numbers[1] = numbers[0] ^ numbers[1];
    numbers[0] = numbers[0] ^ numbers[1];

    *returnSize = 2;
    return numbers;
}
```