class Solution:
    def countSubstrings(self, s: str) -> int:
        end_sum=0
        list1=list(s)
        n=len(list1)
        for i in range(0,n-1):
            left=i-1
            right=i+1
            while left>=0 and right<n:
                if list1[left]==list1[right]:
                    end_sum+=1
                    left-=1
                    right+=1
                else:
                    break
            left=i
            right=i+1
            while left>=0 and right<n:
                if list1[left]==list1[right]:
                    end_sum+=1
                    left-=1
                    right+=1
                else:
                    break
        return end_sum+n
看到题目不要想多了，就是一个字符串从中找出回文字符串，也就是取中间一个数，两边的数作比较，如果相等就+1，另外还有一种情况就是左右两个数作比较，相等计数就加1，还有就是最后返回的数一定要加上整个列表的长度，因为单个元素也就是一个回文字符串。                    
       
            