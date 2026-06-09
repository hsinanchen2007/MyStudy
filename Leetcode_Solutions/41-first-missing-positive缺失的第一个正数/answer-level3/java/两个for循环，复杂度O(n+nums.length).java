思路：返回最小整数的最小值为1，最大值为（数组长度+1）（例如：[1,2,3,4,5]就返回6）
于是创建一个长度为nums.length的新数组，存储数字nums[i](1<=nums[i]<=数组长度)出现的次数，其余数字则不管。
代码如下：
```
    public int firstMissingPositive(int[] nums) {
        int[] res = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            if(1<=nums[i]&&nums[i]<=nums.length){
                res[nums[i]-1]++; //注意res[0]存的是数字1出现的次数
            }
        }
        for(int i=0;i<res.length;i++){
            if(res[i]==0) 
                return i+1; // 理由同上一个注释,例如nums[3]=0表示4出现了零次
                            // 因为前面比4小的都出现了至 少一次（否则早return了），所以返回4
        }
        return res.length+1; //最后代表[1,数组长度]之间的数都至少出现了一次，所以最小数为长度+1
    }
```
