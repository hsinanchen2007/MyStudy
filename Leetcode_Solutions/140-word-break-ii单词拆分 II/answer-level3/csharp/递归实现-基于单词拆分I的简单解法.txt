记录访问过的路径和返回值
```c# []
List<string>[] visited;
    HashSet<string> dict;
    public IList<string> WordBreak(string s, IList<string> wordDict) {
        visited=new List<string>[s.Length];
        dict=new HashSet<string>(wordDict);
        var res= Find(0,s);
        return res;
    }
    
    List<string> Find(int start,string s){
        if(start<s.Length&&visited[start]!=null){
            return visited[start];
        }
        
        if(start>=s.Length){
            return new List<string>();
        }else{
            var res=new List<string>();
            for(var i=start;i<s.Length;i++){
                var str=s.Substring(start,i-start+1);
                if(dict.Contains(str)){
                    if(i==s.Length-1){
                        res.Add(str);
                        return res;
                    }
                    var t=Find(i+1,s);
                    if(t!=null&&t.Count>0){
                        foreach(var item in t){
                            res.Add($"{str} {item}");
                        }
                    }
                }
            }
            visited[start]=res;
            return res;
        }
    }
```
```python []
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> List[str]:
        dict=set(wordDict)
        sl=len(s)
        visited=[None]*sl
        def find(start):
            if start<sl and visited[start]!=None:
                return visited[start]
            if start>=sl:
                return []
            else:
                res=[]
                for i in range(start,sl):
                    st=s[start:i+1]
                    if st in dict:
                        if i==sl-1:
                            res.append(st)
                            visited[start]=res
                            return res
                        next=find(i+1)
                        if next != None and len(next)>0:
                            for item in next:
                                res.append(st+' '+item)
                
                visited[start]=res
                return res
        fres=find(0)
        
        return fres
                
```

