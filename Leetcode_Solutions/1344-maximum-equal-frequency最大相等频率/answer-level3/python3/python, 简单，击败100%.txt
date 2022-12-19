![image.png](https://pic.leetcode-cn.com/90c7adedcfafba6e9a10350a8791ef12ac4b59003c6a2b097dab9aab6d7595e5-image.png)

```
class Solution:
    def maxEqualFreq(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0
        cout_dict = collections.Counter(nums)
        for i in reversed(range(len(nums) + 1)):
            cnt_key = set(cout_dict.keys())
            cnt = set(cout_dict.values())
            list_cnt = sorted(list(cnt))
            if len(cnt) == 1 and len(cnt_key) == 1:
                return len(nums[0:i])
            if len(cnt) == 1 and list_cnt[0] == 1:
                return len(nums[0:i])
            if len(cnt) == 2:
                list_cnt = sorted(list(cnt))
                min = []
                max = []
                for k, v in cout_dict.items():
                    if v == list_cnt[0]:
                        min.append(k)
                    else:
                        max.append(k)
                if (list_cnt[0] == 1 and len(min) == 1) or (list_cnt[1] == 1 and len(max) == 1):
                    # print(nums[0:i])
                    return len(nums[0:i])
                if list_cnt[1] - list_cnt[0] == 1 and len(max) == 1:
                    return len(nums[0:i])
            if cout_dict[nums[i-1]] == 1:
                cout_dict.pop(nums[i-1])
            else:
                cout_dict[nums[i-1]] = cout_dict[nums[i - 1]] - 1
        return 0
```

```
