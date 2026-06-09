![image.png](https://pic.leetcode-cn.com/6bdf6c7c2cf5addf03ab378fa77061dac98c6408e6bbca11a3d6a8afeebe3f96-image.png)

###### 不需要求出具体的2进制是多少。我们只需要求出输入数据转化为2进制有多少位即可
# 
#### 具体思想如下，我们来看个规律
1. 输出数字是5的话，转换成2进制有3位
2. 3位二进制的最大值为111，即十进制的7
3. 补码 = `111 - 101 = 010` （其实就是` 7 - 5 = 2` ）
4. 7怎么来的呢？`7 = 8 - 1 `
5. 8怎么来的呢？因为我们上面知道了5转换为二进制有3位，而2的3次方=8
6. 所以，我们只需要知道一个信息就可以求出补码，而不需要具体求出5对应的2进制是多少，更不用二进制计算差值再转为十进制
7. 这个信息就是：输出数据转化为二进制有多少位
# 
# 
#### 有了思路再来撸代码就很方便了
##### 1、利用递归的方法求出输入2进制有x位
##### 2、计算x位二进制数的最大值（2的x次方 -1 ）
# 
#### 完整代码
```python
class Solution:
    def findComplement(self, num: int) -> int:
        if num == 0:
            return 1
        # 利用递归获取该10进制转化为二进制的位数
        def get_bin_nums(num):
            # 递归终止条件
            if num == 0:  # 如果余数为0，则直接返回0位
                return 0
            if num == 1:  # 如果余数是1，则返回1位
                return 1
            num = num // 2
            return get_bin_nums(num) + 1
        
        bin_nums = get_bin_nums(num) # 获取到位数之后，求出该位二进制对应的最大值（2的x次方-1）
        bin_max = 2 ** bin_nums - 1
        return bin_max - num  # 最后十进制的补码就是对应二进制的最大值减去输入的值
```