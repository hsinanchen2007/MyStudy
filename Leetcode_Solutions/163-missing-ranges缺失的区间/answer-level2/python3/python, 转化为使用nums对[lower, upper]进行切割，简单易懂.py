```
def convert_range_to_str(range_list):
    if range_list[0] == range_list[1]:
        return str(range_list[0])
    return f"{range_list[0]}->{range_list[1]}"


class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        results = []
        for num in nums:
            # split range
            if lower < num:
                missing = [lower, num - 1]
                results.append(convert_range_to_str(missing))
                lower = num + 1
            elif lower == num:
                lower = num + 1
            else:
                # lower > num. duplicate num
                continue

        missing = [lower, upper]
        if lower <= upper:
            results.append(convert_range_to_str(missing))

        return results
```

![image.png](https://pic.leetcode-cn.com/6263ee14a629a0974e34c796ef27692457c7e95797511ef47b93a27cc618a00b-image.png)

