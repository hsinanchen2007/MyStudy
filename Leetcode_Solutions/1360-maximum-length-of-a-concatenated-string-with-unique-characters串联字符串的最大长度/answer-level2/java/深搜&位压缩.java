    解决问题第一思路可以想到回溯，优化即不一一比较可以使用位压缩的方法
在使用位压缩的思路在于把每个字母，例如abc，转化为111，ac转化为101这样的形式，检验是否有重复字母利用&操作，获得合并字符串用|操作，具体如代码所示。
还想要更快的话，将每个字符串有多少种不同的字符存下来，存在例如我代码里的in数组里，同时把有相同字符的字符串用-1标记，等到搜索时直接跳过，等到要用时直接读取即可。
这样写的时间效率直接超过了100%的java代码。
```
class Solution {
    public int n;
    public int ans=0;
    public int maxLength(List<String> arr) {
        int[] narr=new int[arr.size()];
        int[] in=new int[arr.size()];
        n=arr.size();
        for(int i=0;i<n;i++){
            char[] chs=arr.get(i).toCharArray();
            for(char ch:chs){
                int num=1<<(int)(ch-'a');
                if((num&narr[i])!=0){
                    narr[i]=-1;
                    break;
                }else{
                    narr[i]|=num;
                    in[i]++;
                }
            }
        }
        dfs(0,narr,in,0,0);
        return ans;
    }
    public void dfs(int p,int[] narr,int[] in,int num,int a){
        ans=Math.max(num,ans);
        if(p==n)
            return;
        for(int i=p;i<n;i++)
            if(narr[i]!=-1&&(a&narr[i])==0)
                dfs(i+1,narr,in,num+in[i],a|narr[i]);
    }
}
```
