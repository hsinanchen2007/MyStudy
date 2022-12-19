### 解题思路
从 0  0 状态开始
三种操作选择
若头相等 则 同时推进
若不等 则 三种操作 接着推进


### 代码

```csharp
using VT = System.ValueTuple<int, int>;
class EditW{
    //搜索所有状态空间
    //宽度搜索最快到达目标
    //Length > word2  
    //Length = word2 
    //最大公共子串 允许跳跃 
    //删除 + Replace + Add
    //部分公共子串

    private string W0,W1;
    public int total = 0;
    private Dictionary<VT, int> cache = new Dictionary<VT, int>();
    private int MD(int s0, int s1){ //两部分相等 最小操作
        total++;
        if(s0 >= W0.Length && s1 >= W1.Length) return 0;
        if(s0 >= W0.Length){//空对s1 Add
            return W1.Length - s1;
        }   
        if(s1 >= W1.Length){ //Remove All
            return W0.Length - s0;
        }
        var key = (s0, s1);
        if(cache.ContainsKey(key)) return cache[key];
        // var l0 = W0.Length - s0;
        // var l1 = W1.Length - s1;
        //相等则保留
        if(W0[s0] == W1[s1]){
            var md = MD(s0 + 1, s1 + 1);
            cache.Add(key, md);
            return md;
        }else {//不同则移除或者 Add 或者 Replace
            var m1 = MD(s0 + 1, s1 + 1)+1;//Replace 相等
            var m2 = MD(s0, s1 + 1)+1; //添加
            var m3 = MD(s0 + 1, s1)+1; //移除
            var md = Int32.MaxValue;
            md = Math.Min(md, m1);
            md = Math.Min(md, m2);
            md = Math.Min(md, m3);
            cache.Add(key, md);
            return md;
        }
    }
    public int MinDistance(string word1, string word2) {
        W0 = word1;
        W1 = word2;
        return MD(0, 0);
    }
}

public class Solution {
    public int MinDistance(string word1, string word2) {
        var md = new EditW();
        return md.MinDistance(word1, word2);
    }
}
```