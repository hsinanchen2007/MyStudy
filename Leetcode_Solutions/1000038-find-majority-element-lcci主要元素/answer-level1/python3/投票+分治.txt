### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if not nums:
            return 

        # provit=nums[0]
        # count=1
        # for num in nums[1:]:
        #     if count==0:
        #         provit=num
        #         count+=1
        #     else:
        #         count+=1 if num==provit else -1
        # return provit if count>0 else -1

        def majElem(left, right):
            if left==right:
                return nums[left]
            
            mid=(left+right)//2
            leftElem=majElem(left, mid)
            rightElem=majElem(mid+1, right)

            if leftElem==rightElem:
                return leftElem
            leftCnt=sum(1 for i in range(left, right+1) if nums[i]==leftElem)
            rightCnt=sum(1 for i in range(left, right+1) if nums[i]==rightElem)

            return leftElem if leftCnt>rightCnt else rightElem

        return majElem(0, len(nums)-1)
```