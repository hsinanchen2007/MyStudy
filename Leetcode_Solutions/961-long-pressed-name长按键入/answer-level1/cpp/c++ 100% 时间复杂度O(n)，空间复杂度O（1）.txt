```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
		int i=0,j=0;
		name+=' ';
		typed+=' ';
		while(name[i]!=' '&&typed[j]!=' '){
			int x=1;
			while(name[i]==name[i+1]){
				++i;
				++x;
			}
			int y=1;
			while(typed[j]==typed[j+1]){
				++j;
				++y;
			}
			if(x>y||name[i]!=typed[j])return false;
			++i;
			++j;
		}
        if(name[i]!=' '||typed[j]!=' ')return false;
		return true;
    }
};
```