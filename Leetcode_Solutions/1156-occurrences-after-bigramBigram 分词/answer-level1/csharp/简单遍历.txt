注意边界处理
```
 public string[] FindOcurrences(string text, string first, string second) {
      
        var strs=text.Split(' ').ToArray();
        var res=new List<string>();
        
        for(var i=0;i<strs.Length-1;i++){
            if(strs[i]==first&&strs[i+1]==second&&i+2<strs.Length){
                res.Add(strs[i+2]);
            }
        }
        return res.ToArray();
    }
```
