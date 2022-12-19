```
//(1)
char *a = new char[s.length()+1];
vector<string> outputV;
strcpy(a,s.c_str()); //http://www.cplusplus.com/reference/string/string/c_str/ 

//(2)
char *p=strtok(a," ");
while(p){
    outputV.push_back(p);
    p=strtok(NULL," "); //http://www.cplusplus.com/reference/cstring/strtok/?kw=strtok 
}

```

```
class Solution {
public:
    string reverseWords(string s) {
        //(1)
        char *a = new char[s.length()+1];
        vector<string> outputV;
        strcpy(a,s.c_str()); //http://www.cplusplus.com/reference/string/string/c_str/ 
        
        //(2)
        char *p=strtok(a," ");
        while(p){
            outputV.push_back(p);
            p=strtok(NULL," "); //http://www.cplusplus.com/reference/cstring/strtok/?kw=strtok 
        }
        
        string output="";
        for(int i=0;i<outputV.size();i++){
            reverse(outputV[i].begin(),outputV[i].end());
            output.append(outputV[i]);
            if(i==outputV.size()-1)
                break;
            output.append(" ");
        }
        return output;
    }
};
```
