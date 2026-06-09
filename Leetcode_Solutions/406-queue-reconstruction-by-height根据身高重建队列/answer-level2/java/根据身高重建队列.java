####  方法：贪心算法
这个问题是让我们重建队列。
![在这里插入图片描述](https://pic.leetcode-cn.com/0b13fafcb2dad898575a95702d0f76d58eb973f84112c011c0771c282eb1cc6c-file_1577091496469)
让我们从最简单的情况下思考，当队列中所有人的 `(h,k)` 都是相同的高度 `h`，只有 `k` 不同时，解决方案很简单：每个人在队列的索引 `index = k`。 
![在这里插入图片描述](https://pic.leetcode-cn.com/f1d3fb50fbff21d238b5373f026e5d8145b03a71b80cd469d2f1003db9f31fca-file_1577091496518)
即使不是所有人都是同一高度，这个策略也是可行的。因为个子矮的人相对于个子高的人是 “看不见” 的，所以可以先安排个子高的人。
![在这里插入图片描述](https://pic.leetcode-cn.com/3910bd5f1730547364d6a44e04de732819ebcb5c1ab3ce116ffff648d6e9e122-file_1577091496595)
上图中我们先安排身高为 `7` 的人，将它放置在与 `k` 值相等的索引上；再安排身高为 `6` 的人，同样的将它放置在与 `k` 值相等的索引上。

该策略可以递归进行：
- 将最高的人按照 `k` 值升序排序，然后将它们放置到输出队列中与 `k` 值相等的索引位置上。
- 按降序取下一个高度，同样按 `k` 值对该身高的人升序排序，然后逐个插入到输出队列中与 `k` 值相等的索引位置上。
- 直到完成为止。
![在这里插入图片描述](https://pic.leetcode-cn.com/210edfd93704664c8aa80cc99db90c9a924869a8d1b0fd3c6b53d2ab88936371-file_1577091496575)
![在这里插入图片描述](https://pic.leetcode-cn.com/328e9d5d2ab9657ffcde7905b7d0a5edbb093c16e913daf803d2e5d40797f11e-file_1577091496580)
![在这里插入图片描述](https://pic.leetcode-cn.com/54b501b711e84a58204bb2b4c8ecb33b5aae6a38ea95ed07efd22b2c31311445-file_1577091496515)
![在这里插入图片描述](https://pic.leetcode-cn.com/394b84089e8ed708a586b48aaae248dc7e38597037aa49439c228a223f4cc2d6-file_1577091496600)
![在这里插入图片描述](https://pic.leetcode-cn.com/4ea345630cb6e0634333d2ffa0629489d98cd61b5794c112ed62b672f35cf0c8-file_1577091496571)
![在这里插入图片描述](https://pic.leetcode-cn.com/b057dd649208e88d4c88e4635060eac49eaaf5ad0ca59a3bea02d41dc4484c48-file_1577091496564)
![在这里插入图片描述](https://pic.leetcode-cn.com/0cc7e0d70b2bc97b32d4988daa710ede2f0ad8f99387f695addb18213856d8a6-file_1577091496578)
![在这里插入图片描述](https://pic.leetcode-cn.com/6c52bb74a2dc15fcc8adb54681ef0dd958fb21ae4c523aeeda16cfb930a98b2a-file_1577091496602)
![在这里插入图片描述](https://pic.leetcode-cn.com/ffc1c3c59c3deb0a5fae770bb69ce9ed867d089841de3059c9ffd5e74caa196f-file_1577091496598)
![在这里插入图片描述](https://pic.leetcode-cn.com/120db0056abcfa07fbf2727878f204d072efc3cb6c7918d1aff6693a3e7d3020-file_1577091496593)
**算法：**
- 排序：
	-  按高度降序排列。
	-  在同一高度的人中，按 `k` 值的升序排列。
- 逐个地把它们放在输出队列中，索引等于它们的 `k` 值。
- 返回输出队列

```python [solution1-Python]
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key = lambda x: (-x[0], x[1]))
        output = []
        for p in people:
            output.insert(p[1], p)
        return output
```

```java [solution1-Java]
class Solution {
  public int[][] reconstructQueue(int[][] people) {
    Arrays.sort(people, new Comparator<int[]>() {
      @Override
      public int compare(int[] o1, int[] o2) {
        // if the heights are equal, compare k-values
        return o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0];
      }
    });

    List<int[]> output = new LinkedList<>();
    for(int[] p : people){
      output.add(p[1], p);
    }

    int n = people.length;
    return output.toArray(new int[n][2]);
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N^2)$。排序使用了 $\mathcal{O}(N \log N)$ 的时间，每个人插入到输出队列中需要 $\mathcal{O}(k)$ 的时间，其中 $k$ 是当前输出队列的元素个数。总共的时间复杂度为 $\mathcal{O}\left({\sum\limits_{k = 0}^{N - 1}{k}}\right)$ = $\mathcal{O}(N^2)$。
* 空间复杂度：$\mathcal{O}(N)$，输出队列使用的空间。