### 解题思路
此处撰写解题思路
先将对应的数字转成二维数组，比如234,转成[["abc"],["def],["ghi"]]
之后for循环两次，第一次循环外面的数组，第二次循环里面的数据，然后将["abc"]和["def"]里的字母两两合并为['ad', 'bd', 'cd', 'ae', 'be', 'ce', 'af', 'bf', 'cf'],保存起来，在下一个循环里将['ad', 'bd', 'cd', 'ae', 'be', 'ce', 'af', 'bf', 'cf']和["ghi"]里的字母两两合并，最终输出结果

### 代码

```python
class Solution(object):
    map = {"2":"abc", "3":"def", "4":"ghi", "5":"jkl", "6":"mno", "7":"pqrs", "8":"tuv", "9":"wxyz"}
    def letterCombinations(self, digits):
        if "1" in digits or "0" in digits:
            return []
        else:
            list = []
            nums = self.getTranslatedList(digits)
            for i in range(len(nums)):
                if i == 0:
                    list = nums[i]
                    continue
                tmp_list = []
                for j in range(len(nums[i])):
                    for y in range(len(list)):
                        tmp_list.append(list[y] + nums[i][j])
                        if j + 1 == len(nums[i]) and y + 1 == len(list):
                            list = tmp_list
        if len(list) == 3 or len(list):
            result = []
            for e in list:
                result.append(e)
            return result
        return list

    def getTranslatedList(self, digits):
        b_list = []
        for num in digits:
            b_list.append(self.map[num])
        return b_list
```