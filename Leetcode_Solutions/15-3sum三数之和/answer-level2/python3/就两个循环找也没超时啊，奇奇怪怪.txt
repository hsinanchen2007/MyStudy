就两个循环找也没超时啊，奇奇怪怪，set去重。
```
class Solution:
    def threeSum(self, nums: list):
        result = set()
        nums_dic = {}
        for ele in nums:
            if ele in nums_dic.keys():
                nums_dic[ele] += 1
            else:
                nums_dic[ele] = 1
        for i in nums_dic.keys():
            for j in nums_dic.keys():
                if (0-i-j) in nums_dic:
                    temp_list = [i, j, 0-i-j]
                    temp_list.sort()
                    temp_dic, temp_flag = {}, True
                    for ele in temp_list:
                        temp_dic[ele] = temp_list.count(ele)
                    for temp_key in temp_dic.keys():
                        if temp_dic[temp_key] > nums_dic[temp_key]:
                            temp_flag = False
                    if temp_flag:
                        result.add(tuple(temp_list))
        result_list = []
        for _ in result:
            result_list.append(list(_))
        return result_list
```
