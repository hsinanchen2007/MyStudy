思路一：一个简单清晰的方案，暴力查找。
```
    public static List<Integer> brute(int[] nums) {
        Integer[] res = new Integer[nums.length];
        for (int i = 0; i < nums.length; i++) {
            res[i] = 0;
            for (int j = i + 1; j < nums.length; j++) if (nums[j] < nums[i]) res[i]++;
        }
        return Arrays.asList(res);
    }
```
但是，复杂度O(N²)，超时。

思路二：也是一个简单清晰的方案，插入排序。在所有基本排序算法中，插入排序是比较特殊的。
首先，因为不涉及递归和调用栈，所以在小规模排序的场景中优势明显。
其次，插入排序的执行过程，可以方便地统计交换次数，或者说是逆序数。
但是，需要作出两个调整。
第一，因为测试用例中，存在10万多元素的数组，所以要在插入到有序部分的环节，使用二分查找的一个变种。
第二，因为统计的是，后面比当前元素小的个数，所以要按照从后到前的顺序插入，原位置和插入位置的差值。
```
    public static List<Integer> binaryInsert(int[] nums) {
        int n = nums.length;
        if (n < 1) return new ArrayList<Integer>();
        Integer[] res = new Integer[n];
        res[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int posit = binarySearch(nums, i + 1, n - 1, nums[i]) - 1;
            int pivot = nums[i];
            System.arraycopy(nums, i + 1, nums, i, posit - i);
            nums[posit] = pivot;
            res[i] = posit - i;
        }
        return Arrays.asList(res);
    }
    // 这里查找的是，最后一个小于当前元素的位置
    private static int binarySearch(int[] nums, int low, int hig, int key) {
        while (low <= hig) {
            int mid = low + ((hig - low) >> 1);
            if (nums[mid] < key) low = mid + 1;
            else hig = mid - 1;
        }
        return low;
    }
```
以上方案可以通过测试用例，但是耗时在几百毫秒以上了。

思路三：统计交换次数常用的算法，除了插入排序之外，就是归并排序了。归并排序，有分解和归并两个阶段。统计的方法是在关键的归并环节。
假定数组分为前半部分、后半部分两个有序数组。那么，前半部分的任意元素的逆序数，就是在归并这个元素之前，已经归并的后半部分的数量。
以下是具体实现，做了几点优化。
1、在分解数组的时候，最直观的做法，是创建两个子数组，分别拷贝两部分数据，然后进行递归。尽管这两个子数组是局部变量，但是不断的创建、销毁，还是非常耗时。因此这里，一次性创建一个专门的辅助数组，通过参数传入，结合low、mid、hig的下标范围，即可确定归并的两个数组的范围。
2、对于这个专门的辅助数组，一个做法是在归并的时候，将low~hig之间的数据，拷贝到辅助数组，然后再归并到原数组。另一个做法是，直接用原始数组的拷贝，作为辅助数组，拆分递归的时候，交换两个数组的角色，节省了拷贝的时间。参见代码。
3、如果直接对原始数组归并排序，数组元素位置的变化，导致交换的次数无法与原始数组一一对应。这里的做法是，使用索引数组记录位置信息，针对索引数组进行排序。排序过程中，比较仍然是通过索引找到原始元素，但是交换只交换索引的位置。
4、在归并之前，如果两部分已经有序，则无需归并。
5、还有一个代码中没有，但是可以做的优化点是，如果元素的数量少于某个值，则直接使用插入排序。
```
    public static List<Integer> merge(int[] nums) {
        int n = nums.length;
        int[] idx = new int[n];
        // 使用位置索引，原始位置不变
        Integer[] res = new Integer[n];
        for (int i = 0; i < n; i++) {
            idx[i] = i;
            res[i] = 0;
        }
        // 直接使用拷贝，节省拷贝时间
        mergeSort(nums, 0, n - 1, idx, idx.clone(), res);
        return Arrays.asList(res);
    }
    // 使用同一的辅助数组，避免频繁创建、销毁
    private static void mergeSort(int[] nums, int low, int hig, int[] idx, int[] aux, Integer[] res) {
        int nRemaining = hig - low + 1;
        if (nRemaining < 2) return;
        int mid = low + ((hig - low) >> 1);
        mergeSort(nums, low, mid, aux, idx, res);
        mergeSort(nums, mid + 1, hig, aux, idx, res);
        // 如果已经有序，则无需归并。
        if (nums[aux[mid]] <= nums[aux[mid + 1]]) {
            System.arraycopy(aux, low, idx, low, nRemaining);
            return;
        }
        merge(nums, low, mid, hig, idx, aux, res);
    }

    private static void merge(int[] nums, int low, int mid, int hig, int[] idx, int[] aux, Integer[] res) {
        int i = low, j = mid + 1;
        for (int k = low; k <= hig; k++) {
            if (i > mid) {
                idx[k] = aux[j++];
            } else if (j > hig) {
                // 这里
                res[aux[i]] += j - mid - 1;
                idx[k] = aux[i++];
            } else if (nums[aux[i]] > nums[aux[j]]) {
                // 如果统计的是总交换次数，那么应该在这里+mid-i+1
                idx[k] = aux[j++];
            } else {
                // 这里
                res[aux[i]] += j - mid - 1;
                idx[k] = aux[i++];
            }
        }
    }
```
以上代码，基本上能达到10几毫秒的理想水平了。

