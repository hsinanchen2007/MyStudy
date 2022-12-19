### 解题思路
官方题解那里学到的xor运算，xor运算：①a^a=0  ②a^0=a  ③XOR 满足交换律和结合律
所以我们只需要将所有的数进行 XOR 操作，得到那个唯一的数字。
时间O(n) 空间O(1)。

### 代码

```c
int singleNumber(int* nums, int numsSize){
    int result=0;
    for(int i=0;i<numsSize;i++){
        result = result^nums[i];
    }
    return result;
}
```