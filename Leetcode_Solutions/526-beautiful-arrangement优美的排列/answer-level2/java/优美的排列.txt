#### 方法 1：暴力 [Time Limit Exceeded]

**算法**

在暴力方法中，我们找到使用数字 1 到 N 的所有排列。然后我们逐一遍历每个数字并检查是否满足两个条件中的一个。

为了产生所有可能的排列，我们使用函数 `permute(nums, current_index)`。这个函数创建所有可能的排列。

`permute` 首先将当前元素 $current_index$ 的下标当做参数之一。然后它将当前元素跟数组中它后面的每一个元素交换位置，以产生新的数组顺序。当前元素交换后，调用函数自己但这次处理的是数组中的下一个元素的位置。当递归回来以后，我们将当前函数中交换的两个元素换回原来的位置。

当我们到达数组尾部时，新的数组顺序已经产生了。

```Java []
public class Solution {
    int count = 0;
    public int countArrangement(int N) {
        int[] nums = new int[N];
        for (int i = 1; i <= N; i++)
            nums[i - 1] = i;
        permute(nums, 0);
        return count;
    }
    public void permute(int[] nums, int l) {
        if (l == nums.length - 1) {
            int i;
            for (i = 1; i <= nums.length; i++) {
                if (nums[i - 1] % i != 0 && i % nums[i - 1] != 0)
                    break;
            }
            if (i > nums.length) {
                count++;
            }
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

* 时间复杂度：$O(n!)$ 。会产生 $n!$ 个长度为 $n$ 的排列。

* 空间复杂度：$O(n)$ 。递归树的深度最多为 $n$ 。且使用了大小为 $n$ 的 $nums$ 数组。

#### 方法 2：更好的暴力 [Accepted]

**算法**

在暴力方法中，我们产生了所有可能的排列并对每一个排列都进行了可除性检查。此方法中，我们可以稍做优化。我们将每个元素添加到数组最后面的时候，我们马上进行可除性检查，一旦发现当前元素和位置不满足要求我们就不能将这个元素放在当前位置，即可换一个元素继续判断。

```Java []
public class Solution {
    int count = 0;
    public int countArrangement(int N) {
        int[] nums = new int[N];
        for (int i = 1; i <= N; i++)
            nums[i - 1] = i;
        permute(nums, 0);
        return count;
    }
    public void permute(int[] nums, int l) {
        if (l == nums.length) {
            count++;
        }
        for (int i = l; i < nums.length; i++) {
            swap(nums, i, l);
            if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0)
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

* 时间复杂度：$O(k)$ 。 $k$ 是有效排列的数目。

* 空间复杂度：$O(n)$ 。递归树的深度最多为 $n$ 层，除此以外， $nums$ 数组的大小为 $n$ ，这里 $n$ 是给定数字的大小。

#### 方法 3：回溯 [Accepted]

**算法**

这个方法背后的想法很简单。我们常数从 1 到 N 创建所有的排列。我们可以将一个数字放在一个特定位置并检查这个数字在这个位置的可除性。但我们还需要记录之前已经使用过哪些数字以免重复使用同一个数字。如果当前数字不能满足可除性要求，当前位置为这个数的所有排列我们就都不需要考虑了，这个剪枝可以让我们的搜索空间大大减少。我们通过将每个数字在每个位置进行检查来实现这一过程。

我们使用一个使用一个大小为 $N$ 的 “已使用数组” ，这里 $visited[i]$ 表示目前为止第 $i$ 个数字是否已经使用过，True 表示已经使用过， False 表示还没有使用过。

我们使用函数 `calculate`，它将从 1 到 N 所有还没有被使用过的数字放到当前位置 $pos$，并检查是否满足可除性。如果 $i$ 放到当前位置 $pos$ 是满足要求的，我们就把 $i$ 放在当前位置 $pos$ 并继续考虑下一个位置 $pos + 1$，否则我们需要换一个数字放在当前位置。

下面的动画能帮助你更好理解这个过程。

<![image.png](https://pic.leetcode-cn.com/4e358e2f9cf2cf43dae5b87ef509f78faf2c0762f213aa66cd12f9fb277c24c8-image.png),![image.png](https://pic.leetcode-cn.com/1f18c21a1a6a977efe54976fe36bcfa141fda641b13f97ae4d84c4d8ee524ba7-image.png),![image.png](https://pic.leetcode-cn.com/05a58918d326f9a76d92465f8c3b5e145f7ab2f87586d0d87d114eb7650b49e4-image.png),![image.png](https://pic.leetcode-cn.com/bfe8f8167cf1a6a686d16d3f0320a21d70d726528d3d1cb1eb76b843393f53fb-image.png),![image.png](https://pic.leetcode-cn.com/77ddd15459090a4e232bc60632d1de7a6fc32f6e3e19fedfa4a811a6449f9918-image.png),![image.png](https://pic.leetcode-cn.com/b60ee51eee66cce4865102c87e062859bb8b16bbcf9f31092c35ddf5a2d43be1-image.png),![image.png](https://pic.leetcode-cn.com/02570fa1ab1a06af6db1659f57c28173d44f7d3a0ef081169c8f64ab6bf010e1-image.png),![image.png](https://pic.leetcode-cn.com/5f91528db79dc91e80e73e3f012f4b17f667a51810cbfa08c140f0b5a3e52bf0-image.png),![image.png](https://pic.leetcode-cn.com/a590617200ebef22d9035a433236c5913bb28a227a715892ef3defba56292702-image.png),![image.png](https://pic.leetcode-cn.com/8769a6b21124e503324ba4d3f33d798f254f3aa6ac0a375a740e5b820665b173-image.png),![image.png](https://pic.leetcode-cn.com/8ec6744951a1e59de9588b82690f4eabac21070140a04a085e276d0425299967-image.png),![image.png](https://pic.leetcode-cn.com/820f2a6876fd0c2338c2ae8be1f35f1cbddb49821dbc875ac9c3064a9c7fbc1a-image.png),![image.png](https://pic.leetcode-cn.com/7d30d119b4a3f0c424fab16d7a7b5604a8f8a588f76c46905d1b0cba3ec15fb3-image.png),![image.png](https://pic.leetcode-cn.com/c22ba79b1bdd513faac597cab2741f35c8c421483345c90008ee2f7ae4a8abb9-image.png),![image.png](https://pic.leetcode-cn.com/b8231b3d2b9043da880ad52bf84584079469de96e9b0d5321f6562e07557bc61-image.png),![image.png](https://pic.leetcode-cn.com/159a1da865c5098e0f7b024bea2c39874ab2ecd1a7310721d12a908bcfa3d706-image.png),![image.png](https://pic.leetcode-cn.com/3d34ca0fe9d2f63ed32bf9fccdfcd212e8633dd409a149531ad07c250c3eb68b-image.png),![image.png](https://pic.leetcode-cn.com/bf7962d4c8d75f81eeea3ea859d9e0600ecf9cc59aaba9834773c8dbcf29017c-image.png),![image.png](https://pic.leetcode-cn.com/8a470d0028619f346d1c9fd4de7766b6fd0113f247c711132cbb8e7c7fef3408-image.png),![image.png](https://pic.leetcode-cn.com/5b59e83dcbe3efa53c51cf433b6c22c0699375ef996dc4328982a19c14b456d1-image.png),![image.png](https://pic.leetcode-cn.com/86ec6e1662151a253be9f4f96c02dba4ebcf0387d6ee34de0378835b5c9a4737-image.png),![image.png](https://pic.leetcode-cn.com/c6d129bec153807faf1e40c8646b5cc423bdc368d20aece35721574282ac9867-image.png),![image.png](https://pic.leetcode-cn.com/cb0ad162ddda1a02b89475c919b5e4dc754557ea666630c8af008592ab75bf1a-image.png),![image.png](https://pic.leetcode-cn.com/fc94a05911bc698547ada8d16b4fb116f9d591539736da7b56a08366f2d10741-image.png),![image.png](https://pic.leetcode-cn.com/03e37a5a6f31bc93c0709e9953d1c645868a7accde924dcb2a25821abb7e8813-image.png),![image.png](https://pic.leetcode-cn.com/7f93aa5c924369f5c4d89525c3074c6c5728e909be257791df73c43359dee339-image.png)>


下面的代码由 [@shawngao](http://leetcode.com/shawngao) 提供。

```Java []
public class Solution {
    int count = 0;
    public int countArrangement(int N) {
        boolean[] visited = new boolean[N + 1];
        calculate(N, 1, visited);
        return count;
    }
    public void calculate(int N, int pos, boolean[] visited) {
        if (pos > N)
            count++;
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited);
                visited[i] = false;
            }
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(k)$。$k$ 是有效排列的数目。

* 空间复杂度：$O(n)$。使用了大小为 $n$ 的数组 $visited$。递归树的深度最多为 $n$，这里 $n$ 是给定的整数 $n$。