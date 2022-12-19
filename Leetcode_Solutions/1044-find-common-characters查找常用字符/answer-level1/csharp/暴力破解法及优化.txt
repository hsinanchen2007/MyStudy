```c# []
public IList<string> CommonChars(string[] A) {
        var res=new int[A.Length,26];
        for(var i=0;i<A.Length;i++){
            var s=A[i];
            foreach(var c in s){
                res[i,c-'a']++;
            }
        }
        var list=new List<string>();
        for(var i=0;i<26;i++){
            var count=int.MaxValue;
            for(var j=0;j<A.Length;j++){
                if(res[j,i]<count){
                    count=res[j,i];
                }
            }
            if(count>0){
                while(count>0){
                    list.Add(((char)('a'+i)).ToString());
                    count--;
                }
            }
        }
        return list;
    }
```
优化一下
```
 public IList<string> CommonChars(string[] A)
        {
            var res = new int[26];
            for (var k = 0; k < 26; k++)
            {
                res[k] = int.MaxValue;
            }
            foreach (var s in A)
            {
                var t = new int[26];
                foreach (var c in s)
                {
                    t[c - 'a']++;
                }
                for (var k = 0; k < 26; k++)
                {
                    if (t[k] < res[k])
                    {
                        res[k] = t[k];
                    }
                }
            }
            var list = new List<string>();
            for (var k = 0; k < 26; k++)
            {
                if (res[k] < int.MaxValue)
                {
                    while (res[k] > 0)
                    {
                        list.Add(((char)('a' + k)).ToString());
                        res[k]--;
                    }
                }
            }
            return list;
        }
```

