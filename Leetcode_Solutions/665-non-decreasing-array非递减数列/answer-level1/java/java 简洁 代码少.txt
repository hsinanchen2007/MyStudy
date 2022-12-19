![image.png](https://pic.leetcode-cn.com/0e695b82ee5b2d8fe2d9e94bbd89be91c4d231905c84d0ad34eeb33a9dfb892a-image.png)

```
        int temp = nums[0];
        int count = 0;
        for(int i = 1;i<nums.length;i++){
            if(temp > nums[i]){ 
                 if((++count) == 2) return false;
                 if(i>1&&nums[i]<nums[i-2]) continue;
            }
            temp = nums[i];
        }
        return true;
```
