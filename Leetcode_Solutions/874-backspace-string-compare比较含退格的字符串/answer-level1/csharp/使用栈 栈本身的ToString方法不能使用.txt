```
public class Solution {
    public bool BackspaceCompare(string S, string T) {
        
        return Convert(S)==Convert(T);
      
        
        
    }
    
    public string Convert(string S){
         Stack<char> content = new Stack<char>();
        for(int i=0;i<S.Length;i++){
            if(S[i]=='#'){
                if(content.Count>0) content.Pop();
                
            }else{
                content.Push(S[i]);
            }
        }
        
        string result ="";
        foreach(var ly in content){
            result+=ly;
        }
        return result;
    }
}
```
