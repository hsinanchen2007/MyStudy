获取n个数全排列的基本思路：

    先确定第一个，再确定第二个，依此类推，直到确定第n个。

    确定第一个时，有n种可能，第一个一旦确定，确定第二个时，有n-1种可能，依此类推。

    确定第n个时，只有一种可能。

    简单讲，就是循环+递归。

确定第k(k属于[1,n])个的方法：

    算法转换为代码时需要考虑的更多，其中就包括，如何实现“选中第k个”。
    
    如果，将选中的拿出来，放到一个数组里，那么需要记录原来的数组中，哪些被选过了，哪些没有被选过，这可能都需要开辟新的空间，而且还需要频繁的进行添加操作。

    另一种可能的实现便是，在确定第k个时，将选中的元素与第k个位置的元素的值进行交换，每次迭代完成后再交换回来，以免影响其他循环和递归。

代码如下：

```
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        int length = nums.length;
        //List<Integer> numsList = Arrays.stream(nums).boxed().collect(Collectors.toList());
        //int数组转化为list
        ArrayList<Integer> numsList = new ArrayList<Integer>();
        for (int num : nums) {
            numsList.add(num);
        }
        List<List<Integer>> ans = new ArrayList<>();
        run( ans, numsList, 0,length - 1);
        return ans;
    }
    private void run(List<List<Integer>> ans,List<Integer> numsList, int pos, int last) {
        if (pos == last) {
            ans.add(new ArrayList(numsList));
        } else {
            for (int i = pos; i <= last; i ++) {
                Collections.swap(numsList, pos, i);
                run(ans, numsList, pos + 1, last);
                Collections.swap(numsList, pos, i);
            }
        }
    }
}
```
需要注意的是，尽管思路是相同的，某些细节的实现的不同，可能会导致性能上的巨大差异。比如：

    由于结果是List<List<Integer>>类型的，而参数是int[]类型的，需要将int[]类型转换为List<Integer>类型，两种类型之间又不能隐式（直接转换），

    所以什么时候转换，怎么转换就需要好好考虑一下。
    
    实践证明，使用Arrays.stream(nums).boxed().collect(Collectors.toList())这种方法转换要比for循环转换慢。

    而且，在调用递归方法前转换，要比在递归方法中转换快（转换一次和转换多次）。

循环递归的一种理解方式：

    相对于从结合代码、处理细节的角度理解循环递归，单纯从思路上、宏观上理解循环递归还是比较容易的。思路——》代码的转换，可以尝试使用：树形图。

    简单讲就是深度优先的遍历（需要虚拟一个根节点）。循环在后，递归在前（先写的循环代码，但，先执行的递归代码）