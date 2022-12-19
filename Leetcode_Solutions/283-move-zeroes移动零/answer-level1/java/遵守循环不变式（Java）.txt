
循环不变式就是在循环的开始、中途、结束都遵守的性质，遵守循环不变式，可以帮助我们正确写好代码，弄清楚边界。

「循环不变式」是《算法导论》这本书中的内容，很有用，不是很难的知识点，感兴趣的朋友可以阅读一下。

![image.png](https://pic.leetcode-cn.com/5a69b7c30f9c4884c0e76d7733e4f545e5a5b50742065d8df1541a8de31c61c8-image.png)

建议：这本书初学算法的朋友最好带着问题去看，只看需要的部分。


### 方法一：覆盖的写法


**参考代码 1**：

```Java []
public class Solution {

    public void moveZeroes(int[] nums) {
        int len = nums.length;
        if (len < 2) {
            return;
        }

        int next = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                // 遵守循环不变式：[0, i) 非零，所以先赋值，后自增
                nums[next] = nums[i];
                next++;
            }
        }

        // 把剩下的部分设置为 0
        for (int i = next; i < len; i++) {
            nums[next] = 0;
            next++;
        }
    }
}
```

### 方法二：交换元素的写法


**参考代码 2**：
```Java []
public class Solution {

    // 循环不变式：
    // [0, notZero) 非零
    // [Zero, i) == 0
    // i == len 时停止

    public void moveZeroes(int[] nums) {
        int len = nums.length;
        if (len < 2) {
            return;
        }

        int notZero = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                swap(nums, notZero, i);
                notZero++;
            }
        }
    }

    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```

如果修改了循环不变式的定义，初始化的值和在循环中的操作就会有细微的变化。


**参考代码 3**：
```Java []
public class Solution {

    // 循环不变式：
    // [0, notZero] 非零
    // (Zero, i) == 0
    // i == len 时停止

    public void moveZeroes(int[] nums) {
        int len = nums.length;
        if (len < 2) {
            return;
        }
        int notZero = -1;
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                notZero++;
                swap(nums, notZero, i);
            }
        }
    }

    private void swap(int[] nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```
