![image.png](https://pic.leetcode-cn.com/b2722d5617e244a52dfd767add47a477b69cc7448010ee2ae78f194da82e7945-image.png)

看了大多数人都用hash，把所有key塞进去，感觉这样空间复杂度很高，很暴力。这里的解题思路如下：
# 
##### 1、申请一个包含两个元素的数组tmp，tmp[0]表示某个单词，tmp[1]表示这个单词连续出现的次数
##### 2、依次遍历每个元素，如果tmp[0]与这个元素相等，则tmp[1] + 1 
##### 3、如果当前元素与tmp[0]不相等，则组装输出字符串并把tmp[0] = 当前元素，tmp[1] = 1
# 
```python
def compress_string(input):
    if len(input) <= 2:
        return input
    output = ""
    tmp = [input[0], 1]  # 第一个元素是key，第二个元素计数
    for i in range(1, len(input)):
        if input[i] == tmp[0]:  # 判断当前元素与tmp里的是否一致
            tmp[1] += 1  # 一致的话直接计数器+1
            continue
        output += tmp[0] + str(tmp[1])  # 不一致的话直接把当前tmp里的key和value拼接到output
        tmp[0] = input[i]  # 同时清空tmp里的key和value
        tmp[1] = 1
    output += tmp[0] + str(tmp[1])
    if len(output) >= len(input):
        return input
    return output
```
