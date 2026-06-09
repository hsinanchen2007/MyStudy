### 解题思路
最优结果是每个子串只有1个不同字符 其余字符公用
最差结果 n* k^n 长度
避免相同的子串重复
每个子串的Hash值 和前缀相关

### 代码

```csharp
class NPass{
    //k ^ n
    // 1 2 3 4 5 6 7 8 9 ... n
    public int totalNum = 0;
    private string MinLen(int n, int k)
    {
        if (k == 1)
        { //0000
            // return n;
            var sb1 = new StringBuilder();
            for (var i = 0; i < n; i++){
                sb1.Append(0);
            }
            return sb1.ToString();
        }
        if (n == 1)
        {//0 1 2 ~k-1
            // return k;
            var sb1 = new StringBuilder();
            for (var i = 0; i < k; i++){
                sb1.Append(i);
            }
            return sb1.ToString();
        }
        //K^N 00 
        //总长度 00 01 10 11  K^n 组合 * n 每个长度N
        
        var kV = 1;
        for (var i = 0; i < n; i++)
        {
            kV *= k;
        }
        //最差的情况下的长度 
        var totalLen = kV * n;
        var curMinLen = totalLen;
        var maxSmall = kV+n-1;

        var off = 1;
        for (var i = 0; i < n-1; i++){
            off *= 10;
        }
        // Console.WriteLine("KV:" + kV + ":" + totalLen+":"+off);
        //寻找所有可能中 最小的配置
        //K进制 N位  10000 * 4
        var stack = new List<int>();
        stack.Add(-1);
        var passValue = new List<int>();//0~当前 -n N个之前的元素N位数和 类似于字符串
        passValue.Add(-1);
        //1234 5678
        //1 12 123 1234  pre*10+now
        //当前堆栈中拥有的密码
        var matchPass = new Dictionary<int, int>();
        var lsRet = new List<int>();
        while (stack.Count > 0)
        {
            totalNum++;
            var top = stack[stack.Count - 1];
            var last = stack.Count - 1;
            // //Console.WriteLine("Print:\n"+top+":\n\n"+ObjectDumper.Dump(stack)+":\n" + ObjectDumper.Dump(matchPass)+":Pass:\n\n"+ObjectDumper.Dump(passValue));
            //少一个字符是否可以OK
            if (top < k - 1 && stack.Count < curMinLen) //过长没意义了
            {
                var pv1 = passValue[last];
                if(stack.Count >= n && pv1 != -1){
                    matchPass[pv1]--;
                    if(matchPass[pv1] == 0) matchPass.Remove(pv1);
                }
                stack[last]++;
                if (last > 0)
                {
                    if(last >= n){//移除第一个
                        passValue[last] = (passValue[last - 1] - stack[last-n]*off )* 10 + stack[last];
                    }else
                    {
                        passValue[last] = passValue[last - 1] * 10 + stack[last];
                    }
                }
                else
                {
                    passValue[last] = stack[last];
                }
                // if(!matchPass.ContainsKey(passValue[last])) matchPass[passValue[last]]=0
                if (stack.Count >= n)
                {
                    matchPass.TryAdd(passValue[last], 0);
                    matchPass[passValue[last]]++;
                    var lv = passValue[last];
                    //不要重复N次 
                    if(matchPass[lv] > 1){
                        continue;
                    }
                }
                if (matchPass.Count == kV)
                {
                    //Console.WriteLine("MatchPass:" +ObjectDumper.Dump(matchPass));
                    lsRet.Clear();
                    lsRet.AddRange(stack);
                    if(stack.Count == maxSmall) break;//最小长度达成 每个子串只有1个不同
                    curMinLen = Math.Min(curMinLen, stack.Count);
                    var pv = passValue[last];
                    matchPass[pv]--;
                    if (matchPass[pv] == 0) matchPass.Remove(pv);
                    passValue.RemoveAt(last);
                    stack.RemoveAt(last);
                }
                else
                {
                    //剪枝
                    // var eachLen = stack.Count / (matchPass.Count + 1); 
                    // if(eachLen > n) continue;//单个重复太多了 每个长度N*Count = totalLen
                    stack.Add(-1);
                    passValue.Add(-1);
                }
            }else {//超过了只能移除
                var pv = passValue[last];
                if (pv != -1 && stack.Count >= n)
                {
                    matchPass[pv]--;
                    if(matchPass[pv] == 0) matchPass.Remove(pv);
                }
                passValue.RemoveAt(last);
                stack.RemoveAt(last);
            }

        }

        var sb = new StringBuilder();
        foreach(var r in lsRet) sb.Append(r);
        return sb.ToString();
    }
    public string CrackSafe(int n, int k) {
        return MinLen(n, k);
    }
    // static void Main(string[] arg)
    // {
    //     var s = new NPass();
    //     var r = s.CrackSafe(2, 4);
    //     Console.WriteLine(r+":"+s.totalNum);
    // }
}

public class Solution {
    public string CrackSafe(int n, int k) {
        var np = new NPass();
        return np.CrackSafe(n, k);
    }
}
```