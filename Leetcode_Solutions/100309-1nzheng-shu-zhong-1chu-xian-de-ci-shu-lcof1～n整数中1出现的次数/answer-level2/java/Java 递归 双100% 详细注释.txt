
```
class Solution {
    //nums[i]= 1 到 10^i-1之间1的数量,比如i=2,，nums[i]就存着1~99中1的数量
    int[] nums;
    //pows[i]=Math.pow(10,i)
    int[] pows;
    //计算n的位数,countDigit(1000)=4 (112)=3 (2)=1
    private int countDigit(int n){
        int res=0;
        while(n!=0){
            res++;
            n/=10;
        }
        return res;
    }
    //通过这个函数，递归求取答案
    private int getResult(int n){
        if(n==0)
            return 0;
        if(n<10)
            return 1;
        //获取n的位数
        int cd=countDigit(n);
        int res=0;
        //求解算法分为两步：
        //举个例子 n=3112，先求1~3000一的数量，再求1~112一的数量
        
        //第一步：
        //nums[cd-1]存放着1到10^cd之间1的数量
        //n/pows[cd-1]提取最高位数字
        //下述式子含义，比如n=3112,有3个（1~999中1的数量）
        //也就是说0~999,1000~1999,2000~2999这3个区间不考虑最高位1的数量
        res+=nums[cd-1]*(n/pows[cd-1]);
        //上式忽略了最高位，下面这个if语句就是用来处理最高位的1
        //最高位大于大于2，比如，n=3112的话，1000~1999还有有额外1000个1
        if(n>=2*pows[cd-1])
            res+=pows[cd-1];
        else
        //反之，最高位等于1，比如,n=1314的话,1000~1314有额外315个1
            res+=n-pows[cd-1]+1;
        //第二步：
        //上面的结果加上加上1~112中1的数量
        return res+getResult(n-n/pows[cd-1]*pows[cd-1]);
    }
    public int countDigitOne(int n) {
        int cd=countDigit(n);
        pows=new int[cd+1];
        pows[0]=1;
        for(int i=1;i<cd;i++)
            pows[i]=pows[i-1]*10;
        nums=new int[cd+2];
        nums[1]=1;
        for(int i=2;i<nums.length;i++)
            nums[i]=nums[i-1]*10+pows[i-1];
        return getResult(n);
    }
}
```
