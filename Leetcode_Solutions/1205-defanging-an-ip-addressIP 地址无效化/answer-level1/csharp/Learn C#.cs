Sry, I don't have chinese input source in this computer.
```C#
public class Solution {
    public string DefangIPaddr(string address) {
        string res="";//Here you must give the definition, or it will not work in the foreach loop
        foreach(var s in address){
            if(s=='.') 
            {res+="[.]";}
            else {res+=s;}
        }
        return res;
    }
}
```
