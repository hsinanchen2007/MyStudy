### 双重循环思路
看到题第一想法肯定是双重循环，取index=0的数，分别和index+1后的数相加是否=target，等于直接返回两个index即可。
双重循环时间复杂度就肯定是O(n^2)了。优化就还是一句话，空间换时间，所有引入哈希表

### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        for (int i = 0; i < length; i++) {
            int first = nums[i];
            for (int j = i+1; j < length; j++) {
                int secend = nums[j];
                if (target - first == secend){
                    return new int[]{i,j};
                }
            }
        }
        return null;
    }
}
```

### 哈希
引入HashMap最大的争议，肯定是HashMap的reSize，这个问题我想的是，初始化的时候直接把nums.length传进去，HashMap就会根据length向2^n次方 向上取大小了，免去了put时的reSize.
还看到有人对containsKey有疑惑，HashMap的containsKey其实就是一个get操作，时间复杂度我们都知道最好情况是O(1)最坏情况是O(n)。
HashMap的数据结构是数组+链表（达到界定条件转红黑树）,数组+链表时的get操作，时间复杂度都是O(1)的，而我们要知道链表转红黑树的条件是，某个Hash值因为频繁被碰撞，链表的长度>7就转为红黑树。
而本题的数组转HashMap，即使在最坏的情况下转变为了红黑树，举例[1,2,3,3,3,3,3,3,3,3,4,5] target=8
i=2时put第一个3进入Map，我们后续7个3进入，3的存储结构会变为红黑树，但是我们containsKey(5)是不会跑到红黑树上去遍历的,因为8-3!=3。
那如果target=6呢？我们就需要去判断containsKey(3),而根据代码，我们执行到i=2，put第一个3进入Map，没有适合的值，进入下一次循环i=3，我们还是判断containsKey(3)，但是此时，我们的Map中只有一个3，也是3Hash后存放的entry其实只有一个，永远达不到红黑树，所以，我们的containsKey在本题中的时间复杂度只会是O(1)


### 代码

```java
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int length = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>(length);
        for (int i = 0; i < length; i++) {
            int result = target - nums[i];
            if (map.containsKey(result)){
                return new int[]{map.get(result),i};
            }
            map.put(nums[i],i);
        }
        return null;
    }
}
```