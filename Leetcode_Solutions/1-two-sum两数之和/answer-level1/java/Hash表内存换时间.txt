### 原问题
来源：力扣（LeetCode）  
链接：https://leetcode-cn.com/problems/two-sum
>给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
> 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

> 示例:
> 给定 nums = [2, 7, 11, 15], target = 9  
> 因为 nums[0] + nums[1] = 2 + 7 = 9  
> 所以返回 [0, 1]
### 解题思路
#### 滑动窗口（错误）
首先想到的是滑动窗口，即最左和最右相加，然后大了往左移，小了往右移，但是经试验不发现不行。
```java
import java.util.Arrays;

/**
 * @author 17326
 * @date 2020/4/10 11:41
 */
public class EASY_1 {
    public int[] twoSum(int[] nums, int target) {
        Arrays.sort(nums);
        for(int i = 0, j = nums.length -1; i < j;){
            int sum = nums[i] + nums[j];
            if(sum == target){
                return new int[]{i,j};
            }else if (sum > target){
                --j;
            }else{
                ++i;
            }
        }
        throw new NullPointerException();
    }

    public static void main(String[] args) {
        int [] nums = new int[]{3, 2, 4};
        int target = 6;
        EASY_1 easy_1 = new EASY_1();
        for(int i : easy_1.twoSum(nums, target)){
            System.out.println(i);
        }
    }
}
```
当 ```3+4 = 7```时太大往左移，然后只能```3+2```，此时就没办法继续移动了。而答案是```2+4```

#### 暴力法
因为限定了两个数字之和，所以最简单、直接的做法，直接```O(n²)```的算法
```java
/**
 * @author 17326
 * @date 2020/4/10 11:41
 */
public class EASY_1 {
    public int[] twoSum(int[] nums, int target) {
        for(int i = 0; i < nums.length; i++){
            int value = target - nums[i];
            for(int j = 0; j < nums.length; j++){
                if(nums[j] == value && i != j){
                    return new int[]{i,j};
                }
            }
        }
        throw new NullPointerException();
    }

    public static void main(String[] args) {
        int [] nums = new int[]{2, 7, 11, 15};
        int target = 9;
        for(int i : new EASY_1().twoSum(nums, target)){
            System.out.println(i);
        }
    }
}
```
即通过二重循环，暴力搜索符合条件的数字索引，起初i循环条件想设置为```i < nums.length / 2 + 1```，因为想着只要搜索一半就好了，后来发现想法有问题，因为有可能两个数字都在右边。
#### Hash表
以上直接通过暴力搜索效率太低，可以改善搜索方法，问题的本质是搜索值```value```，所以我们可以将```value```作为索引，且数组的索引和值在各自维度都是唯一的，可以使用```Map```反转数组的索引方法，```map```中```key```定义为数组中的```value```, ```map```中```value```定义为数组中的```index```。
```java
import java.util.HashMap;
import java.util.Map;

/**
 * @author 17326
 * @date 2020/4/10 11:41
 */
public class EASY_1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map = new HashMap<>((int)(nums.length / 0.75 + 1));
        for(int i = 0; i < nums.length; i++){
            map.put(nums[i], i);
        }
        for(int i = 0; i < nums.length ; i++){
            int expected = target - nums[i];
            Integer value = map.get(expected);
            if(value != null && i != value){
                return new int[]{i, value};
            }
        }
        throw new NullPointerException();
    }

    public static void main(String[] args) {
        int [] nums = new int[]{2, 7, 11, 15};
        int target = 9;
        for(int i : new EASY_1().twoSum(nums, target)){
            System.out.println(i);
        }
    }
}
```
结果：
> 执行用时 : 3 ms , 在所有 Java 提交中击败了 89.25% 的用户  
> 内存消耗 : 40 MB , 在所有 Java 提交中击败了 5.13% 的用户

#### Hash表优化
上述方法遍历了两次Hash表，查看官方题解可以只遍历一次
```java
import java.util.HashMap;
import java.util.Map;

/**
 * @author 17326
 * @date 2020/4/10 11:41
 */
public class EASY_1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map = new HashMap<>((int)(nums.length / 0.75 + 1));
        for(int i = 0; i < nums.length ; i++){
            int expected = target - nums[i];
            if(map.containsKey(expected)){
                return new int[]{map.get(expected), i};
            }
            map.put(nums[i], i);
        }
        throw new NullPointerException();
    }

    public static void main(String[] args) {
        int [] nums = new int[]{2, 7, 11, 15};
        int target = 9;
        for(int i : new EASY_1().twoSum(nums, target)){
            System.out.println(i);
        }
    }
}
```
### 代码
```java
import java.util.HashMap;
import java.util.Map;

/**
 * @author 17326
 * @date 2020/4/10 11:41
 */
public class EASY_1 {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> map = new HashMap<>((int)(nums.length / 0.75 + 1));
        for(int i = 0; i < nums.length ; i++){
            int expected = target - nums[i];
            if(map.containsKey(expected)){
                return new int[]{map.get(expected), i};
            }
            map.put(nums[i], i);
        }
        throw new NullPointerException();
    }

    public static void main(String[] args) {
        int [] nums = new int[]{2, 7, 11, 15};
        int target = 9;
        for(int i : new EASY_1().twoSum(nums, target)){
            System.out.println(i);
        }
    }
}
```
> 执行用时 : 2 ms , 在所有 Java 提交中击败了 99.60% 的用户  
> 内存消耗 : 39.6 MB , 在所有 Java 提交中击败了 5.13% 的用户