```
    string similarRGB(string color) {
        return "#" + func(color.substr(1,2)) + func(color.substr(3,2)) + func(color.substr(5,2));
    }
    
    string func(const string &x)
    {
        int _x = strtol(x.c_str(),0,16);
        if (_x < 9)
        {
            return "00";
        }
        else if (_x < 9+17)
        {
            return "11";
        }
        else if (_x < 9+17*2)
        {
            return "22";
        }        
        else if (_x < 9+17*3)
        {
            return "33";
        }  
        else if (_x < 9+17*4)
        {
            return "44";
        }  
        else if (_x < 9+17*5)
        {
            return "55";
        }  
        else if (_x < 9+17*6)
        {
            return "66";
        }  
        else if (_x < 9+17*7)
        {
            return "77";
        }  
        else if (_x < 9+17*8)
        {
            return "88";
        }  
        else if (_x < 9+17*9)
        {
            return "99";
        }  
        else if (_x < 9+17*10)
        {
            return "aa";
        }  
        else if (_x < 9+17*11)
        {
            return "bb";
        }     
        else if (_x < 9+17*12)
        {
            return "cc";
        } 
        else if (_x < 9+17*13)
        {
            return "dd";
        } 
        else if (_x < 9+17*14)
        {
            return "ee";
        }        
        else
            return "ff";
    }
```
