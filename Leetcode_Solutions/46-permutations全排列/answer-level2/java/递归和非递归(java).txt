【算法思想】
【1】的全排列：
【1】

【1，2】的全排列：
【1】前后共有2个位置可以插入2，故有【1，**2**】【**2**，1】

【1，2，3】的全排列：
【1，2】前中后共有3个位置可以插入3，故有【**3**，1，2】【1，**3**，2】【1，2，**3**】
【2，1】前中后共有3个位置可以插入3，故有【**3**，2，1】【2，**3**，1】【2，1，**3**】

推广到n
n 个数字的全排列可在其前 n-1 个数字的全排列的基础上，分别向其中 n 个可能的位置插入第 n 个数字得到

【java代码(递归)】时间和空间指标一般，凑活看看
```
    private List<List<Integer>> permute_fun(int[] nums, int n) {//返回n个数字的全排列
        List<List<Integer>> ans = new LinkedList<>();
        if (n == 1) {//退出条件，返回第一个数字的全排列
            List<Integer> list = new ArrayList<Integer>();
            list.add(nums[0]);
            ans.add(list);
            return ans;
        }
        List<List<Integer>> preAns = permute_fun(nums, n - 1);//获取前n-1个数字的全排列
        for (List<Integer> list : preAns) {
            for (int i = 0; i < n; i++) {//在n个可能的位置插入第n个数字
                List<Integer> newList = new ArrayList<Integer>();
                newList.addAll(list);
                newList.add(i, nums[n - 1]);
                ans.add(newList);
            }
        }
        return ans;
    }

    public List<List<Integer>> permute(int[] nums) {
        return permute_fun(nums, nums.length);
    }
```

【java代码(非递归)】时间和空间指标一般，凑活看看
```
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new LinkedList<>();
        List<List<Integer>> preAns = null;
        List<Integer> newList = null;
        for (int i = 1; i <= nums.length; i++) {//求1个数的全排列，2个数的全排列。。。n个数的全排列
            if (i == 1) {//1个数的全排列
                newList = new ArrayList<Integer>();
                newList.add(nums[0]);
                ans.add(newList);
                continue;
            }
            preAns = ans;
            ans = new LinkedList<>();
            for (List<Integer> list : preAns) {//遍历前n-1个数的全排列
                for (int j = 0; j < i; j++) {//在n个可能的位置插入第n个数字
                    newList = new ArrayList<Integer>();
                    newList.addAll(list);
                    newList.add(j, nums[i - 1]);
                    ans.add(newList);
                }
            }
        }
        return ans;
    }
```