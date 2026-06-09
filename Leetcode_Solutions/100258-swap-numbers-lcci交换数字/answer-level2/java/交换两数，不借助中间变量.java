### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] swapNumbers(int[] numbers) {
        numbers[0]=numbers[0]+numbers[1];//将第一个数变为两数之和
        numbers[1]=numbers[0]-numbers[1];//将第二个数变为原来第一个数
        numbers[0]=numbers[0]-numbers[1];
        return numbers;
    }
}
```