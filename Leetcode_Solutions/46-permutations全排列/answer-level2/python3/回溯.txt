
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:

        def back_track(nums, track):
            if len(track) == len(nums):
                # 这里不能传入track的引用，否则后续改变track时，result中的元素也会随之变化
                # 算法执行结束后，track为[]，因此如果传入track，result中便全是[]了
                result.append(track[:])
                return

            for i in nums:
                if i in track:
                    continue
                track.append(i)
                back_track(nums, track)
                track.pop()

        result = []
        track = []
        back_track(nums, track)
        return result
```
