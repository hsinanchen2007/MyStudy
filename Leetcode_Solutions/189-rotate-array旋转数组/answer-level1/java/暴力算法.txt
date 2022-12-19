```
public class Rotate_189 {

    public void rotate(int[] nums, int k) {
        if (nums == null || nums.length == 0 || k < 1) return;
        // 总共经历k轮循环
        for (int i = 0; i < k; i++) {
            int temp = nums[nums.length - 1];
            // 倒序遍历，然后赋值
            for (int j = nums.length - 1; j > 0; j--) {
                nums[j] = nums[j - 1];
            }
            nums[0] = temp;
        }
    }
}
```
