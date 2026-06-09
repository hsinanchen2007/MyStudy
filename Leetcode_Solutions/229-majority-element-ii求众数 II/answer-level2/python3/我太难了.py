### 解题思路
虽然已经做完了169的众数题，但还是不会做这道...我太难了

里面有很多小细节：
+ 怎么保证两个候选人不一样
+ 各种逻辑判断`if`,`continue`,`elif`

### 代码

```python3
class Solution:
    def majorityElement(self, nums) -> int:
        ans = []
        if not nums:
            return ans
        a_cnt = 0
        b_cnt = 0
        a_candidate = nums[0]
        b_candidate = nums[0]
        for each in nums:
            if each == a_candidate:
                a_cnt += 1
                continue
            if each == b_candidate:
                b_cnt += 1
                continue
            if a_cnt == 0:
                a_candidate = each
                a_cnt += 1
                continue
            if b_cnt == 0:
                b_candidate = each
                b_cnt += 1
                continue
            a_cnt -= 1
            b_cnt -= 1
        req_cnt = len(nums) // 3 + 1
        a_cnt = 0
        b_cnt = 0
        for each in nums:
            if each == a_candidate:
                a_cnt += 1
            elif each == b_candidate:
                b_cnt += 1
        if a_cnt >= req_cnt:
            ans.append(a_candidate)
        if b_cnt >= req_cnt:
            ans.append(b_candidate)
        return ans

```