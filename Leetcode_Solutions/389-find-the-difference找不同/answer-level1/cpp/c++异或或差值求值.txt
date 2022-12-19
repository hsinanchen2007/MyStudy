
```

//得两string的总值做差即为多出来的那个值
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sall=0,tall=0;
        for(int i=0;i<s.size();i++)
            sall+=s[i];
        for(int i=0;i<t.size();i++)
            tall+=t[i];
        char x=tall-sall;
        return x;
            
    }
};


//用异或法，全部异或过后，所有重复出现的会回0，只留下落单的那个值
class Solution
{ 
    public: char findTheDifference(string s, string t) 
    { 
        int res=0; 
        for(int i=0;i<s.size();i++) 
            res^=s[i]; 
        for(int i=0;i<t.size();i++) 
            res^=t[i]; 
        return (char)res; 
    } 
};
```