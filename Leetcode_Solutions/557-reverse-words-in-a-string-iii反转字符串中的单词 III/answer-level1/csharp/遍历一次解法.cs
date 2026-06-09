```c# []
public string ReverseWords(string s) {
        var sb=new StringBuilder();
        var sb1=new StringBuilder();
        for(var i=0;i<s.Length;i++){
           if(s[i]==' '){
               sb1.Append(' ');
               sb.Append(sb1.ToString());
               sb1.Clear();
           } else if(i==s.Length-1){
               sb1.Insert(0,s[i]);
               sb.Append(sb1.ToString());
           }
            else{
               sb1.Insert(0,s[i]);
           }
        }
        return sb.ToString();
    }
```

