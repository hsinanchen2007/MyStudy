![Image.png](https://pic.leetcode-cn.com/4b581301c25b69113ce6f8314c3a758d183cd60ed54f80362cbcddfed800781b-Image.png)
所以规律：
1.head和rear相等,rear右移
2.head和rear不等,head右移然后更新所在的位置值

```java
public int removeDuplicates(int[] nums) {
    if(nums.length < 2){
        return nums.length;
    }
    if(nums.length == 2){
        return nums[0] == nums[1] ? 1 : 2;
    }
    int head = 0, rear = 1;
    while(rear < nums.length){
        if(nums[head] == nums[rear]){
            //相等的话，rear右移
            rear++;
        }else{
            //不等的话，head右移，将移动后的位置变成rear位置的值
            head++;
            nums[head] = nums[rear];
        }
    }
    return head+1;
}
```

