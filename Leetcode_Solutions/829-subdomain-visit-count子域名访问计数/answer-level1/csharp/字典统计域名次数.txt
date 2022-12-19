
执行用时 :
404 ms, 在所有 C# 提交中击败了100.00%的用户
内存消耗 :
31.6 MB, 在所有 C# 提交中击败了20.00%的用户

```javascript []
public IList<string> SubdomainVisits(string[] cpdomains) {
        var dict=new Dictionary<string,int>();
        foreach(var s in cpdomains){
            var t=s.Split(' ');
            var count=int.Parse(t[0]);
            var ps=t[1].Split('.');
            string domain=string.Empty;
            for(var i=ps.Length-1;i>=0;i--){
                if(i!=ps.Length-1){
                    domain='.'+domain;
                }
                domain=ps[i]+domain;
                
                if(!dict.ContainsKey(domain)){
                    dict[domain]=count;
                }else{
                    dict[domain]+=count;
                }
            }
        }
        var R=new List<string>();
        foreach(var kv in dict){
            R.Add($"{kv.Value} {kv.Key}");
        }
        return R;
    }
```

