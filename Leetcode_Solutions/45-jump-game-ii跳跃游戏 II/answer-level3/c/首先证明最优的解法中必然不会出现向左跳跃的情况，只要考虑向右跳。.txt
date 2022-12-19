"""
跳跃游戏 
第一次肯定只能向左边跳

最少步数的过程为s

假设s中间某种过程

先在b
左跳a 然后右跳c

因为是从最左边开起跳 然后到b 无论中间多复杂 无论b的上一个点在何处 
都存在小于等于b到步数的方法 直接到a 然后到c 使得步数减少 

对于b的上一步b0 在a 右边的情况 总有b0的上一步b1 b2 b3... 出现在a左边 那么直接 bi 到 a 即可省下下i+1步
否则a 是第一个点 那直接a 到 c  不然总有办法 即便 b 
a  b0  b 
a  b b0 
a  b b0

b0 a b  那么b0直接到a 再到c
这样就省下了到b这一步

所以 最终解法的s 中** 一定不存在向左的跳跃 所以只要考虑向右跳跃**

再次假设最少步数的过程为s
其中有 a b c
从a 到b 在到c的过程 必定是向右跳的过程

如果一开始在a处 到b为一步 到c 为第二步。 a绝对没有办法1步到c 不然就不是最短过程

所以考虑 从a位置跳跃两步后到达的最远位置。可以证明 最远位置到a之间 不包括a 这其中的任何一个点，都是可以在两步以内到达的。
如果我找到了这样的若干方法，如a b1 c1, a b2 c2 ,......
那么一定有c1=c2=...cn >= c
一定有 c>b1 c>b2 ....c>bn

那么c点也是可以两步到达的。这若干方法，就是等价于最少步数过程s的方法。只需要取得其中一种即可。也就是a调到b1,b2,b3,......,bn 中的任何一个即可


向右跳跃的过程 下一个点应当使得下一个点的下一个点的位置最远


算法描述：

只要当前点的下标小于最后一个位置的下标
就可以起跳

    如果当前位置直接可到最后位置 +1计数退出

    考察向右的最大可行方法 即两步可到最远处的解法
    则两步以内可以到达该点到最远点之间包括最远点 不包括该点的所有点

    跳到这个两步最大可行的第一步。计数+1  循环 

就比如 4 3 1 2 1 ...... 
如果4 到 3 下次最多到末尾的1
如果4 到 2 或者最后的1  下次可以到后面的数
"""
class Solution:
    def jump(self, nums) -> int:
        count = 0
        present_index = 0
        max_index = len(nums)-1
        while(present_index<max_index):
            if present_index+nums[present_index]>=max_index:
                count +=1
                break
            i_buf = present_index+1 #后面操作可以保证绝对不到0点 因为一定有越过0点办法存在 不然与题目必有解矛盾
            most_index = 0
            for i in range(present_index+1,present_index+nums[present_index]+1,1):
                if i+nums[i]>most_index:
                    most_index = i+nums[i]
                    i_buf = i
            count += 1
            present_index = i_buf
        return count


s = Solution()
a = [2,3,1,1,4]
print(s.jump(a))