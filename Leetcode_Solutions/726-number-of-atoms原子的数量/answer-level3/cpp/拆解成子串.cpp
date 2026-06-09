### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {

public:
    string countOfAtoms(string formula) {
        map<string,int> str_nums;
        getNums(str_nums, formula, 0, formula.size()-1, 1);
        string ans;
        for(auto a:str_nums){
            ans+=a.first;
            if(a.second>1){
                ans+=to_string(a.second);
            }            
        }
        return ans;
    }
    void getNums(map<string,int>& str_nums, string& formula, 
    int first, int last, int multi){
        //cout<<"f,l: "<<first<<", "<<last<<", "<<multi<<endl;
        int i=first;
        while(i<=last){
            if(isAlphaUpper(formula[i])){
                // Mg17
                string str_atom;
                str_atom.push_back(formula[i]);
                int j=i+1;
                while(j<=last&&isAlphaLower(formula[j])){
                    str_atom.push_back(formula[j]);
                    j++;
                }
                int n=0;
                string str_n;
                while(j<=last&&isDigit(formula[j])){
                    str_n.push_back(formula[j]);
                    j++;
                }
                if(str_n.empty()){
                    n=1;
                }else{
                    n=stoi(str_n);
                }
                //cout<<"     "<<str_atom<<" "<<n<<endl;
                str_nums[str_atom]+=n*multi;
                i=j;
                //cout<<"     i:"<<i<<endl;
            }else if(formula[i]=='('){
                // (...)17
                int st_bracket=1;
                int j = i+1;
                while(j<=last){
                    if(formula[j]=='('){
                        st_bracket+=1;
                        j++;
                    } else if(formula[j]==')'){
                        st_bracket-=1;
                        j++;
                        if(st_bracket==0){
                            break;
                        }
                    }else{
                        j++;
                    }
                }
                int k=j;
                int n=0;
                string str_n;
                while(k<=last&&isDigit(formula[k])){
                    str_n.push_back(formula[k]);
                    k++;
                }
                if(str_n.empty()){
                    n=0;
                }else{
                    n=stoi(str_n);
                }
                getNums(str_nums,formula,i+1,j-2,multi*n);
                i=k;
            }
        }
        cout<<"quit"<<endl;
    }
    bool isDigit(char& c){
        return c>='0'&&c<='9';
    }
    bool isAlphaUpper(char& c){
        return c>='A'&&c<='Z';
    }
    bool isAlphaLower(char& c){
        return c>='a'&&c<='z';
    }
};
```