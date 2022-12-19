### 解题思路
通过两数之和，三数之和这两个练习题，发现除了迭代遍历暴力计算法以外，采用哈希表的原理可以大大的减少复杂度，不过都没有解决这次练习里最难的去重问题。精选里第二个大佬排序后使用指针的方法比较有用，可以直接在n^2的复杂度内得到没有重复的所有解。

关于自己的方案，先找出所有的三个组，计算和之和，再去重，不适用于数组很多输入值的情况，做很多很多的比较，会超出时间限制和输出限制，不好不好。


### 代码

```python3
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # 方案1，迭代三轮for循环计算和，仍然有重复
        # 方案2：先两个一组，然后利用哈希思想找同伴,复杂度就调整为n^2，但是仍然没有去重
        '''
        res = []
        hash_tabel = {}
        for i in range(len(nums)-2):
            for j in range(i+1,len(nums)-1):
                if nums[j] in hash_tabel:
                    out1 = [nums[j]]
                    out1.extend(hash_tabel[nums[j]])
                    res.append(out1)
                    del hash_tabel[nums[j]]
                    # 这里要清除是因为，针对nums换了第一个数和第二个数之后，可能缺的那第三个数一样
                else:
                    mark = 0 - nums[i] - nums[j]
                    hash_tabel[mark] = [nums[i],nums[j]]
                    # 首先遍历第一个数，然后遍历第二个数得到需要的第三个结果，第二轮再看后面的数
                    # 时，就判断这个数是否是之前看过需要的第三个数
        return res
        '''

        # 方案3 排序后进行指针挪位，去掉重复元素
        
        nums.sort()
        res = []
        length = len(nums)
        for i in range(length-2):
            # 如果排序后已经大于0，说明不可能有加起来为0的结果，就返回当前收集好的res
            if nums[i]>0:
                return res
            # 对排序后的元素在第一遍遍历取第一个数的时候就不取重复，可以保证不取第二次    
            if i>0 and nums[i]==nums[i-1]:
                continue
            
            L = i+1
            R = length-1

            while(L<R):
                if nums[i]+nums[L]+nums[R]==0:
                    print(nums[i],nums[L],nums[R])
                    res.append([nums[i],nums[L],nums[R]])
                    while(L<R and nums[L+1]==nums[L]):
                        L=L+1
                    while(L<R and nums[R-1]==nums[R]):
                        R=R-1
                    L=L+1  # 注意这两步很容易漏掉，上面两个while是过滤重复出现的数
                    R=R-1  # 如果没有以上两种情况，那么左右指针都应该移动
                elif nums[i]+nums[L]+nums[R]>0:
                    R=R-1
                else:
                    L=L+1
        return res
        
        # 我的方案：得到所有的三个元素的组合选项，然后计算和是否为0
        # 但是这样子会有重复的，使用设置标志位的方法判断结果列表是是否有重复，已解决去重
        
        # from itertools import combinations
        # out = list(combinations(nums,3))
        # res = []
        # for i in range(len(out)):
        #     sum_all = out[i][0]+out[i][1]+out[i][2]
        #     if sum_all == 0:
        #         res.append(out[i])
        
        # res_out = []  # 去重
        # for i in range(len(res)):
        #     flag = False # 默认每一个是独一无二的
        #     for j in range(i+1,len(res)):
        #         is_all_in = [True for c in res[i] if c not in res[j]] # res[i]没有包含在j里 
        #         if not is_all_in and set(res[i])==set(res[j]) :
        #             # 关于不包含，要除去有相同元素的情况，[0,0,0]是不包含在[0,-3,3]里面的
        #             #print('包含在里面，跳过')
        #             flag = True
        #             break

        #         # else:
        #         #     print('不包含在里面，继续看下一个')
        #     if not flag:
        #         res_out.append(res[i])
        
        # return res_out



    
        

```