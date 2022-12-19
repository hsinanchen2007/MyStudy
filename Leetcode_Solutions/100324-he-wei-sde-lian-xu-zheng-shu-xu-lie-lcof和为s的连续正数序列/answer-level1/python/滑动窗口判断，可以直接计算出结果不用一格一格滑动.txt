滑动窗口+直接计算，注释标出了每一步的作用
```
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        result = list()
        for i in range(2, 10000):
            # 假设最大可以有10000个数字（这里可以early break，够大是为了足够全）
            if (target - sum(range(1, i+1))) % i == 0 and target - sum(range(1, i+1)) >= 0:
                # 因为target-（1+..+i）必定要是i的整数倍才可以使窗口滑过去对齐，所以这么判断
                # 此时（1+..+i）必须小于等于target，窗口才能滑得动
                if i % 2 == 0:
                    # 如果是偶数个，就按照偶数的规律直接算出这偶数个数字生成list，不用一格一格滑动窗口
                    result.append(list(range(target//i - (i//2) + 1, target//i + (i//2) + 1 )))
                else:
                    # 如果是奇数个，就按照奇数的规律直接算出这奇数个数字生成list，不用一格一格滑动窗口
                    result.append(list(range(target//i - (i//2), target//i + (i//2) + 1 )))
            elif target - sum(range(1, i+1)) < 0:
                # 此时（1+..+i）大于target，窗口已经过大了，提前终止
                break
        # 最后的list是由短到长的，所以要转一下
        result.reverse()
        return result
```

