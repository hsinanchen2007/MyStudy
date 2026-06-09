参考了他人的代码
[python3]

`

    class Solution(object):
        def commonChars(self, A):
            res=[]
            kk=set(A[0])
            for x in kk:
                small =min(bb.count(x) for bb in A )  #copy from others
            
                res.extend(small*x)   # donot use for , one step 
            return res 
`
small 就是在所有的字符串中，出现x 最少的次数， 用extend 就是为了不用for 循环了，一步搞定 ，参考了别人的代码，改进的。