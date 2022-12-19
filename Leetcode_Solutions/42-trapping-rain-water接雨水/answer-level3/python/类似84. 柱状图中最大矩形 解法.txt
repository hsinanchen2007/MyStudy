```
class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        N = len(height)
        left_larger = [0] * N
        for i in xrange(N):
            left = i - 1
            while left >= 0 and height[i] > height[left]:
                left = left_larger[left]

            left_larger[i] = left

        right_larger = [0] * N
        for i in xrange(N - 1, -1, -1):
            right = i + 1
            while right < N and height[i] >= height[right]:
                right = right_larger[right]

            right_larger[i] = right

        result = 0
        for i in xrange(N):
            left_higher = left_larger[i]
            right_higher = right_larger[i]
            if left_higher < 0 or right_higher >= N:
                continue

            sub_result = (min(height[left_higher], height[right_higher]) - height[i]) * (right_higher - left_higher - 1)
            result += sub_result

        return result
```

还是有点别扭
