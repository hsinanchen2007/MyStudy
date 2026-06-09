##  解决方法：
####  方法一：暴力法：
**算法：**
- 暴力法非常简单。我们可以生成代表糖果的给定 $nums$ 数组的所有排列，并确定所生成数组前半部分中唯一元素的数目。 
- 为了确定数组前半部分中唯一元素的数目，我们将所有需要的元素放在一个集合中，并计算集合中元素的数目。我们在生成的数组的前半部分中为所有可能的排列计算这样的唯一元素，并返回最大集合的大小。 

```Java [ ]
public class Solution {
    int max_kind = 0;
    public int distributeCandies(int[] nums) {
        permute(nums, 0);
        return max_kind;
    }
    public void permute(int[] nums, int l) {
        if (l == nums.length - 1) {
            HashSet < Integer > set = new HashSet < > ();
            for (int i = 0; i < nums.length / 2; i++) {
                set.add(nums[i]);
            }
            max_kind = Math.max(max_kind, set.size());
        }
        for (int i = l; i < nums.length; i++) {
            swap(nums, i, l);
            permute(nums, l + 1);
            swap(nums, i, l);
        }
    }
    public void swap(int[] nums, int x, int y) {
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n!)$。
* 空间复杂度：$O(n)$，递归树的深度可以达到 $n$。 


####  方法二：优化的暴力法
**算法：**
- 在研究这种方法之前，首先我们需要观察一点。女孩能得到的唯一糖果的最大数量可以是 $n/2$，其中 $n$ 是指糖果的数量。此外，如果独特的糖果数量低于 $n/2$ 的话，为了使女孩能得到的独特的糖果数量最大化，我们会将所有独特的糖果分配给女孩。因此，在这种情况下，女孩得到的独特糖果数量等于给定 $candies$ 数组中的独特糖果总数。 
- 现在,我们需要在给定的 $candies$ 数组中找到唯一糖果的总数。找到唯一糖果数量的一种方法是遍历给定的 $candies$ 数组。每当我们遇到一个元素，比如 $candies[j]$ 时，我们可以将所有与 $candies[j]$ 相同的元素标记为无效，并将唯一元素的计数增加 1。 
- 最后，$count$ 会提供给女孩所需数量的独特糖果。此外，要返回的值由：$\text{min}(\frac{n}{2}, count)$ 给出。当 $count$ 超过 $\frac{n}{2}$ 时，我们可以停止对给定 $candies$ 数组的遍历。 

```Java [ ]
public class Solution {
    public int distributeCandies(int[] candies) {
        int count = 0;
        for (int i = 0; i < candies.length && count < candies.length / 2; i++) {
            if (candies[i] != Integer.MIN_VALUE) {
                count++;
                for (int j = i + 1; j < candies.length; j++) {
                    if (candies[j] == candies[i])
                        candies[j] = Integer.MIN_VALUE;
                }
            }
        }
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n^2)$。对于每一个新发现的元素，我们遍历 $candies$ 的所有元素。在最坏的情况下，我们对 $candies$ 的每个元素都这样做。$n$ 表示 $candies$ 数组的大小。 
* 空间复杂度：$O(1)$。

####  方法三：排序
**算法：**
我们可以对给定的 $candies$ 数组进行排序，并通过比较排序数组的相邻元素来找出唯一的元素。对于找到的每个新元素（与前一个元素不同），我们需要更新 $count$。最后，我们可以将所需结果返回为 $\text{min}(n/2, count)$，如前面的方法所述。 

```Java [ ]
public class Solution {
    public int distributeCandies(int[] candies) {
        Arrays.sort(candies);
        int count = 1;
        for (int i = 1; i < candies.length && count < candies.length / 2; i++)
            if (candies[i] > candies[i - 1])
                count++;
        return count;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n\log n)$。排序需要 $O(n\log n)$ 的时间。
* 空间复杂度：$O(1)$。

####  方法四：集合set
**算法：**
找到唯一元素数量的另一种方法是遍历给定 $candies$ 数组的所有元素，并继续将元素放入集合中。通过集合的属性，它将只包含唯一的元素。最后，我们可以计算集合中元素的数量，例如 $count$。要返回的值将再次由 $\text{min}(count, n/2)$ 给出，如前面的方法所述。其中 $n$ 表示 $candies$ 数组的大小。 

```Java [ ]
public class Solution {
    public int distributeCandies(int[] candies) {
        HashSet < Integer > set = new HashSet < > ();
        for (int candy: candies) {
            set.add(candy);
        }
        return Math.min(set.size(), candies.length / 2);
    }
}
```
* 时间复杂度：$O(n)$。整个 $candies$ 数组只遍历一次。这里，$n$ 表示 $candies$ 数组的大小。 
* 空间复杂度：$O(n)$,在最坏的情况下，$set$ 的大小为 $n$。