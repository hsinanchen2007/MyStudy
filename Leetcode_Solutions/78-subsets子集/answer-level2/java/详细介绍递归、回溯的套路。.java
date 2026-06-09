典型的递归回溯题，本文详细介绍递归回溯的套路。

```
List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> subsets1(int[] nums) {
        if(nums == null || nums.length ==0){
            return lists;
        }

        List<Integer> list = new ArrayList<>();
        process(list, nums, 0);
        return lists;

    }

    private void process(List<Integer>list, int[] nums, int start){

        lists.add(new ArrayList(list));
        for(int i = start; i < nums.length; i++){

            list.add(nums[i]);
            process(list, nums, i+1);
            list.remove(list.size()-1);
        }
    }
```



关于递归回溯的一些套路，参考此文。

从一个题说起

[leetcode 39. 组合总和](https://leetcode-cn.com/problems/combination-sum/)
题目给出的算法结构为
```
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
       
    }
}
```
首先题目要求返回的类型为 `List<List<Integer>>`，那么我们就新建一个 `List<List<Integer>>` 作为全局变量，最后将其返回。
```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
       
        return lists;
    }
}
```
再看看返回的结构，`List<List<Integer>>`。因此我们需要写一个包含 `List<Integer>` 的辅助函数，加上一些判断条件，此时结构变成了
```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null || candidates.length == 0 || target < 0) {
            return lists;
        }

        List<Integer> list = new ArrayList<>();
        process(candidates, target, list);
        return lists;
    }

    private void process(int[] candidates, int target, List<Integer> list) {
    

    }
}
```
重点就是如何进行递归。递归的第一步，当然是写递归的终止条件啦，没有终止条件的递归会进入死循环。那么有 哪些终止条件呢？由于条件中说了都是正整数。因此，如果 `target<0`,当然是要终止了，如果 `target==0`，说明此时找到了一组数的和为 `target`，将其加进去。此时代码结构变成了这样。
```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null || candidates.length == 0 || target < 0) {
            return lists;
        }

        List<Integer> list = new ArrayList<>();
        process(candidates, target, list);
        return lists;
    }

    private void process(int[] candidates, int target, List<Integer> list) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            lists.add(new ArrayList<>(list));
        }
       

    }
}
```
我们是要求组成 `target` 的组合。因此需要一个循环来进行遍历。每遍历一次，将此数加入 `list`，然后进行下一轮递归。代码结构如下。
```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null || candidates.length == 0 || target < 0) {
            return lists;
        }

        List<Integer> list = new ArrayList<>();
        process(candidates, target, list);
        return lists;
    }

    private void process(int[] candidates, int target, List<Integer> list) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            lists.add(new ArrayList<>(list));
        } else {
            for (int i = 0; i < candidates.length; i++) {
                list.add(candidates[i]);
                //因为每个数字都可以使用无数次，所以递归还可以从当前元素开始
                process( candidates, target - candidates[i], list);
      
            }
        }

    }
}
```
似乎初具规模，测试一把结果如下
![图片.png](https://pic.leetcode-cn.com/1188201c79fc60517300e5bd3c1a3dfd1a1f542ccf4c7e6fa26f9b7cf451f2a8-%E5%9B%BE%E7%89%87.png){:width=500}
{:align=center}

结果差距有点大，为何会出现如此大的反差。而且发现一个规律，后面的一个组合会包含前面一个组合的所有的数字，而且这些数加起来和 target 也不相等啊。原因出在哪呢？java 中除了几个基本类型，其他的类型可以算作引用传递。这就是导致 list 数字一直变多的原因。因此，在每次递归完成，我们要进行一次回溯。把最新加的那个数删除。此时代码结构变成这样。
```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null || candidates.length == 0 || target < 0) {
            return lists;
        }

        List<Integer> list = new ArrayList<>();
        process(candidates, target, list);
        return lists;
    }

    private void process(int[] candidates, int target, List<Integer> list) {
        if (target < 0) {
            return;
        }
        if (target == 0) {
            lists.add(new ArrayList<>(list));
        } else {
            for (int i = 0; i < candidates.length; i++) {
                list.add(candidates[i]);
                //因为每个数字都可以使用无数次，所以递归还可以从当前元素开始
                process( candidates, target - candidates[i], list);
                list.remove(list.size() - 1);
            }
        }

    }
}
```
再测一下，结果如下：
![图片.png](https://pic.leetcode-cn.com/92fe23acff8cfd4442d3781252364f5487f5ecc0af307553d7e7da5055a17b5f-%E5%9B%BE%E7%89%87.png){:width=500}
{:align=center}

还是不对。这次加起来都等于 7 了，和上次结果相比算是一个很大的进步了。分析下测试结果。不难能看出，本次结果的主要问题包含了重复的组合。为什么会有重复的组合呢？因为每次递归我们都是从 0 开始，所有数字都遍历一遍。所以会出现重复的组合。改进一下，只需加一个 start 变量即可。 talk is cheap, show me the code。

代码如下：
```
List<List<Integer>> lists = new ArrayList<>();

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if (candidates == null || candidates.length == 0 || target < 0) {
            return lists;
        }

        List<Integer> list = new ArrayList<>();
        process(0, candidates, target, list);
        return lists;
    }

    private void process(int start, int[] candidates, int target, List<Integer> list) {
        //递归的终止条件
        if (target < 0) {
            return;
        }
        if (target == 0) {
            lists.add(new ArrayList<>(list));
        } else {
            for (int i = start; i < candidates.length; i++) {
                list.add(candidates[i]);
                //因为每个数字都可以使用无数次，所以递归还可以从当前元素开始
                process(i, candidates, target - candidates[i], list);
                list.remove(list.size() - 1);
            }
        }

    }

```
最后再测一下。
![图片.png](https://pic.leetcode-cn.com/91e72e57e89bd79da675b9b7d957bddc6e82012f578866c46ca12de008d363ba-%E5%9B%BE%E7%89%87.png){:width=500}
{:align=center}

代码通过，但是效率并不高。本题有效果更好的动态规划的解法。本文主要展示递归回溯，就不做具体介绍了。


是不是有点感觉了，那么再来一题。

[leetcode 77. 组合](https://leetcode-cn.com/problems/combinations/)


题目给出的算法结构为
```
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        
    }
}
```
按照前面的套路，首先建一个 `ArrayList<List<Integer>> res` 作为全局变量。顺带建一个含有 `List<Integer>list` 的辅助函数。

此时结构变成如下所示。


```
class Solution {
     private ArrayList<List<Integer>> res;
    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    private void generateCombinations(int n, int k, int start, List<Integer> list){
        
    }

    public List<List<Integer>> combine(int n, int k) {

        res = new ArrayList<>();
        if(n<=0 || k<=0 || k>n){
            return res;
        }
        List<Integer> list = new ArrayList<>();
        generateCombinations(n,k,1,list);
        
        return res;

    }
}
```
对于辅助递归函数。第一步当然是列出终止条件，避免进入死循环。由于题目要求是所有 k 个数的组合。那么很容易知道递归的终止条件为 `list.size() == k`。
因此，代码结构可变为如下所示。
```
class Solution {
     private ArrayList<List<Integer>> res;
    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    private void generateCombinations(int n, int k, int start, List<Integer> list){
        if(list.size() == k){
            res.add(new ArrayList<>(list));
            return;
        }
    }

    public List<List<Integer>> combine(int n, int k) {

        res = new ArrayList<>();
        if(n<=0 || k<=0 || k>n){
            return res;
        }
        List<Integer> list = new ArrayList<>();
        generateCombinations(n,k,1,list);
        
        return res;

    }
}
```
接下来要进入重头戏了，递归回溯的整个过程。整个递归过程不就是一直将数字加入 list 么。因此可以用一个循环。
在循环中主要做三件事
1.加此轮的数据加入 list。
2.递归进行下一步调用。
3.删除此轮加入的数据进行回溯。

此时代码结构如下：

```
class Solution {
     private ArrayList<List<Integer>> res;
    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    private void generateCombinations(int n, int k, int start, List<Integer> list){
        if(list.size() == k){
            res.add(new ArrayList<>(list));
            return;
        }
        for (int i = start; i <= n ; i++) {
            list.add(i);
            generateCombinations(n,k,i+1,list);
            list.remove(list.size()-1);

        }
    }

    public List<List<Integer>> combine(int n, int k) {

        res = new ArrayList<>();
        if(n<=0 || k<=0 || k>n){
            return res;
        }
        List<Integer> list = new ArrayList<>();
        generateCombinations(n,k,1,list);
        
        return res;

    }
}
```
代码大致结构以及形成，测试一下，结果如下。
![图片.png](https://pic.leetcode-cn.com/ebaff594f2a1d54aea2942213cd55c4ea7054ef51119c2e38b0deabb2ed8d790-%E5%9B%BE%E7%89%87.png){:width=500}
{:align=center}

通过是通过了，但是真的慢成狗啊。
分析一下原因所在。假设 `n = 100`, `k= 90`, `i = 15`，list 里面就 3 个数据。
按照上面的代码，我们还需要继续循环 85 次。但是想一下，即使后面的循环每次都加一个数据，最后也才 88 个数据。
不能形成一组解。也就是说这些循环都是在做无用功，因此引出一个很重要的知识点。 **剪枝**
循环的终止条件不应该是 `i<=n`,  应该是 `i-1 +(k-list.size()) <= n`。

因此代码如下:
```
class Solution {
     private ArrayList<List<Integer>> res;
    // 求解C(n,k), 当前已经找到的组合存储在c中, 需要从start开始搜索新的元素
    private void generateCombinations(int n, int k, int start, List<Integer> list){
        if(list.size() == k){
            res.add(new ArrayList<>(list));
            return;
        }
        for (int i = start; i <= n-(k-list.size())+1 ; i++) {
            list.add(i);
            generateCombinations(n,k,i+1,list);
            list.remove(list.size()-1);

        }
    }

    public List<List<Integer>> combine(int n, int k) {

        res = new ArrayList<>();
        if(n<=0 || k<=0 || k>n){
            return res;
        }
        List<Integer> list = new ArrayList<>();
        generateCombinations(n,k,1,list);
        
        return res;

    }
}
```
最后运行结果如下。
![图片.png](https://pic.leetcode-cn.com/b30e72b1af706352dd7664b994ddd4bb92b3cda615335a710a4ecb2be12b4d67-%E5%9B%BE%E7%89%87.png){:width=500}
{:align=center}

### [更多题解见本人github](https://github.com/reedfan/leetcode/tree/master/src/main/java/leetcode)

