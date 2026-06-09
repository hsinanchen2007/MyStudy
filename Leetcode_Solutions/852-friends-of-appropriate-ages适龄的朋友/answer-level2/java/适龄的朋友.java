#### 方法 1：计数

**想法**

不考虑遍历所有的 `20000` 个人，我们只考虑遍历所有的元组 `(age, count)` 表示在这个年纪有多少人。因为最多只有 120 个可能的年纪，这会是一个很快的提升。

**算法**

对于每个元组 `(ageA, countA)`，`(ageB, countB)`，如果条件满足对应的年纪，那么久将 `countA * countB` 加入发好友请求的人数。

当 `ageA == ageB` 的时候我们就数多了：我们只有 `countA * (countA - 1)` 对好友请求，因为你不能和自己发送请求。

```Java []
class Solution {
    public int numFriendRequests(int[] ages) {
        int[] count = new int[121];
        for (int age: ages) count[age]++;

        int ans = 0;
        for (int ageA = 0; ageA <= 120; ageA++) {
            int countA = count[ageA];
            for (int ageB = 0; ageB <= 120; ageB++) {
                int countB = count[ageB];
                if (ageA * 0.5 + 7 >= ageB) continue;
                if (ageA < ageB) continue;
                if (ageA < 100 && 100 < ageB) continue;
                ans += countA * countB;
                if (ageA == ageB) ans -= countA;
            }
        }

        return ans;
    }
}
```

```Python []
class Solution(object):
    def numFriendRequests(self, ages):
        count = [0] * 121
        for age in ages:
            count[age] += 1

        ans = 0
        for ageA, countA in enumerate(count):
            for ageB, countB in enumerate(count):
                if ageA * 0.5 + 7 >= ageB: continue
                if ageA < ageB: continue
                if ageA < 100 < ageB: continue
                ans += countA * countB
                if ageA == ageB: ans -= countA

        return ans
```


**复杂度分析**

* 时间复杂度：$O(A^2 + N)$，其中 $N$ 是人数，$A$ 是年龄的种树。
* 空间复杂度：$O(A)$，`count` 的空间开销。