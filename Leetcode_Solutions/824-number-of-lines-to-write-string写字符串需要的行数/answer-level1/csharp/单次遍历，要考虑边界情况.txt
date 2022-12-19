执行用时 :356 ms, 在所有 C# 提交中击败了100.00%的用户
内存消耗 :28.8 MB, 在所有 C# 提交中击败了22.22%的用户
```c# []
public int[] NumberOfLines(int[] widths, string S) {
        var len=0;
        var line=1;
        foreach(var c in S){
            var k=widths[c-'a'];
            var t=len+k;
            if(t>100&&t-100<k){
                line++;
                len=k;
            }else if(t==100){
                line++;
                len=0;
            }else{
                len=t;
            }
        }
        var res=new int[2];
        res[0]=line;
        res[1]=len;
        return res;
    }
```

