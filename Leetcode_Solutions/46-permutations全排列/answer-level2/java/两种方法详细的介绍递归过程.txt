
### 分析1
题目给的结构如下
```
class Solution {
    public List<List<Integer>> permute(int[] nums) {

    }
}
```
首先题目要求返回的类型为 `List<List<Integer>>`，那么我们就新建一个 `List<List<Integer>>` 作为全局变量，最后将其返回。
```
class Solution {

	List<List<Integer>> lists = new ArrayList<>();   
    public List<List<Integer>> permute(int[] nums) {
        return lists;
    }
}
```
再看看返回的结构，`List<List<Integer>>`。因此我们需要写一个包含 `List<Integer>` 的辅助函数，加上一些判断条件，此时结构变成了
```
class Solution {
	List<List<Integer>> lists = new ArrayList<>();   
    public List<List<Integer>> permute(int[] nums) {
        if(nums == null || nums.length == 0){
            return lists;
        }
        List<Integer> list = new ArrayList<>();
        process(list,nums);
        return lists;
    }

  private void process( List<Integer> list, int[] nums) {
  }
}
```
重点就是如何进行递归。递归的第一步，当然是写递归的终止条件啦，没有终止条件的递归会进入死循环。那么有 哪些终止条件呢？由于条件中说了都是正整数。因此，如果 list.size() == nums.length，说明此时找到了一组结果，将其加进去。此时代码结构变成了这样。
```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();   
    public List<List<Integer>> permute(int[] nums) {
        if(nums == null || nums.length == 0){
            return lists;
        }
        List<Integer> list = new ArrayList<>();
        process(list,nums);
        return lists;
    }


    private void process( List<Integer> list, int[] nums) {
        //终止条件
        if(list.size() == nums.length){
            lists.add(new ArrayList<>(list));
            return;
        }
    }
}
```
对于每一个位置的数，都有选和不选两种选择。加入我们用一个list来存储一次递归过程中加入的数字。
因此在递归过程中我们大概需要有这样一段代码。
```java
for (int i = 0; i < nums.length ; i++){
        //加入
       list.add(nums[i]);
       process(list,nums);
        //回退
        list.remove(list.size()-1);
}
```
此时的代码结构变为
```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();   
    public List<List<Integer>> permute(int[] nums) {
        if(nums == null || nums.length == 0){
            return lists;
        }
        List<Integer> list = new ArrayList<>();
        process(list,nums);
        return lists;
    }


    private void process( List<Integer> list, int[] nums) {
        //终止条件
        if(list.size() == nums.length){
            lists.add(new ArrayList<>(list));
            return;
        }
		for (int i = 0; i < nums.length ; i++){
        	//加入
      		 list.add(nums[i]);
       		process(list,nums);
        	//回退
        	list.remove(list.size()-1);
		}
    }
}
```


似乎初具规模，测试一把结果如下
![图片.png](https://pic.leetcode-cn.com/5c6140b787c296eca69ee7289fbe8616be99f7c3bbd610ccf53b0c7693c7b142-WeChat4687306f626f35df807573f35d79ff92.png)

结果差距有点大，为何会出现如此大的反差。因为上面的递归过程会导致我们对同一个数多次加进结果。
为了解决这个问题。我们可以引入一个boolean[] visted表示该位置的数是否已经加入list。
并且如果某个位置的数加入list，visted[该位置]将被设置为true，回退以后，visted[该位置]将被设置为false。
此时代码变为


```
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    boolean[] visted;
    public List<List<Integer>> permute(int[] nums) {
        if(nums == null || nums.length == 0){
            return lists;
        }
        List<Integer> list = new ArrayList<>();
        visted = new boolean[nums.length];
        process(list,nums);
        return lists;
    }

    private void process( List<Integer> list, int[] nums) {
        //终止条件
        if(list.size() == nums.length){
            lists.add(new ArrayList<>(list));
            return;
        }
        for (int i = 0; i < nums.length ; i++) {
            if(!visted[i]){
                visted[i] = true;
                //加入
                list.add(nums[i]);
                process(list,nums);
                //回退
                list.remove(list.size()-1);
                visted[i] = false;

            }
        }
    }
}
```

最后再测一下。
![图片.png](https://pic.leetcode-cn.com/2655943588ad8ddf58005d9bf2ac4339bd4a49af7990e9be7e9e7f72025d19c7-%E5%9B%BE%E7%89%87.png)

代码通过。
### 分析2
对一个数全排列可以看成如下的过程
比如[1,2,3]的全排列可以按如下过程分解。
首先确定第一个数1，然后再对[2,3]做全排列得到[1, 2, 3]和[1, 3, 2]。
首先确定第一个数1，然后再对[1,3]做全排列得到[2, 1, 3]和[2, 3, 1]。
首先确定第一个数3，然后再对[1,2]做全排列得到[3, 1, 2]和[3, 2, 1]。
可清晰的可以得出如下结论permute({1,2,3}) = {1 + permute({2,3})} + {2 + permute({1,3})} + {3 + permute({1,2})}
很明显这是一个递归的过程。将第一个位置的数字进行固定，然后对后面的数字进行递归。那么，如何写代码呢？
 我们可以在递归的过程中，可以将每个位置的数都和第一个数调换一下位置。此轮递归结束以后再进行一次回溯，也就是将数据换回来。
 举个例子，假如要枚举[1, 2, 3]以2开始的所有的排列。首先将2和1调换变为[2, 1, 3]。第一个数定位2.
  然后permute({1,3})。首先得到第一个解2，1，3.然后将1和3进行调换。得到第二个解2,3,1.求出两个解以后需要进行回溯，也就是将数据换回来。
  将1和3的位置换一下变为[2, 1, 3]，将1和2的位置换一下变为[1, 2, 3]。至此，以2开头的这轮过程结束。
###   代码2
```java
List<List<Integer>> lists = new ArrayList<>();

    public List<List<Integer>> permute(int[] nums) {
        process(nums,0);
        return lists;
    }

    //变量start表示到达了某一层。
    private void process(int[] nums, int start) {
        //如果起始位置已经到达了末尾，那么这就是一组解。
        if(start == nums.length){
            List<Integer>list = new ArrayList<>();
            for(int num:nums){
                list.add(num);
            }
            lists.add(list);
        }
        for (int i = start; i < nums.length ; i++) {
            //把第一个元素分别与后面的元素进行交换，递归的调用其子数组进行排序
            swap(nums,i,start);
            process(nums,start+1);
            swap(nums,i,start);

        }
    }

    private void swap(int[] nums, int index1, int index2){
        int tmp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = tmp;
    }
```



