#### 方法一：模拟游戏【通过】

**思路**

参议员不需要在轮到自己的时候就立即使用禁令，可以等待另一个阵营的参议员投票时再使用。

**算法**

使用一个整数队列表示所有的参议员：`1` 代表 `'Radiant'` 阵营；`0` 代表 `'Dire'` 阵营。

遍历队列：对于当前队头的参议员，如果另外一个阵营有禁令，则禁止当前参议员的权利；如果另外一个阵营没有禁令，则该参议员所在阵营的禁令数量加 1。

```python [solution1-Python]
def predictPartyVictory(self, senate):
    queue = collections.deque()
    people, bans = [0, 0], [0, 0]

    for person in senate:
        x = person == 'R'
        people[x] += 1
        queue.append(x)

    while all(people):
        x = queue.popleft()
        if bans[x]:
            bans[x] -= 1
            people[x] -= 1
        else:
            bans[x^1] += 1
            queue.append(x)

    return "Radiant" if people[1] else "Dire"
```

```java [solution1-Java]
class Solution {
    public String predictPartyVictory(String senate) {
        Queue<Integer> queue = new LinkedList();
        int[] people = new int[]{0, 0};
        int[] bans = new int[]{0, 0};

        for (char person: senate.toCharArray()) {
            int x = person == 'R' ? 1 : 0;
            people[x]++;
            queue.add(x);
        }

        while (people[0] > 0 && people[1] > 0) {
            int x = queue.poll();
            if (bans[x] > 0) {
                bans[x]--;
                people[x]--;
            } else {
                bans[x^1]++;
                queue.add(x);
            }
        }

        return people[1] > 0 ? "Radiant" : "Dire";
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是参议员的数量，每次投票都会从另一支队伍中删除一名参议员。

* 空间复杂度：$O(N)$，队列大小。