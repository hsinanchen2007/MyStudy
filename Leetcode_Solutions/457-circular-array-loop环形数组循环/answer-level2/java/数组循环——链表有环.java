参考别人代码写的~思路类似快慢指针判断链表是否有环，在注释里
```
class Solution {
    public boolean circularArrayLoop(int[] nums) {
        if(nums.length == 0 || nums.length == 1 || nums == null) return false;//处理特殊情况
        for(int i = 0; i < nums.length; i++){
            //慢指针j从i的位置开始移动(类似 slow = node)，快指针k从i移动一次以后的位置开始移动（类似 fast =node.next)
            int j = i, k = next(nums, i);
            //保证快慢指针始终向着nums[i]表示的同一个方向移动,>0始终右，反之始终左
            while(nums[i]*nums[j] > 0 && nums[i]*nums[k] > 0 && nums[i]*nums[next(nums,k)] > 0){
                //System.out.println("i"+i);
                if(j == k){//快慢指针相遇(在循环中相遇，类似于在环形链表中相遇)
                    if(j == next(nums, j)){break;}//循环长度未1不能true
                    return true;                       
                }
                j = next(nums,j);//移动慢指针 类似于slow=slow.next;
                //System.out.println("j"+j);
                k = next(nums,next(nums,k));//移动快指针，类似于fast= fast.next.next;
                //System.out.println("k"+k);
            }
        }
        return false;
    }
        //计算下一个位置时，避免越界
        private int next(int[] nums, int i){
            int next = i + nums[i];
            if(next >= 0) return next%nums.length; //合并0~nums.length的部分
            else {return nums.length+next%nums.length;}
        }
}
```
