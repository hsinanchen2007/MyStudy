```
class Solution {
public:
    string defangIPaddr(string address) {
        
        //不使用insert函数
        string res = "";
        
        for(int i=0; i<address.length(); i++){
            
            if(address[i] == '.')
                res += "[.]";
            else
                res += address[i];
        }
        
        return res;
    }
};
```


```
class Solution {
public:
    string defangIPaddr(string address) {
        
        //使用insert函数
        for(int i=0; i<address.length(); i++){
            
            if(address[i] == '.'){
                
                address = address.insert(i, 1, '[');
                address = address.insert(i+2, 1, ']');
                i = i + 3;
            }
                
        }
        
        return address;
        
        
    }
};
```

