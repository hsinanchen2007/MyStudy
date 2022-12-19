### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] createTargetArray(int[] nums, int[] index) {
        int[] target = new int[nums.length];
        for (int i = 0; i < target.length; i++) {
            insert(target, index[i], nums[i]);
        }
        return target;
    }
    public void insert(int[] target,int index,int num){
        int temp=target[index];
        target[index] = num;
        for (int i = index+1; i < target.length; i++) {
            temp = target[i] ^ temp;
            target[i] = target[i] ^ temp;
            temp = target[i] ^ temp;
        }
    }
}
```