如有疏漏，请指正
```
class Solution {
public:
    int compress(vector<char>& chars) {
    	if(chars.size()<2) return chars.size();
	    int i=0,j=0; //i指向相同字段的第一个字符，j指向该段短尾的下一个字符 
	    int count=0; //count记录该段长度 
	    for(;j<chars.size();i=j){
		    while(j<chars.size()&&chars[j]==chars[i]) j++;
		    count = j-i;
		    if(count == 1) continue;
		    else{
		    string s = to_string(count);
		    	chars.erase(chars.begin()+i+1,chars.begin()+j);  //vector的删除只支持迭代器,只保留第一个 
		        j=i+1;  //j本应该在的位置 
			    for(int k=0; k!=s.size();k++,j++){
				    chars.insert(chars.begin()+j,s[k]);   //vector的插入是在迭代器所指元素之前插入 
			    }
		    }		
	    }
	    return chars.size();
    }
};
```
