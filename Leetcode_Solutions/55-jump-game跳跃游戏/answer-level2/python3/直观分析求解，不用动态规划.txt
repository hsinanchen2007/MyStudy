```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        '''
        思路：
        我的思路是，如果在每一个0之前有一个位置最大跨度能超过这个0，那么这个0的位置就不会成为
        阻碍，所以我们只要判断每个0是否能被跨过就能判断是否能到终点。
        '''
        # 没有0的nums以及长度为1的nums一定能过.
        if len(nums) == 1 or 0 not in nums:
            return True
        else:
            left = 0
            # 用flag 标志判断是否能跨过0 那个位置。
            flag = 0
            while left < len(nums) and 0 in nums[left:]:
                # 注意，每次找0的位置时，要注意相对位置和绝对位置！
                index_0 = left + nums[left:].index(0)
                if index_0 == 0:
                    print('false')
                    break
                flag = 0
                # 判断每一个0之前的任一个位置的值的跨度
                for i in range(1,index_0+1):
                    # 注意这个0 的位置是否在nums最后！
                    if index_0 == len(nums)-1:
                        if nums[index_0-i] >= i:
                            flag = 1
                            left = index_0 + 1
                            break
                    elif nums[index_0-i] > i:
                        flag = 1
                        left = index_0 + 1
                        break
                if flag == 0:
                    break
            if flag == 1:
                return True
            else:
                return False
                
            
```
