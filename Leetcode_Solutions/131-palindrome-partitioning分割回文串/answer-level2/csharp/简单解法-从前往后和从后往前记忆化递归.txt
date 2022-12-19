1.从后往前递归，使用字典保存递归过的路径结果，加速计算
```c# []
public class Solution {
    Dictionary<int,List<IList<string>>> dict=new Dictionary<int,List<IList<string>>>();
    public IList<IList<string>> Partition(string s) {
        if(string.IsNullOrEmpty(s)||s.Length==0){
            return new List<IList<string>>{};
        }
        
        return Partition(s,0);
    }
    
    List<IList<string>> Partition(string s,int start){
        if(dict.ContainsKey(start)){
            return dict[start];
        }
        if(start==s.Length-1){
            return  new List<IList<string>>{
                new List<string>{s[s.Length-1].ToString()}
            };
        }else if(start>=s.Length){
            return null;
        }else{
            var res=new List<IList<string>>();
            for(var i=start;i<s.Length;i++){
                if(Check(s,start,i)){
                    var str=s.Substring(start,i-start+1);
                    if(i==s.Length-1){
                        res.Add(new List<string>{str});
                        
                        continue;
                    }
                    
                    var temp=Partition(s,i+1);
                    if(temp!=null){
                        foreach(var ary in temp ){
                            var tlist=new List<string>{str};
                            tlist.AddRange(ary);
                            res.Add(tlist);
                        }
                    }
                    
                }
            }
            res=res.Count>0?res:null;
            dict[start]=res;
            return res;
        }
    }
    bool Check(string s,int l,int r) {
        if(l==r){
            return true;
        }
        if(l>r){
            return false;
        }
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
```

2.从前往后，无记忆化加速
```
public class Solution {
    IList<IList<string>> res=new List<IList<string>>();
    public IList<IList<string>> Partition(string s) {
        if(string.IsNullOrEmpty(s)||s.Length==0){
            return res;
        }
        Partition(new List<string>(),s,0);
        return res;
    }
    
    void Partition(List<string> temp,string s,int start){
        if(start==s.Length-1){
            temp.Add(s[s.Length-1].ToString());
            res.Add(temp);
            return;
        }else if(start>=s.Length){
            return;
        }else{
            for(var i=start;i<s.Length;i++){
                if(Check(s,start,i)){
                    var list=new List<string>(temp);
                    list.Add(s.Substring(start,i-start+1));
                    if(i==s.Length-1){
                        res.Add(list);
                    }else{
                        Partition(list,s,i+1);
                    }
                }
            }
        }
        
    }
    bool Check(string s,int l,int r) {
        if(l==r){
            return true;
        }
        if(l>r){
            return false;
        }
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
```
