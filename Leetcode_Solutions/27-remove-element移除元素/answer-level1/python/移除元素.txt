1. 主要是在原地移除和目标值相等的元素，不使用额外的数组空间，我们可以建立两个指针，都从数组的起始位置0开始
2. 两个指针一快一慢，快指针j，遇到和目标值val相等的元素先跳过。（反向思维，正常来讲都是遇到相等的就停止，那样的话会超出时间空间限制）
3. 跳过后的下一次循环，直到遇到和目标值val不等的元素，就将当前下标为j的值，复制给下标为i的慢指针所对应的值，再把i加1
4. 最后返回i的值就是新数组的长度

```
        if (nums.length == 0){
            return 0;
        }
        int i = 0;
        for(int j = 0;j < nums.length; j++){
            if(nums[j] != val){
                nums[i] = nums[j];
                i += 1;
            }
        }
        return i;
```

```
        i = 0
        for j in range(len(nums)):
            if nums[j] != val:
                nums[i] = nums[j]
                i+=1
        return i
```



