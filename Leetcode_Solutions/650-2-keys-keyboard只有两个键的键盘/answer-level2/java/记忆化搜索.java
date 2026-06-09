# 解题思路
为什么我一直坚持先写记忆化递归呢？这对我来说算是兜底的存在了吧，优雅之前得先找出个答案吧。

1.每次递归都有2个选择，copyAll or Paste，但是copy==0，即剪贴板没有一个 'A' 时，得先copyAll

2.如果copy>0，剪贴板里面有 'A' 的时候，可以继续copyAll，但是**一直copy会导致溢出**，所以需要**让它及时停止**：`if copyRecord==n`，这里**copyRecord是累计的copyAll的次数**

3.当然，剪贴板有 'A' 的时候，也可以paste，但是**paste有条件：保证paste粘贴之后 'A' 的个数不大于n**，转变成代码表达就是：`count+copy<=n`，其中，count是累计的 'A' 的个数，copy是当前剪贴板里面 'A' 的个数。

# 记忆化递归代码
```
    int n;
    int[][] memo;//memo[i][j],i是当前'A'的个数,j是当前剪贴板copy中的容量
    public int minSteps(int n) {
        this.n=n;
        memo=new int[n+1][n+1];
        return recursion(1,0,0);
    }
    
    //count:当前积累的'A'个数
    //copy:剪贴板上'A'的个数,初始为0
    //copyRecord:累计copy的次数,总不能一直copy的
    private int recursion(int count,int copy,int copyRecord){
        if(count==n||copyRecord==n){//有一个分支是一直在copy的，没有paste不行
            return 0;
        }
        if(memo[count][copy]>0){
            return memo[count][copy];
        }
        int ans=n+1;//打印3个A,步骤最多也是copy一次，打印n=3次，这里随意了，比 n 大就行
        if(copy==0){
            //没有就先copyAll,copyAll算一步+1
            ans=Math.min(ans,1+recursion(count,count,copyRecord+1));

        }else if(count+copy<=n){//如果粘贴paste之后'A'的总数超过n,是不允许的

            //剪贴板有内容的时候可以选择copyAll,或者paste
            ans=Math.min(ans,Math.min(1+recursion(count+copy,copy,copyRecord),1+recursion(count,count,copyRecord+1)));
        }
        memo[count][copy]=ans;
        return ans;
    }
```

