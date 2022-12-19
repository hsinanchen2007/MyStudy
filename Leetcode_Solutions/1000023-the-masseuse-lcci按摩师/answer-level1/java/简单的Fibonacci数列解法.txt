```java
//类似斐波那契数列， 设0~i个请求的最大只是 f(i),  那么 f(i)=max(f(i-1), f(i-2)+nums[i]);
    public int massage(int[] nums) {
        int n=nums.length;
        if(n==0) return 0;
        if(n==1) return nums[0];
        int a=nums[0],b=Math.max(nums[0],nums[1]),c=b;
        for(int i=2; i<n; i++){
            c=Math.max(b,a+nums[i]);
            a=b;
            b=c;
        }
        return c;
    }
```
