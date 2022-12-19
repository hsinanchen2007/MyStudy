
根据题意可得，对于每个索引就两种选择，交换或者不交换（需要检查合法性）。
用递归来写，加上记忆化就可以了。
代码如下，详情请看代码和注释。
```
    public int minSwap(int[] A, int[] B) {
        int[][] book=new int[A.length][2];
        for (int[] b:book)
        {
            Arrays.fill(b,-1);
        }
        return Math.min(1+slove(1,A,B,book,1),slove(1,A,B,book,0));
    }

    // flag=1为上次idx-1交换了位置，flag=0为上次idx-1没有交换位置
    // idx为此时的索引
    // book[idx][flag]为在flag状态下且idx索引以前都是递增，把idx（包括idx）之后的变为递增需要的最小次数
    private int slove(int idx, int[] a, int[] b, int[][] book,int flag) {
        if(idx==b.length) return 0;
        if(book[idx][flag]!=-1)return book[idx][flag];//记忆化
        int res=Integer.MAX_VALUE;
        //检查在不交换的前提下是否满足递增
        if((flag==0&&a[idx]>a[idx-1]&&b[idx]>b[idx-1])||(flag==1&&a[idx]>b[idx-1]&&b[idx]>a[idx-1]))
        {
            res=slove(idx+1,a,b,book,0);
        }
        //检查能否交换位置
        if((flag==0&&b[idx]>a[idx-1]&&a[idx]>b[idx-1])||(flag==1&&a[idx]>a[idx-1]&&b[idx]>b[idx-1]))
        {
           res=Math.min(res,1+slove(idx+1,a,b,book,1));
        }
        return book[idx][flag]=res;//记忆化
    }
```
