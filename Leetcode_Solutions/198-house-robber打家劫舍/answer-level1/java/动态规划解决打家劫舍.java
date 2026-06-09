动态规划问题，不过是把递归问题，转化为数组存储每一步结果的问题。减少时间复杂度的问题
```java
class Solution {
    public static int rob(int[] a){
        int len=a.length;
        if(len==0)
            return 0;
        int[] db=new int[a.length];
        db[0]=a[0];
        if(len==1)
            return a[0];
        db[1]=Math.max(a[0],a[1]);
        if(len==2)
            return db[1];
        db[2]=Math.max(a[2]+a[0],a[1]);
        for(int i=3;i<a.length;i++){
            int max1=Math.max(db[i-1],a[i]+db[i-2]);
            db[i]=Math.max(max1,a[i]+db[i-3]);
        }
        return db[a.length-1];
    }
}
```