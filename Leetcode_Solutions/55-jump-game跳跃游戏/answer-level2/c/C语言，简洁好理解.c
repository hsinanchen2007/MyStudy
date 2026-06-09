
从后往前找点
![QQ图片20200309221118.png](https://pic.leetcode-cn.com/9de5e227c4925072f93138a61465e7258070b90e7072df94729a94cc62118370-QQ%E5%9B%BE%E7%89%8720200309221118.png)


    bool canJump(int* nums, int numsSize){
    int i,tmp;
    
    for(i=numsSize-2,tmp=numsSize-1;i>=0;i--){
        if(nums[i]>=(tmp-i)){          //如果i点能够跳到tmp，令i为tmp
            tmp=i;
        }
    }

    if(tmp==0) return 1;
    else return 0;
    }