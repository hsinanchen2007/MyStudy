#### 方法一 : 回溯法

**算法**

[回溯法](https://baike.baidu.com/item/%E5%9B%9E%E6%BA%AF%E6%B3%95/86074?fr=aladdin) 
是一种通过遍历所有可能成员来寻找全部可行解的算法。若候选 _不是_ 可行解 (或者至少不是 _最后一个_ 解)，回溯法会在前一步进行一些修改以舍弃该候选，换而言之， _回溯_ 并再次尝试。

这是一个回溯法函数，它将第一个添加到组合中的数和现有的组合作为参数。 `backtrack(first, curr)`

* 若组合完成- 添加到输出中。

* 遍历从 `first` t到 `n`的所有整数。

    * 将整数 `i` 添加到现有组合 `curr`中。

    * 继续向组合中添加更多整数 : 
    `backtrack(i + 1, curr)`.

    * 将 `i` 从 `curr`中移除，实现回溯。

**实现**

<![image.png](https://pic.leetcode-cn.com/d947037362716a3357ba754190f8ee23d1a64ad58a8529dfce2010db0aa42cfa-image.png),![image.png](https://pic.leetcode-cn.com/837f342bb4c60937fe7d56452e7885b453bfb8a3619e6e***793261dee0d2182-image.png),![image.png](https://pic.leetcode-cn.com/fce713aaef28d6f13b5d16a246f7e1b62fd77c3e24ce828f2cdba3292e59c359-image.png),![image.png](https://pic.leetcode-cn.com/6b63d7f8f786fd9a7644eb24608232896fd4150daf223f0fb9c16dde9b096e98-image.png),![image.png](https://pic.leetcode-cn.com/0ec9225141cf8661322753ef23b5b3054f0eb1363430836b6c3958713bd1848a-image.png),![image.png](https://pic.leetcode-cn.com/861218c2b34798259435b888f82e376c53c9ad230e0270f912471055dc83a3c0-image.png),![image.png](https://pic.leetcode-cn.com/927aae310103f328f34766414275e8f2d0f6a0849f65d883384b54b07306d396-image.png),![image.png](https://pic.leetcode-cn.com/13dbafc454915f7c62dca11b2e5f876161f8db07d505dc89f1e4d97431f5c85d-image.png),![image.png](https://pic.leetcode-cn.com/54722f740c51861d5ad0a3518c9669a83e7b76b021607fa6b802f2a410aec359-image.png),![image.png](https://pic.leetcode-cn.com/31a7bf9ad8c88dbd17899260e2b87a8ada68d45b1646506946bfab80567d2fb9-image.png),![image.png](https://pic.leetcode-cn.com/64037947713388172368e89dfc8b114f20b8fac8d3a53ff709fe0849a07f38dc-image.png),![image.png](https://pic.leetcode-cn.com/d0a907c370a8eec80f964723f522183494b89698340ac9911ca0d10803224306-image.png)>

```Python [solution 1]
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        def backtrack(first = 1, curr = []):
            # if the combination is done
            if len(curr) == k:  
                output.append(curr[:])
            for i in range(first, n + 1):
                # add i into the current combination
                curr.append(i)
                # use next integers to complete the combination
                backtrack(i + 1, curr)
                # backtrack
                curr.pop()
        
        output = []
        backtrack()
        return output
```

```Java [solution 1]
class Solution {
  List<List<Integer>> output = new LinkedList();
  int n;
  int k;

  public void backtrack(int first, LinkedList<Integer> curr) {
    // if the combination is done
    if (curr.size() == k)
      output.add(new LinkedList(curr));

    for (int i = first; i < n + 1; ++i) {
      // add i into the current combination
      curr.add(i);
      // use next integers to complete the combination
      backtrack(i + 1, curr);
      // backtrack
      curr.removeLast();
    }
  }

  public List<List<Integer>> combine(int n, int k) {
    this.n = n;
    this.k = k;
    backtrack(1, new LinkedList<Integer>());
    return output;
  }
}
```


**复杂度分析**

* 时间复杂度 : $O(k C_N^k)$，其中 $C_N^k = \frac{N!}{(N - k)! k!}$ 是要构成的组合数。
`append / pop` (`add / removeLast`) 操作使用常数时间，唯一耗费时间的是将长度为 `k` 的组合添加到输出中。
 
* 空间复杂度 : $O(C_N^k)$ ，用于保存全部组合数以输出。
<br />
<br />


---
#### 方法二: 字典序 (二进制排序) 组合

**直觉**

主要思路是以字典序的顺序获得全部组合。


![image.png](https://pic.leetcode-cn.com/ab26203eb768a3153fe704cfee97158429d08e886f7e5b453b2256ee658f0598-image.png)
**算法**

算法非常直截了当 : 

* 将 `nums` 初始化为从 `1` 到 `k`的整数序列。 将 `n + 1`添加为末尾元素，起到“哨兵”的作用。
将指针设为列表的开头 `j = 0`.

* While `j < k` :
    
    * 将`nums` 中的前k个元素添加到输出中，换而言之，除了“哨兵”之外的全部元素。
    
    * 找到`nums`中的第一个满足 `nums[j] + 1 != nums[j + 1]`的元素，并将其加一
    `nums[j]++` 以转到下一个组合。

**实现**


```Python [solution 2]
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        # init first combination
        nums = list(range(1, k + 1)) + [n + 1]
        
        output, j = [], 0
        while j < k:
            # add current combination
            output.append(nums[:k])
            # increase first nums[j] by one
            # if nums[j] + 1 != nums[j + 1]
            j = 0
            while j < k and nums[j + 1] == nums[j] + 1:
                nums[j] = j + 1
                j += 1
            nums[j] += 1
            
        return output
```

```Java [solution 2]
class Solution {
  public List<List<Integer>> combine(int n, int k) {
    // init first combination
    LinkedList<Integer> nums = new LinkedList<Integer>();
    for(int i = 1; i < k + 1; ++i)
      nums.add(i);
    nums.add(n + 1);

    List<List<Integer>> output = new ArrayList<List<Integer>>();
    int j = 0;
    while (j < k) {
      // add current combination
      output.add(new LinkedList(nums.subList(0, k)));
      // increase first nums[j] by one
      // if nums[j] + 1 != nums[j + 1]
      j = 0;
      while ((j < k) && (nums.get(j + 1) == nums.get(j) + 1))
        nums.set(j, j++ + 1);
      nums.set(j, nums.get(j) + 1);
    }
    return output;
  }
}
```

**复杂度分析**

* 时间复杂度 : $O(k C_N^k)$，其中$C_N^k = \frac{N!}{(N - k)! k!}$ 是要构建的组合数。由于组合数是$C_N^k$，外层的 while 循环执行了$C_N^k$次 。对给定的一个`j`，内层的 while 循环执行了$C_{N - j}^{k - j}$次。外层循环超过 $C_N^k$次访问，平均而言每次访问的执行次数少于1。因此，最耗费时间的部分是将每个长度为$k$ 的组合(共计$C_N^k$ 个组合) 添加到输出中，
消耗 $O(k C_N^k)$ 的时间。

    你可能注意到，尽管方法二的时间复杂度与方法一相同，但方法二却要快上许多。这是由于方法一需要处理递归调用栈，且其带来的影响在Python中比在Java中更为显著。
    
*  空间复杂度 : $O(C_N^k)$ ，用于保存全部组合数以输出。