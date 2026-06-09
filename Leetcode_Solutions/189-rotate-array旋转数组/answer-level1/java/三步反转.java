```
class Solution {
    public void reverse(int[] num,int from, int to)//简单的翻转函数，从头到尾的那种
    {
        while(from < to)
        {
            int temp = num[from];
            num[from++] = num[to];
            num[to--] = temp;
        }
    }
    public void rotate(int[] nums, int k) {
        int lastIndex = nums.length-1 ;
        k %= nums.length;
        reverse(nums,lastIndex - k + 1,lastIndex);//子串1
        reverse(nums,0,lastIndex - k);//子串2
        reverse(nums,0,lastIndex);//全体
    }
}
```
