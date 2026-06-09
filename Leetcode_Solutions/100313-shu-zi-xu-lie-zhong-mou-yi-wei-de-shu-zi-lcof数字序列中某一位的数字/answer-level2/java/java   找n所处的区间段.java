![屏幕快照 2020-02-28 下午3.36.50.png](https://pic.leetcode-cn.com/f040ffb2704e05e0323c3bb10bc1614519b8602da29659bc2ecfcb4fd2e170c3-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-28%20%E4%B8%8B%E5%8D%883.36.50.png)

1.先找出n所处的区间段，0-9，10-99，100-999.。。。。。
2.求出n所在的那个数具体是多少：
  （1）如果是某个数字的个位数字，直接mod10就好了
   (2) 如果不是各位数字，先用digits-rest求出这个数字还有多少位（假设后面还有m位），除以10^m后，再mod10即可

**注意！要用long保存数据，否则10^10不能通过**

```
    public int findNthDigit(int n) {
        long num=n;
        int ans=0;
        if(num==0) return ans;
        long digits=1; //n所在的位数
        long i=1;//当前位数
        while(num>digits*(9*i)){
            num=num-digits*(9*i);  //i:位数  9*i: 该位数的数字有多少个
            digits++;
            i=i*10;
        }
        long count=num/digits;
        long rest=num%digits;

        if(rest==0){  //某个数字的末位
            ans=(int)(((long)Math.pow(10,digits-1)+count-1)%10);
        }else{
            long number=(long)Math.pow(10,digits-1)+count; //先找到这个数字
            ans=(int)(number/(long)Math.pow(10,digits-rest))%10;
        }
        return ans;

    }
```
