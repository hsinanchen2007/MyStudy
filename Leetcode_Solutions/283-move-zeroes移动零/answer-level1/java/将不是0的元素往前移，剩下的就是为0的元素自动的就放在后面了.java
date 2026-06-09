```
int index = -1;  // 定一个标准
// 找到第一个下标是0的数
for(int i = 0;i < nums.length;i++){
    if(nums[i] == 0){
        index = i;
        break;
    }
}
// index不是-1证明nums中有0，则进行下面的操作
if(index != -1){
    for(int i = 0;i < nums.length;i++){
        if(nums[i] != 0 && i > index){
            // 在第一个0后面的数字需要进行换位置
            nums[index] = nums[i];
            nums[i] = 0;
            // 交换后index的值需要后移一位
            index++;
        }
    }
}
```


![屏幕快照 2019-12-03 16.56.31.png](https://pic.leetcode-cn.com/c0563bf7ee69f6a8cb0015ea64578e2e41da7f484b89cc8dc6f30742c9c5aeb0-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-03%2016.56.31.png)

