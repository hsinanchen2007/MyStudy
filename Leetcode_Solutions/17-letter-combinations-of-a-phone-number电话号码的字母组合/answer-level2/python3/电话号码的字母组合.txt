解题思路：

第一步：利用字典将数字与字母的关系保存起来

第二步：每一个组合的长度都是len(digits)，但需要根据digits[i]中将字母从字典中取出，利用循环往下遍历，并且每一次取值都是一次递归操作，递归的过程中判断目标字符串是否符合要求（递归结束的条件）

第三部：根据digits去判断是否要调用回溯函数（空字符直接返回[]）

    class Solution:
        def letterCombinations(self, digits: str) -> List[str]:
            '''
            #两种方法一样，下面的内存占用更小
            d = {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
            n = len(digits)
            ans = []
            res = []
            for i in digits:
                ans.append(d.get(i)) 
                
                
            def back(ans,temp):
                if len(ans)==0:
                    res.append(''.join(temp))
                    return 
                for i in range(len(ans[0])):
                    back(ans[1:],temp+[ans[0][i]])
                    
                    
            if ans:
                back(ans,[])
            else:
                return []
            return res
            '''

            d = {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
            n = len(digits)
            #ans = []
            res = []
            #for i in digits:
            #    ans.append(d.get(i)) 
                
            def back(digits,temp):
                if len(digits)==0:
                    res.append(''.join(temp))
                    return 
                for i in range(len(d.get(digits[0]))):
                    back(digits[1:],temp+[d.get(digits[0])[i]])
                    
                    
            if digits:
                back(digits,[])
            else:
                return []
            return res