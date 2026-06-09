
![image.png](https://pic.leetcode-cn.com/9cece113a0e910165d2634cf5d5b95ad9723f11481e09d92cab49c95b0b3abd9-image.png)

```
public int[] createTargetArray(int[] nums, int[] index) {
            int[] target=new int[nums.length];
            for (int i = 0; i <nums.length ; i++) {
                for (int j = nums.length-1; j >index[i] ; j--) {//插入位置的数往后移
                    target[j]=target[j-1];
                }
                target[index[i]]=nums[i];
            }
            return target;
    }
```
