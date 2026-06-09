#### 方法：贪心（双指针）

**思路**

如果最重的人可以与最轻的人共用一艘船，那么就这样安排。否则，最重的人无法与任何人配对，那么他们将自己独自乘一艘船。

这么做的原因是，如果最轻的人可以与任何人配对，那么他们也可以与最重的人配对。

**算法**

令 `people[i]` 指向当前最轻的人，而 `people[j]` 指向最重的那位。

然后，如上所述，如果最重的人可以与最轻的人共用一条船（即 `people[j] + people[i] <= limit`），那么就这样做；否则，最重的人自己独自坐在船上。

```cpp [FmbVqh3B-C++]
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1;
        int ans = 0;

        while (i <= j) {
            ans++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }

        return ans;
    }
};
```
```java [FmbVqh3B-Java]
class Solution {
    public int numRescueBoats(int[] people, int limit) {
        Arrays.sort(people);
        int i = 0, j = people.length - 1;
        int ans = 0;

        while (i <= j) {
            ans++;
            if (people[i] + people[j] <= limit)
                i++;
            j--;
        }

        return ans;
    }
}
```
```python [FmbVqh3B-Python]
class Solution(object):
    def numRescueBoats(self, people, limit):
        people.sort()
        i, j = 0, len(people) - 1
        ans = 0
        while i <= j:
            ans += 1
            if people[i] + people[j] <= limit:
                i += 1
            j -= 1
        return ans
```


**复杂度分析**

* 时间复杂度：$O(N \log N)$，其中 $N$ 是 `people` 的长度。

* 空间复杂度：$O(N)$。