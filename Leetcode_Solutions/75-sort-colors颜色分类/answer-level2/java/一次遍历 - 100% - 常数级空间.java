### 解题思路
使用三个指针
- 一个指针 tail 指向末位, 用于把 2 放在最后
- 一个指针 head 指向首位, 保证该指针前面不存在 1
- 一个指针 fast 用于遍历, 如果是 1 就过, 如果是 0 则和 head交换

### 代码

```java
public void sortColors(int[] nums) {
    int head=0;
    int fast=0;
    int tail=nums.length-1;
    while(fast<=tail){
        if(nums[fast]==0){
            if(head==fast){
                head++;
                fast++;
            }else{
                nums[fast++]=1;
                nums[head++]=0;
            }
        }else if(nums[fast]==2){
            nums[fast]=nums[tail];
            nums[tail]=2;
            tail--;
        }else{
            fast++;
        }
    }
}
```