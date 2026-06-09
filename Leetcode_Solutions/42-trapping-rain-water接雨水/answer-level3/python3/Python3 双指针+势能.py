## 解题思路
通读题目后，**紧紧地**抓住**核心思想**：
- 下雨了，**势能低**的低洼地方被雨水**填充**了

继续整理，得到三个指导要点：
1. 如果**L山峰**和**R山峰**中间有一个低洼的地方（两座山峰之间没有比它们更高的山峰），那么这个低洼地方被雨水填充后，高度达到**min(L,R)**
2. 利用**双指针**思想，制定**逐步回溯势能方针（比较左右两边的势能并更新记录当前势能，然后让势能低的地方往中间遍历，直到两个指针相碰。由于势能的特性，势能更新只会越来越大）**，这样就可以只用**一次遍历**更新所有被雨水填充的地方的高度
3. **下雨后**的总势能 - **下雨前**的总势能 = **雨水**带来的势能

## 代码
```python3 []
class Solution:
    def trap(self, height: List[int]) -> int:
        # 我有点强迫倾向，想保持势能排序，所以用了两个list
        wetL, wetR = [], []
        potential = 0
        iL, iR = 0, len(height) - 1
        while iL <= iR:
            ptL, ptR = height[iL], height[iR]
            potential = max(potential, min(ptL, ptR))
            if ptL <= ptR:
                iL += 1
                wetL.append(potential)
            else:
                iR -= 1
                wetR.append(potential)
        return sum(wetL + wetR[::-1]) - sum(height)
```
稳定精巧，简洁高效，即吾追求
