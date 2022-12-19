```
class Solution:
    ''' def removeElement(self, nums: List[int], val: int) -> int: '''
    def removeElement(self, nums, val):
        tmp = 0
        for i in range(0, len(nums)):
            if nums[i] == val: # 如果相等就跳过
                continue
            nums[tmp] = nums[i]
            tmp += 1

        return tmp

if __name__ == '__main__':
    s = Solution()
    print(s.removeElement([0,1,2,2,3,0,4,2], 2))
                        # [3,2,2,3]
```
