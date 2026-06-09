运行结果：
执行用时 :2 ms, 在所有 Java 提交中击败了98.98% 的用户
内存消耗 :34.5 MB, 在所有 Java 提交中击败了88.32%的用户

大致思路：
k不断减小，减小到1的时候  数组的顺序就是要的结果
减小的过程是这样的：比如123456789，
当我们k=123时，k>5的阶乘120，我们把倒数第6个数字4 和后面第一个比他大的数字5交换位置得到123546789，这样我们就直接从最小的跳到第121个小的了，此时k=3；k>2的阶乘也就是2，我们把我们把倒数第3个数字7 和后面第一个比他大的数字8交换位置得到123546879，这样我们就直接从第121个的跳到第123个小的了，此时k=1；返回结果
谢谢大噶
代码如下：
```
    public String getPermutation(int n, int k) {
        int []factorial=new int[n+1];//存放阶乘
        int []nums=new int[n];//存放1-n个数字
        for (int i = 0; i <n; i++) {
            nums[i]=i+1;
        }
        factorial[0]=1;
        for (int i = 1; i < n+1; i++) {//把1到9 的阶乘先全都算出来
            factorial[i]=i*factorial[i-1];
        }
        StringBuilder sb=new StringBuilder();//用来保存结果的
        if (k==factorial[n]){//这是一个特殊情况 后面的while循环没法处理  所以单独拎出来了
            for (int i = n-1; i >=0 ; i--) {
                sb.append(nums[i]);
            }
            return sb.toString();
        }
        int n2=n-1;
        while (k>1){
            if (k>factorial[n2]){
                k-=factorial[n2];
                int tmp=nums[n-1-n2];//要进行交换的位置
                for (int i = n-n2; i <n ; i++) {//找到第一个比当前位置的的
                    if (nums[i]>tmp){//交换
                        nums[n-1-n2]=nums[i];
                        nums[i]=tmp;
                        break;
                    }
                }
            }
            if (k<=factorial[n2])n2--;
        }
        for (int i = 0; i <n ; i++) {
            sb.append(nums[i]);
        }
        return sb.toString();
    }
}
```