思路四：排序树，左子树小于等于根节点，右子树大于根节点。具体思路不细说了，评论区有很好的讲解。但是这里有两个写法。
一个是自顶向下，找到叶子的位置，从无到有地create，逐层递归地返回给根节点，即下面的create方法。
另一个是单独创建root节点，之后是自顶向下地append，即下面的append方法。
经过我的测试（未必充分），后者的耗时更低。
```
    public static List<Integer> countSmaller(int[] nums) {
        if (nums.length < 1) return new ArrayList<Integer>();
        Integer[] res = new Integer[nums.length];
        Arrays.fill(res, 0);
//        TreeNode root = new TreeNode(nums[nums.length - 1]);
//        for (int i = nums.length - 2; i >= 0; i--) root.append(nums[i], i, res);
        TreeNode root = null;
        for (int i = nums.length - 1; i >= 0; i--) root = TreeNode.create(root, nums[i], i, res);
        return Arrays.asList(res);
    }

    class TreeNode {
    int val;
    int count;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }

    public static void list(TreeNode root, ArrayList<Integer> list) {
        if (root == null) {
            return;
        }
        list(root.left, list);
        list.add(root.val);
        list(root.right, list);
    }

    @Override
    public String toString() {
        return String.valueOf(val);
    }

    public void append(int v) {
        if (v <= val) {
            if (left == null) left = new TreeNode(v);
            else left.append(v);
        } else {
            if (right == null) right = new TreeNode(v);
            else right.append(v);
        }
    }

    public void append(int v, int i, Integer[] res) {
        if (v <= val) {
            count += 1;
            if (left == null) left = new TreeNode(v);
            else left.append(v, i, res);
        } else {
            res[i] += count + 1;
            if (right == null) right = new TreeNode(v);
            else right.append(v, i, res);
        }
    }

    public static TreeNode create(TreeNode root, int v) {
        if (root == null) {
            root = new TreeNode(v);
        } else if (v <= root.val) {
            root.left = create(root.left, v);
        } else {
            root.right = create(root.right, v);
        }
        return root;
    }

    public static TreeNode create(TreeNode root, int v, int i, Integer[] res) {
        if (root == null) {
            root = new TreeNode(v);
        } else if (v <= root.val) {
            root.count++;
            root.left = create(root.left, v, i, res);
        } else {
            res[i] += root.count + 1;
            root.right = create(root.right, v, i, res);
        }
        return root;
    }
```


