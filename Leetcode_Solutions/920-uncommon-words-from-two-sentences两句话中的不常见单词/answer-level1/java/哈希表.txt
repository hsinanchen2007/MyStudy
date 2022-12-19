执行用时 :5 ms, 在所有 Java 提交中击败了94.03%的用户
内存消耗 :36.2 MB, 在所有 Java 提交中击败了89.24%的用户
两个句子均放在哈希表里，分别比较一次。
```
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        String []a=A.split(" ");
        String []b=B.split(" ");
        List<String>list=new ArrayList();
        HashMap<String,Integer>aa=new HashMap<String,Integer>();
        HashMap<String,Integer>bb=new HashMap<String,Integer>();
        for(int i=0;i<a.length;i++)
        {
            aa.put(a[i],aa.getOrDefault(a[i],0)+1);
        }
        for(int i=0;i<b.length;i++)
        {
            bb.put(b[i],bb.getOrDefault(b[i],0)+1);
        }
        for(int i=0;i<a.length;i++)
        {
            if(aa.get(a[i])==1&&(!bb.containsKey(a[i])))
                list.add(a[i]);
        }
        for(int j=0;j<b.length;j++)
        {
            if(bb.get(b[j])==1&&(!aa.containsKey(b[j])))
                list.add(b[j]);
        }
        return list.toArray(new String[list.size()]);
    }
}
```
