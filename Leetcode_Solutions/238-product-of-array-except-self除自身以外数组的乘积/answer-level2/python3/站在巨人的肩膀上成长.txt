### 解题思路
起初进行各自分析结题，运用了哈希，建立数组索引与元素值的哈希表，再则遍历数组，把当前键值为本次循环的索引删除，之后取哈希里值列表，添加至一个新的列表中，然后再遍历列表里的元素求得值，返回结果，时间复杂度太高阶了，最后也不能运行出来，因为时间超时，大概这是选择java能跑，但是具体语法还不太熟悉，于是乎借鉴了题解里的大佬算法：
    ## 返回结果等于当前数的左积乘以由积。
### 代码

```python3
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        #利用哈希表 以数组的索引位键 以数组的元素值为值 来创建哈希
        #遍历哈希表 值不等于当前循环元素值就累积出最后的结果
        # length = len(nums)
        # hash = {i:nums[i] for i in range(length)}
        # res_list = []
        # for j in range(length):
        #     hash.pop(j)
        #     res_list.append(set(hash.values()))
        #     hash[j] = nums[j]
        # result = []
        # for res in res_list:
        #     ans = 1
        #     for re in res:
        #         ans *= re
        #     result.append(ans)
        # return result
        #以上是自己的尝试，借鉴大神们的算法，时间复杂度降为常数阶，右积与左积

        # int[] res = new int[nums.length];
        # int k = 1;
        # for(int i = 0; i < res.length; i++){
        #     res[i] = k;
        #     k = k * nums[i]; // 此时数组存储的是除去当前元素左边的元素乘积
        # }
        # k = 1;
        # for(int i = res.length - 1; i >= 0; i--){
        #     res[i] *= k; // k为该数右边的乘积。
        #     k *= nums[i]; // 此时数组等于左边的 * 该数右边的。
        # }
        # return res;
        # k = 1
        #左积
        length = len(nums)
        res = [1]*length
        k =1
        j = 1
        for i in range(length):
            res[i] = k
            k *= nums[i]
            
        for i in range(length):
            res[-(i+1)] *= j 
            j *= nums[-(i+1)]
        return res



```