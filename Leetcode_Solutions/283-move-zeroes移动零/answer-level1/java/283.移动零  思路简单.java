思路：
1. 定义变量： nonzeroIndex 记录非零数应该赋值到的索引位置。
2. 双层判断：第一层判断只操作非零数；第二层判断当前非零数索引值要大于 nonzeroIndex时做移动数据操作

```
public void moveZeroes(int[] nums) {
        int nonzeroIndex = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (i > nonzeroIndex) {
                    nums[nonzeroIndex] = nums[i];
                    nums[i] = 0;
                }
                nonzeroIndex++;
            }
        }
    }
```
