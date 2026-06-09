```
题目描述:
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。

示例：
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 
 ```



看到这道题的第一想法，暴力暴力，能用暴力解决的事情不要和我谈其他。

于是，两个for循环噼里啪啦。
```
    //方法一：简单暴力，两个for循环搞定
    public int[] twoSum1(int[] nums, int target) {
        int[] temp = new int[2];//用来存要找的数的下标
        for(int i = 0; i < nums.length; i++){
            for(int j = i + 1; j < nums.length; j++){
                if(nums[i] + nums[j] == target){
                    temp[0] = i;
                    temp[1] = j;
                    return temp;
                }
            }
        }
        return null;
    }
```


不过心里才两个循环时间复杂度可是n的平方，心想肯定得超时，不过还是大胆提交一下提交，呵呵，居然通过了。。。。

我猜这可能是第一道题的原因，让我们开心一下。不过排名你懂的。

不过居然要刷题，要学习算法，那么肯定是不能满足于「第一想法」的，必须得找出我们自己能接受的最优解。

于是我想到了用空间换时间，就是我们可以用哈希表映射的方法，先把数组里所有元素的值作为key，下标作为value存进hashmap里，我们知道从hashmap里查找元素的时间复杂度近似常数，即O(1)。然后我们可以用一个for循环来遍历数组，遍历的过程中一边查找另一个数是否在hashMap里，例如a = nums[i]，然后查找b = targert - a是否在hashMap里，如果在，则证明a,b便是要找的数，否则继续查找。代码下：

```
public int[] twoSum2(int[] nums, int target){
        int[] temp = new int[2];
        Map<Integer,Integer> map = new HashMap<>();
        for(int i = 0; i < nums.length; i++){
            map.put(nums[i], i);
        }
        //遍历查找
        for(int i = 0; i < nums.length; i++){
            int a = nums[i];
            if(map.containsKey(target - a)){
                temp[0] = i;
                temp[1] = map.get(target - a);
                return temp;
            }
        }
        return null;
    }
```


不过，不知道大家发现问题了没有，题目里只是说会有唯一解，并且一个元素只能用一次，但并没有说，不能两个元素的值相同，也就是说，数组如果有元素的值相同的话，存进hashMap会出现**冲突**的情况。所以，这样先把数组的所有元素存进hashMap的做法是不严谨的。

我们来分析一下处理方法：

出现这个问题的本质原因是因为我们要找的那两个数刚好相等，导致我们当今哈希表的时候出现了丢失的情况。如何解决？

上面说了，问题的原因是这两个我们要的数刚好相等，并且我们从一开始就想把他们两个硬塞进哈希表里，导致一山容不了二虎。其实，我们可以换一种想法啊，我们可以一边遍历查找一边把数放进哈希表里啊。
先看代码:

```
public int[] twoSum3(int[] nums, int target){
        int[] temp = new int[2];
        Map<Integer,Integer> map = new HashMap<>();
        //遍历查找
        for(int i = 0; i < nums.length; i++){
            int a = nums[i];
            if(map.containsKey(target - a)){
                temp[0] = map.get(target - a);
                temp[1] = i;
                return temp;
            }else {//如果找不到则存进去
                map.put(nums[i], i);
            }
        }
        return null;
    }
```

就是取出数a=nums[i],先判断b=target-a在不在哈希表里，如果在，那么a和b就是要找的值了，如果不在，就把a放进哈希表了。
这样，就不会出现上面那种情况的冲突了，因为两个我们要找的数，只有一个会放在哈希表里。