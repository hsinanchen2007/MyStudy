题目的意思是给妹妹分更多种类的糖果。这就只需要考虑尽可能不同种类的分给妹妹就行了。去重之后，看数量是否大于candies / 2 大于的话，肯定能分不同种类。
```
/**
 * leetcode 575. 分糖果
 * 给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。
 * 你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
 *
 * 妹妹要尽可能分更多种类的糖果。
 */
public class DistributeCandies {
    public static int distributeCandies(int[] candies) {
        HashSet<Integer> set = new HashSet<>();
        for (int candy: candies) {
            set.add(candy);
        }
        return Math.min(set.size(), candies.length / 2);
    }
}
```
