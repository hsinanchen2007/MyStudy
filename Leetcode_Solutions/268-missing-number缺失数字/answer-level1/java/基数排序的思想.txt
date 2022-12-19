# 基数排序的思想
新建一个数组b,用于统计每个数出现的次数
```
 public int missingNumber(int[] nums) {
       int[] b=new int[nums.length+1];
        for(int i=0;i<nums.length;i++){
            b[nums[i]]=1;
        }
        int res=0;
        for(int i=0;i<b.length;i++){
            if(b[i]!=1){
                res=i;
                break;
            }
        }
        return res;
    }
```
![image.png](https://pic.leetcode-cn.com/f163bb6927b110f89554d00134773a07bbb7b960f85f8b4932ed56bdeafc11a4-image.png)
