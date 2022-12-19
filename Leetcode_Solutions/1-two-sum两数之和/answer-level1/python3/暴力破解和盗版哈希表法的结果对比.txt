### 一、解题思路
暴力破解大家应该都想得到的，使用hashmap（用字典实现）的思路是从别人那里copy过来的，
具体思路不想写了都一样，可以参考我的注释，就是代码实现上有小差别而已。


### 二、执行结果
   暴力破解——时间复杂度：O（N²）
![暴力破解.png](https://pic.leetcode-cn.com/7f9b00ad024e696ca8d89a8f00583d2297520a8287c3adba046067b129935a90-%E6%9A%B4%E5%8A%9B%E7%A0%B4%E8%A7%A3.png)

   哈希表法——时间复杂度：O（N）
![哈希表法.png](https://pic.leetcode-cn.com/a2fee4454dfd25effbc2e87d297b22b857d386748d3210ed585fbfe558fa9275-%E5%93%88%E5%B8%8C%E8%A1%A8%E6%B3%95.png)
   1、第二种的时间性能远高于第一种；
   2、这里还没搞清楚暴力破解的空间复杂度也这么高？急于下一道所以没有仔细去研究了。
   3、对于第二种方法，建立新的字典（哈希表）的时候，因为重复的数字不会产生什么影响，而键又不会重复，所以对这个新字典进行查找的话并不会发生哈希冲突，"if num2 in hashmap:"这一句的时间复杂度就是O（1）。


### 三、代码

```python3
# 暴力破解
'''
class Solution:
    def twoSum(self, nums, target) :

        for i in range(len(nums)):
            num1 = nums[i]
            num2 = target - num1
            try:
                #这里我直接返回索引，对列表里没有num2的异常作继续循环处理                  
                num2_index = nums.index(num2, i+1, )   
                return [i, num2_index]
                break;
                
            except ValueError as result:
                continue
'''

# 哈希表法（字典）
class Solution:
    def twoSum(self, nums, target) :
        hashmap = {}

        #enumerate将nums转化为
        for num1_index, num1 in enumerate(nums):    
            num2 = target - num1
            if num2 in hashmap:
                return [hashmap[num2], num1_index]

            #对于重复的数字我就不去改哈希表里的值，保证输出的索引是最前面的
            if num1 not in hashmap:
                #建立新的哈希表（字典），键为原表的数字，值为该数字的索引
                hashmap[num1] = num1_index    
            else:
                continue


```