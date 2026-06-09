贪心策略很简单，从0开始每次跳[当前能跳距离]+[下次能跳距离]总和最大的点，如果判定本次跳到了数组最后则直接输出跳跃次数。
空间复杂度o(1)，时间复杂度o(n);
```
public int jump(int[] nums) {
        int len=nums.length-1;
        int start=0;
        int nxt=-1;
        int count=0;
        while(start<len){
            int max=-1;
            for(int i=start;i<=start+nums[start];i++){
                if(i==len){
                    return ++count;
                }
                if(i+nums[i]>=max){
                    max=i+nums[i];
                    nxt=i;
                }
            }
            start=nxt;
            count++;
        }
        return count;
    }
```
