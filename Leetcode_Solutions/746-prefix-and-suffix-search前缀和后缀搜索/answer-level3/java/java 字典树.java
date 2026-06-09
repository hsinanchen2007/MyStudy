执行用时 :354 ms, 在所有 Java 提交中击败了88.89%的用户
内存消耗 :70.1 MB, 在所有 Java 提交中击败了96.67%的用户
+ 前缀一个字典树，后缀一个字典树
+ 建树前先预处理重复单词

代码如下
```
 class WordFilter {
    public WordFilter(String[] words) {
        pre=new Node();
        suff=new Node();
        Map<String,Integer> map=new HashMap<>();
        for (int i=0;i<words.length;i++)
        {
            map.put(words[i],i);
        }
        for (Map.Entry<String,Integer> e:map.entrySet())
        {
            String s=e.getKey();
            bulidTree(pre,s.toCharArray(),0,e.getValue());
            bulidTree(suff,new StringBuilder(s).reverse().toString().toCharArray(),0,e.getValue());
        }
    }

    public int f(String prefix, String suffix) {
        List<Integer> pre=serach(prefix.toCharArray(), 0, this.pre);
        List<Integer> suff=serach(new StringBuilder(suffix).reverse().toString().toCharArray(), 0, this.suff);
        Set<Integer> set=new HashSet<>();
        set.addAll(pre);
        int res=-1;
        for (int i:suff)
        {
            if(!set.contains(i))continue;
            res=Math.max(res,i);
        }
        return res;
    }
        
    private List<Integer> serach(char[] strs,int i,Node root)
    {
        if(strs.length==i)return root.idxs;
        Node next=root.nexts[strs[i]-'a'];
        if(next==null)return new ArrayList<>();
        return serach(strs,i+1,next);
    }
        
    private Node pre;
    private Node suff;
        
    class Node
    {
        List<Integer> idxs;
        Node[] nexts;
        Node()
        {
            nexts=new Node[26];
            idxs=new ArrayList<>();
        }
    }
    private void bulidTree(Node root,char[] strs,int i,final int idx)
    {
        root.idxs.add(idx);
        if(i==strs.length)return;
        if(root.nexts[strs[i]-'a']==null)root.nexts[strs[i]-'a']=new Node();
        bulidTree(root.nexts[strs[i]-'a'],strs,i+1,idx);
    }
}
```
