详解很多，直接上代码
```
        def backtrack(numbers, pre):
            nonlocal res
            if len(numbers) <= 1:
                res.append(pre + numbers)
                return
            for key, value in enumerate(numbers):
                if value not in numbers[:key]:
                    backtrack(numbers[:key] + numbers[key + 1:], pre+[value])

        res = []
        if not len(nums): return []
        backtrack(nums, [])
        return res
```
