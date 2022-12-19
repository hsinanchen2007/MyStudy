通过字典树进行匹配，先按顺序建立树再按逆序建立树，因为domino序列用了两次，所以是最终答案的两倍。
但这里会出现特殊情况，domino是回文序列的时候用非回文序列的算法算会有更多重复，所以分开讨论，设立两个变量计算这两种情况的domino对数。


```
class Solution {
    class Trie{
        Trie[] next=new Trie[10];
        int num=0;
    }
    Trie root;
    int res=0;//记录非回文domino答案
    int dup=0;//记录回文domino答案
    private void build(int[] domino){
        Trie cur=root;//顺序建立字典树
        for(int i=0;i<domino.length;i++){
            if(cur.next[domino[i]]==null)
                cur.next[domino[i]]=new Trie();
            cur=cur.next[domino[i]];
        }
        
        //以下7行代码用于判断domino是否回文
        int t;
        for(t=0;t<domino.length/2&&domino[t]==domino[domino.length-1-t];t++);
        if(t==domino.length/2){
            dup+=cur.num;
            cur.num++;
           return; 
        }
            
        if(cur.num>0)
            res+=cur.num;
        cur.num++;

        cur=root;//逆序建立字典树
        for(int i=domino.length-1;i>=0;i--){
            if(cur.next[domino[i]]==null)
                cur.next[domino[i]]=new Trie();
            cur=cur.next[domino[i]];
        }
        if(cur.num>0)
            res+=cur.num;
        cur.num++;
    }
    public int numEquivDominoPairs(int[][] dominoes) {
        root=new Trie();
        for(int i=0;i<dominoes.length;i++){
            build(dominoes[i]);
        }
        return res/2+dup;
    }
}
```
