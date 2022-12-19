由题意和图示，可以知道，第i个柱子的储水量，与左右两侧柱子的最大高度有关，用left_max和right_max分别表示左右两侧的最大高度。
储水量=min(left_max, right_max) - height[i]，当然如果height[i]不小于这两个最大高度的话，就需要对这两个高度进行更新。

- 从左向右遍历，left从0开始，
    - 对于height[left]，left_max是可信的，而right_max不一定是右侧的最大值，但是其一定不大于右侧真正的最大值；
    - 如果left_max<right_max，
        - 如果height[left] >= left_max，更新left_max=height[left]
        - 否则，第left处的储水量就等于left_max-height[left]
        - left += 1
    - 否则，
        - 如果height[right] >= right_max，更新right_max=height[right]
        - 否则，第right处的储水量就等于right_max-height[right]
        - right -= 1