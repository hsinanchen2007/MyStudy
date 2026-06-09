```
public string ToGoatLatin(string S) {
        var sb=new StringBuilder();
        var dict=new HashSet<char>{'a','A','e','E','i','I','o','O','u','U'};
        char pre='*';
        string pfix=string.Empty;
        string post=string.Empty;
        for(var i=0;i<S.Length;i++){
            var c=S[i];
            if((pre=='*'||pre==' ')&&c!=' '){
                if(dict.Contains(c)){
                    pfix="ma";
                    sb.Append(c);
                }else{
                    pfix=c+"ma";
                }
            }
            else if(pre!=' '&& c==' '){
                post+='a';
                sb.Append(pfix);
                sb.Append(post);
                sb.Append(' ');
                pfix=string.Empty;
            }else{
                sb.Append(c);
            }
            
            if(i==S.Length-1){
                post+='a';
                sb.Append(pfix);
                sb.Append(post);
            }
            
            pre=c;
        }
        return sb.ToString();
    }
```
