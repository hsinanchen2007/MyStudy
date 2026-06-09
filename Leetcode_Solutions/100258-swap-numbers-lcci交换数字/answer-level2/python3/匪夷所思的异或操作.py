# 解题思路
假设2个变量分别为a和b，它们的值分别是v1，v2，只需执行3个操作就能将2个数互换，不使用额外空间，根据异或运算定义：
1个数异或自己一定等于0，1个数和0异或一定等于它自己
> 1. a=a^b=v1^v2
> 2. b=a^b=v1^v2^v2=v1
> 3. a=a^b=v1^v2^v1=v2

# 代码

```
    def swapNumbers(self, numbers: List[int]) -> List[int]:
        numbers[0]=numbers[0]^numbers[1]
        numbers[1]=numbers[0]^numbers[1]
        numbers[0]=numbers[0]^numbers[1]
        return numbers
```