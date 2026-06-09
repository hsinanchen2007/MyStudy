如果这个数组中没有数字0 肯定没问题，所以需要考虑数字0 的情况，
1.先把数字0在第一个位置的情况处理了
   A.如果只有一个数字， 直接返回true
   B.如果不止一个数字，直接返回false
2.首位非0的场景  
   循环每一位，记录当前能到达的最远Pos 记录下来maxStep，每循环一次判断一次，记录最远的位置maxStep
   如果当前位置为0， 判断最远的位置 是不是 能把 0 这个位置超越，不能超越直接false  能超越继续往前
   如果maxStep己经大于数组大小，直接返回true;;


```
bool canJump(int* nums, int numsSize){
    int i = 0;
    int j = 0;
    int flag = true;
    int maxStep = 0;
    /*[2 0 0 ] [ 超给多的数]*/
    if (nums[0] == 0 && numsSize == 1){
        printf("******value =%d  numsSize =%d********\n",nums[0], numsSize);
        return true;
    }
    if (nums[0] == 0 && numsSize != 1){
        printf("******value =%d  numsSize =%d********\n",nums[0], numsSize);
        return false;
    }

    for (i = 1; i <= numsSize; i++)  {
        if (nums[i-1] == 0){
            if (maxStep <= i){
                flag = false;
                break;
            }
        }

        if (maxStep < (i + nums[i-1])){
            maxStep = i + nums[i-1];
        }

        if (maxStep >= numsSize){
            flag = true;
            break;
        }
    }

    return flag;
  
}

```




![1.png](https://pic.leetcode-cn.com/2c27da324e64b6e0106bada2eee10c0c1beec4336004b637e563d03ea8047e8c-1.png)
