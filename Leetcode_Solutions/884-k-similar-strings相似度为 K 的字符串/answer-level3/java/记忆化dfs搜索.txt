由提示信息：
+ 1 <= A.length == B.length <= 20
+ A 和 B 只包含集合 {'a', 'b', 'c', 'd', 'e', 'f'} 中的小写字母。

带来的灵感。

只有6个字母，所以可以用3位二进制存储当前索引所有情况，长度最长位20，所以最多需要60个二进制位来存储当前序列也就是long变量就可以满足需求。
只需要利用这个long变量对dfs搜索进行记忆化即可。

执行用时 124ms 超越76.74%
内存 53.8Mb 超越66。67%
代码如下
```
class Solution {
    public int kSimilarity(String A, String B) {
        char[] a=A.toCharArray();
        char[] b=B.toCharArray();
        final long tar=getKey(b);
        final long start=getKey(a);
        return slove(0,start,tar,a,b,new HashMap<>());
    }

    private int slove(int idx, long cur, final long tar, final char[] a, final char[] b, final Map<Long, Integer> map) {
        if(cur==tar)return 0;
        if(idx==a.length)return Integer.MAX_VALUE>>1;
        if(map.containsKey(cur))return map.get(cur);
        int res=Integer.MAX_VALUE>>1;
        if(a[idx]==b[idx]) res=slove(idx+1,cur,tar,a,b,map);
        else
        {
            for (int i=idx+1;i<a.length;i++)
            {
                if(a[i]==b[idx]&&a[idx]!=b[idx])
                {
                    long next=help(cur, a, idx, i);
                    res=Math.min(res,1+slove(idx+1,next,tar,a,b,map));
                    swap(a,idx,i);
                }
            }
        }
        map.put(cur,res);
        return res;
    }

    private long getKey(long start, int idx, char c, int length) {
        long res=0;
        int len=(length-idx-1)*3;
        res|=(c-'a');
        res<<=len;
        long r=start<<(64-len)>>>(64-len);
        if(idx==length-1)r=0l;
        long l=start>>(len+3)<<(len+3);
        res|=r;
        res|=l;
        return res;
    }

    private long help(long start, char[] a, int idx, int j) {
        long res=getKey(start,idx,a[j],a.length);
        res=getKey(res,j,a[idx],a.length);
        swap(a, idx, j);
        return res;
    }

    private void swap(char[] a, int idx, int j) {
        char c=a[idx];
        a[idx]=a[j];
        a[j]=c;
    }

    private long getKey(char[] s) {
        long res=0;
        for (int i=0;i<s.length;i++)
        {
            res|=(s[i]-'a');
            res<<=3;
        }
        res>>>=3;
        return res;
    }
}
```
