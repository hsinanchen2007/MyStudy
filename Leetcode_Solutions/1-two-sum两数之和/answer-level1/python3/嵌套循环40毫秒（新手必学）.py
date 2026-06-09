既然需要里面的任意两个数相加  就可以用l嵌套的for循环 在用两个额外的b整数变量记录位置  既可以轻松的找到所有符合的答案  耗时40毫秒
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        a=0
        b=0
        for i in nums:
            for m in nums:
                if i+m==target:
                    print([a,b])
                b+=1
            a+=1