来自剑指offer书

考虑扩展性的解法，可以将指针替换操作定义为不同的函数（如快排中的比较大小）
本例的判断函数为tailCorrect和headCorrect

执行用时 : 4 ms  在所有 Java 提交中击败了 20.42% 的用户
惹，速度不是很快。期待交流。


```
class Solution {
    public int[] exchange(int[] nums) {
        if(nums.length==0) return nums;
        int head=0;
        int tail=nums.length-1;
        while(tail>head){ // 找到一个就换一个
            while(tail>head && tailCorrect(nums,tail))
                tail--;
            while(tail>head && headCorrect(nums,head))
                head++;
            if(tail>head){
                swap(head++, tail--, nums);
            }else break;
        }
        return nums;
    }

    public boolean tailCorrect(int[] nums, int tail){
        return nums[tail]%2==0;
    }
    
    public boolean headCorrect(int[] nums, int head){
        return nums[head]%2!=0;
    }
    public void swap(int i, int j, int[] n){
        int tmp = n[j];
        n[j] = n[i];
        n[i] = tmp;
    }
}
```
