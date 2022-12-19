```
public int NumSpecialEquivGroups(string[] A) {
        var dict=new Dictionary<string,int>();
        for(var i=0;i<A.Length;i++){
            var s=A[i];
            var t1=new List<char>();
            var t2=new List<char>();
            for(var j=0;j<s.Length;j++){
                if(j%2==0){
                    t1.Add(s[j]);
                }else{
                    t2.Add(s[j]);
                }
            }
            t1.Sort();
            t2.Sort();
            t1.AddRange(t2);
            var res=new string(t1.ToArray());
            dict[res]=0;
        }
        return dict.Keys.Count;
    }
```
