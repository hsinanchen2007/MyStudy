```
//循环问题：用快慢指针解决
//计算 next 位置，对于会超出数组的长度的正数，我们可以通过对n取余，但是对于负数，若这个负数远大于n的话，取余之前只加上一个n，可能是不够的，所以正确的方法是应该先对n取余，再加上n。为了同时把正数的情况也包含进来，最终我们的处理方法是先对n取余，再加上n，再对n取余，这样不管正数还是负数，大小如何，都可以成功的旋转跳跃了。
int getnext(int* nums,int i,int numsSize) {
    return (((nums[i] + i) % numsSize) + numsSize) % numsSize;
}

bool circularArrayLoop(int* nums, int numsSize){
    for(int i = 0;i < numsSize;i++) {
        if(nums[i] == 0) {//如果遇到已经访问过，被标记的地方
            continue;//我们也可以不用 visited 数组，直接在 nums 中标记，由于题目中说了 nums 中不会有0，所以可以把访问过的位置标记为0
        }
        int slow = i;//对于每个i位置，慢指针指向i
        int fast = getnext(nums,i,numsSize);//快指针指向下一个位置，这里调用子函数来计算下一个位置
        int val = nums[i];
        while(val * nums[fast] > 0 && val * nums[getnext(nums,fast,numsSize)] > 0) {//慢指针指向的数要和快指针指向的数正负相同，这个不难理解。并且慢指针指向的数还要跟快指针的下一个位置上的数符号相同
            if(slow == fast) {
                if(slow == getnext(nums,slow,numsSize)) {//直到当快慢指针相遇的时候，就是环出现的时候，但是这里有个坑，即便快慢指针相遇了，也不同立马返回 true，因为题目中说了了环的长度必须大于1，所以我们要用慢指针指向的数和慢指针下一个位置上的数比较，若相同，则说明环的长度为1，此时并不返回 false，而且 break 掉 while 循环。因为这只能说以i位置开始的链表无符合要求的环而已，后面可能还会出现符合要求的环。但是若二者不相同的话，则已经找到了符合要求的环，直接返回 true。
                    break;
                }
                return true;
            }
            //若快慢指针还不相同的，则分别更新，慢指针走一步，快指针走两步
            slow = getnext(nums,slow,numsSize);
            fast = getnext(nums,getnext(nums,fast,numsSize),numsSize);
        }
        //当 while 循环退出后，我们需要标记已经走过的结点，从而提高运算效率，方法就是将慢指针重置为i，再用一个 while 循环，条件是 nums[i] 和 慢指针指的数正负相同
        slow = i;
        while(val * nums[slow] > 0) {
            int next = getnext(nums,slow,numsSize);//然后计算下一个位置，并且 nums[slow] 标记为0，并且慢指针移动到 next 位置。
            nums[slow] = 0;
            slow = next;
        }
    }
    //最终 for 循环退出后，返回 false 即可
    return false;
}


```
