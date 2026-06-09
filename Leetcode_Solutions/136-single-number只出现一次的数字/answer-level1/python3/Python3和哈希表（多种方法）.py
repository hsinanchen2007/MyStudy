        class Solution:
            def singleNumber(self, nums: List[int]) -> int:
                #一、用字典统计元素个数
                dict = {}
                
                #方法一
                for i in nums:
                    dict[i] = dict.get(i, 0) + 1
                    
                #方法二
                # for i in nums:
                #     if i not in dict:
                #         dict[i] = 1
                #     else:
                #         dict[i] += 1
                
                #二、找出只出现一次的元素
                
                #方法一
                return list(dict.keys())[list(dict.values()).index(1)]
            
                #方法二
                # new_dict = {v:k for k,v in dict.items()}
                # return new_dict[1]
            
                #方法三
                # return [key for key, value in dict.items() if value == 1]
                
                # 或
                # for key,value in dict.items():
                #     if value == 1:
                #         return key