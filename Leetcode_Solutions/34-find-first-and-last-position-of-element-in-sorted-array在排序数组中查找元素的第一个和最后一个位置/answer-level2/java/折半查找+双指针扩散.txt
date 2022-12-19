### 解题思路
1. 先折半查找该元素
2. 找到后以该点作为中心，双指针向两个方向同时找
3. 注意处理折半查找的时候head 和tail的值，相差1个的时候要特殊处理

### 代码

```java
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if(nums.length == 0){
            return new int[]{-1,-1};
        }
        // 跳跃指针
        int jumper = 0;
        int head = 0;
        int tail = nums.length-1;
        boolean found = false;
        while (head <= tail){
            if(target > nums[tail] || target < nums[head]){
                head = -1;
                tail = -1;
                break;
            }
            // 存在一个问题就是head + tail除以2始终不会变化
            // 比如0+1 /2 4+5 /2 这些数字会把jumper指针钉住
            // 要解决这个问题
            if(head+1 == tail){
                if(nums[head] == target && nums[tail] == target){
                    return new int[]{head, tail};
                }
                if(nums[head] != target && nums[tail] == target){
                    return new int[]{tail, tail};
                }
                if(nums[head] == target && nums[tail] != target){
                    return new int[]{head, head};
                }
                if(nums[head] != target && nums[tail] != target){
                    return new int[]{-1, -1};
                }
            }
            // 如果间距仍然很远
            jumper = (head+tail) / 2;
            if(nums[jumper] == target){
                // 找到了，开始向两边扩散
                found = true;
                head = jumper;
                boolean changed = false;
                while(head >=0 && nums[head] == target){
                    head--;
                    changed = true;
                }
                if(changed){
                    head++;
                }
                tail = jumper;
                changed = false;
                while(tail <nums.length && nums[tail] == target){
                    tail++;
                    changed = true;
                }
                if(changed){
                    tail--;
                }
                break;
            }else if(nums[jumper] > target){
                tail = jumper;
            }else if(nums[jumper] < target){
                head = jumper;
            }
        }
        if(!found){
            return new int[]{-1,-1};
        }
        return new int[]{head,tail};
    }
}
```