这道题一看到第一反应竟然是暴力解，没想到时间还短，应该是数组长度不够大，测试例子不够刁钻
```
    int i = 0;
    for(i = 0; i < nums.length; i++){
        if(nums[i] == target)
            break;
        if(nums[i] > target)
            break;
    }
    return i;
```
        