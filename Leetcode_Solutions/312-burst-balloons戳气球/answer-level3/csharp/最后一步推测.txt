### 解题思路
每次最后一步 必然左右两侧都被消除完
假设某个元素为 最后一步，计算左右两侧消除完 最大和
总的最大和 = Mid * left * right + 左侧最大和 + 右侧最大和

递归推测 左右两侧的最后一步

### 代码

```csharp


using VT = System.ValueTuple<int, int, int, int>;
class Baloon2{
    //left mid right
    //mid 消耗完为1 左右各自相交
    private int[] nmm;
    private Dictionary<VT, int> cache = new Dictionary<VT, int>();
    public int total = 0;
    private int MaxSum(int s, int e, int left, int right){
        total++;
        if(s > e) return 0;//没有元素
        if(s == e) return nmm[s] * left * right; //消除中间元素
        var key = (s, e, left, right);
        if(cache.ContainsKey(key)) return cache[key];

        var ms = 0;
        for (var i = s; i <= e; i++){
            var sv = nmm[i];
            var lv = MaxSum(s, i - 1, left, sv);
            var rv = MaxSum(i + 1, e, sv, right);
            // sv += lv + rv;
            var mv = lv + rv + sv * left * right;
            ms = Math.Max(ms, mv);
        }
        cache.Add(key, ms);
        return ms;
    }
    public int MaxCoins(int[] nums)
    {
        nmm = nums;
        var m = 0;
        for (var i = 0; i < nums.Length; i++){
            var sv = nums[i];
            //左右都是1 消除只剩下自己了
            var lv = MaxSum(0, i - 1, 1, sv);
            var rv = MaxSum(i + 1, nums.Length - 1, sv, 1);
            var mv = lv + rv + sv*1*1;
            m = Math.Max(mv, m);
        }
        return m;
    }
}

public class Solution {
    public int MaxCoins(int[] nums) {
        var ba = new Baloon2();
        return ba.MaxCoins(nums);
    }
}
```