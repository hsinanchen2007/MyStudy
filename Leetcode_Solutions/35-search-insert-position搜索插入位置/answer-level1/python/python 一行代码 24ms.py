class Solution(object):
    def searchInsert(self, nums, target):
        return (lambda n, t: (lambda f, n, t, s, e, m: f(f, n, t, s, e, m))((lambda f, n, t, s, e, m: s if s > e else m if t == n[m] else f(f, n, t, s, m-1, (s+m-1)//2) if t < n[m] else f(f, n, t, m+1, e, (m+1+e)//2)), n, t, 0, len(n)-1, (len(n)-1)//2))(nums,target)


二分+递归的解法, 用 lambda 写到一行里面去了. 

具体解释如下:

http://ohmycat.me/2019/12/24/how-to-write-functional-programming.html