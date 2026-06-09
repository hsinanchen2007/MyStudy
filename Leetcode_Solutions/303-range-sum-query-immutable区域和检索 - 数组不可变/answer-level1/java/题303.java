### 解题思路
此处撰写解题思路
开始真没看懂题目...想着不是一个循环的事情吗，但是经过朋友提醒说是多次调用方法sumRange，意思是给你一个nums[100]，然后给你多组i j  比如求和1--100的   1--50的   2---10   50--60的
我算是取巧了  毕竟是动态规划的题目  就直接用一个数组a[nums.length]存起了0--j的和
那就简单了  然后i--j的和不就是   a[j]-a[i-1]嘛 
a[j]是0到j   a[i]是0到i   a[j]-a[i-1]就是i到j
### 代码

```java
class NumArray {
    int sum=0;
    int[] a;//这个数组存的是a[i]前的和
    public NumArray(int[] nums) {
        
        a=new int[nums.length];
        for (int i=0;i<a.length;i++){
            sum+=nums[i];
            a[i]=sum;
        }

    }
    
    public int sumRange(int i, int j) {
            if (i==0){
                return a[j];
            }
            else{
                return a[j]-a[i-1];
            }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```