
# 方法一：递归

递归方法总而言之就是抓住三点：

* 找整个递归的终止条件
* 找返回值
* 一次递归需要如何操作

## 找整个递归的终止条件

咱来分析一下题目，递归到``numRows = 0`` 时或者``numRows = 1``时都可以终止，因为第一行比较特殊，只有一个`1`,所以我们可以将其当成整个递归的终止条件，当``numRows = 1``时，我们就可以终止递归向下返回值了。

## 找返回值

找返回值，我们也需要分析下，题目要我们求的是整个杨辉三角的所有数，那最后递归得到的应该就是  ``List<List<Integer>>`` (题目给定)，也就是每递归完一层，我们就更新完List并返回即可，最后递归完成就是我们要的答案。

## 一次递归需要如何操作

递归的难点就在这里，很多童靴刚学递归时，总是在这里搞晕，其实我们只需要关注一次递归即可，因为每一层递归的过程都是一样的，我们只需要找到最上层的递归的规律，就可以了。

![image-20200102202952363](https://pic.leetcode-cn.com/7c57ef42179104ba0d202392e75499e3ac96092d84a8ede7783d5c1b53eac975.jpg)

如图所示，我们只需要分析 第二行到第三行 这级递归即可！先上代码！

# 递归 代码

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
    		//存储要返回的杨辉三角
        List<List<Integer>> dg = new ArrayList<>();
        //若0行，则返回空
        if(numRows == 0){
            return dg;
        }
        //递归出口，这是第一步！找到出口
        if(numRows == 1){
            dg.add(new ArrayList<>());
            dg.get(0).add(1);
            return dg;
        }
        //递归，注意返回值！！！这是第二步
        dg = generate(numRows-1);
        //一级递归要做啥，我们可以看第二行到第三行需要做啥
        //首先是要申请一个list来存储第三行，然后通过第二行得到第三行
        //第三行的首尾为1是确定了的，然后就是中间的数如何得到
        //通过观察很容易拿到for循环里面的式子
        //最后别忘了返回值！！！
        List<Integer> row = new ArrayList<>();
        row.add(1);
        for(int j = 1;j < numRows - 1;j++){
            row.add(dg.get(numRows-2).get(j-1) + dg.get(numRows-2).get(j));
        }
        row.add(1);
        dg.add(row);
        return dg;
    }
}
```

# 方法二：动态规划

思路其实差不多，只是一个递归，一个变成了迭代而，仅此而已！

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
         List<List<Integer>> dp = new ArrayList<>();
        if(numRows == 0){
            return dp;
        }
        dp.add(new ArrayList<>());
        dp.get(0).add(1);
        //注意这里的 i 是指行数，但是dp是从0开始的
        //所以preRow是i-2
        for(int i = 2;i <= numRows;i++){
            List<Integer> row = new ArrayList<>();
            List<Integer> preRow = dp.get(i-2);
            row.add(1);
            for(int j = 1;j < i-1;j++){
                row.add(preRow.get(j) + preRow.get(j-1));
            }
            row.add(1);
            dp.add(row);
        }
        return dp;
    }
}
```


第一次写题解 写的不太好！ 见谅！！！


