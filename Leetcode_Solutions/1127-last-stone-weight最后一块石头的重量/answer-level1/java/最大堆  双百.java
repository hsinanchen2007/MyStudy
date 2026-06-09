*1ms 100%  34MB 100%*

**步骤：**
* 初始化最大堆
* 循环（直至Math.max(stones[1], stones[2])==0）
  * 按要求修改堆顶两个元素
  * 重新调整最大堆

**代码如下：**
```
public int lastStoneWeight(int[] stones) {
    int len = stones.length;
    if (len==1) {
        return stones[0];
    }else if (len==2) {
        return Math.abs(stones[0]-stones[1]);
    }else {
        for (int i = len/2-1; i >= 0 ; i--) {
            maxHeap(stones, i, len-1);
        }
        int temp;
        while ((temp=Math.max(stones[1], stones[2]))!=0) {
            stones[0]-=temp;
            if (stones[1]>stones[2]) {
                stones[1]=0;
            }else {
                stones[2]=0;
            }
            for (int i = 2; i >= 0 ; i--) {
                maxHeap(stones, i, len-1);
            }
        }
        return stones[0];
    }
}
public void maxHeap(int[] nums, int root, int end) {
    int l=2*root+1;
    int temp=nums[root];
    while (l<=end && (nums[l]>temp || (l+1<=end && nums[l+1]>temp))) {
        if (l+1<=end && nums[l+1]>nums[l]) {
            l++;
        }
        nums[root]=nums[l];
        nums[l]=temp;
        root=l; l=2*root+1;
        temp=nums[root];
    }
}
```
