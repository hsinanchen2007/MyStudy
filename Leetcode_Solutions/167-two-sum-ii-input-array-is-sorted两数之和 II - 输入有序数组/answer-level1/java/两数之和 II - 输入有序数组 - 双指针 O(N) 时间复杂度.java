#### 解题思路：
使用双指针，一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小元素的指针从头向尾遍历，指向较大元素的指针从尾向头遍历。

1. 如果两个指针指向元素的和 $sum == target$，那么得到要求的结果；
2. 如果 $sum > target$，移动较大的元素，使 $sum$ 变小一些；
3. 如果 $sum < target$，移动较小的元素，使 $sum$ 变大一些。

数组中的元素最多遍历一次，时间复杂度为 $O(N)$。只使用了两个额外变量，空间复杂度为 $O(1)$。


<![图片](https://pic.leetcode-cn.com/99f5e9af82d1a06d4903349de34103addba027d44b500054873a21f4dd01482a-00100.png){:width="100px"}{:align="center"}, ![图片](https://pic.leetcode-cn.com/8ba5a3ef0edb102c75c3354c57162cfb302172b52cf462c23053981bd0e81a96-00101.png){:width="100px"}{:align="center"}, ![图片](https://pic.leetcode-cn.com/2ae8cc5034152b5f12cb0b2b154aedf7b741c42eb3fe4fed38efa1af29074970-00102.png){:width="100px"}{:align="center"}>

#### 代码：
```java [-Java]
public int[] twoSum(int[] numbers, int target) {
    if (numbers == null) return null;
    int i = 0, j = numbers.length - 1;
    while (i < j) {
        int sum = numbers[i] + numbers[j];
        if (sum == target) {
            return new int[]{i + 1, j + 1};
        } else if (sum < target) {
            i++;
        } else {
            j--;
        }
    }
    return null;
}
```
