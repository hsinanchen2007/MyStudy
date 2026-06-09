![回溯216.PNG](https://pic.leetcode-cn.com/e0986114eec69a1e2dec86adfdb816d04598abf871ff23a997f31c4a6e333a4b-%E5%9B%9E%E6%BA%AF216.PNG)

### 解题思路
回溯的细节需要注意一下:
    1.backtrack(start+1,...)是因为结果集元素互不相同，下一层的搜索起点start+1即可
    2.剪枝的部分,比如说n=7,k=2的时候不需要[1,2,4]这样的由3个数组成的结果,每层递归我们可以让k-1,当k<0的时候就提前退出
    3.n<start,start是这一层递归的搜索起点,表示这一层的搜索区间为[start,9]或者[start,n]，n 表示减剩下的值(n<9才行)
    如果剩余值n都比搜索起点start还小,那就没有更小的值可减了，提前结束

### 代码

```java
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        //组合中只允许含有1~9的数字,这题和40题的不同,这里是不会有重复数字的,40题是一个有重复数字的数组,所以要避免重复数字   
        
        List<List<Integer>> res=new ArrayList<List<Integer>>();
        backtrack(1,k,n,new ArrayDeque(),res);
        return res;
    }

    //int start是因为结果集里的元素互不相同，因此下一层搜索的起点应该是上一层搜索的起点值 + 1
    //n-nums[i]来作为减完之后剩下的值
    private void backtrack(int start,int k,int n,Deque<Integer> path,List<List<Integer>> res){
        if(n==0&&k==0){
            //n减到0的时候且k==0(表示由k个数来把n减为0)
            res.add(new ArrayList<Integer>(path));
            return;
        }
        if(k<0||n<start){
            //剪枝,有时候n=7,k=2就不需要[1,2,4]这样由3个数组合的结果了,提前结束省时间
            /*
                n<start说两句:
                                7   i=start=1(递归顶层),下一层搜索的起点start+1
                               /(-2)    for(i=2,i++) n-i=5(剩余的值)  下层搜索起点start+1=3    
                              5     for(i=start=3,...) n-i=5-3=2(剩余的值) 下层搜索起点start+1=4
                             /(-3) 
                            2     这条递归链path在n减至n=2的时候，搜索的起点start=4,不可能继续搜索了,提前结束
            */    
            return;
        }

        for(int i=start;i<=n&&i<=9;i++){//n=18,会爆炸的,要求在[1,9]中搜索
            //i<=n,比如说,n=7 ,在i=1时候 n-1=6,下一层搜索的时候只需要在[1,6]的区间搜索即可
            if(i<=n){
                //有机会能减为0
                path.addLast(i);
                backtrack(i+1,k-1,n-i,path,res);//i+1为了防止重复,下一层递归搜索起点start+1
                path.removeLast();
            }
        }
    }
}
```