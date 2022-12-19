思路：固定j，使用双指针，从当前位置往前找i，往后找k，其中j前后总和的差超过最大和最小的差就剪枝掉。使用前缀和优化子区间求和，否则超时。
```
    def splitArray(self, nums: List[int]) -> bool:
        """
        遍历数组当前位置为j，使用双指针，从当前位置往前找i，往后找k
        :param nums:
        :return:
        """
        # 需要剪枝优化
        n = len(nums)
        if n < 7:
            return False
        min_val = float('inf')
        max_val = float('-inf')
        presum = [0]
        for num in nums:
            max_val = max(max_val, num)
            min_val = min(min_val, num)
            presum.append(presum[-1] + num)

        for j in range(3, n - 3):
            if abs((presum[n] - presum[j + 1]) - (presum[j] - presum[0])) > (max_val - min_val):
                continue

            for i in range(1, j - 1):
                for k in range(j + 2, n):
                    # l1 = sum(nums[0:i])
                    # l2 = sum(nums[i + 1:j])
                    # l3 = sum(nums[j + 1:k])
                    # l4 = sum(nums[k + 1:n])
                    l1 = presum[i]
                    l2 = presum[j] - presum[i + 1]
                    l3 = presum[k] - presum[j + 1]
                    l4 = presum[n] - presum[k + 1]
                    if l1 == l2 == l3 == l4:
                        return True
        return False
```
