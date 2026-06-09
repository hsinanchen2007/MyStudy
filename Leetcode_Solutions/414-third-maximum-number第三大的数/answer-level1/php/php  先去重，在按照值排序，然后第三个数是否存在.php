![图片.png](https://pic.leetcode-cn.com/f8f2dade1e78e349bcd70be0332441ccae31de94122e841e3c57c0a714deb13f-%E5%9B%BE%E7%89%87.png)
```
function thirdMax($nums) {
        $list = array_flip($nums);
        $nums = array_keys($list);
        rsort($nums);
       return  isset($nums[2]) ?$nums[2]:max($nums);
    }
```
