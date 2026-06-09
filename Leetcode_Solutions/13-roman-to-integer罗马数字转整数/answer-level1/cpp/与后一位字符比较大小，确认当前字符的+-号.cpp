由于罗马数字的特性，当比较小的字符在大的字符的前面时，表现为负数。
所以只要在遍历时都与后面一位字符的大小做比较就好了~
```
class Solution{
	public: 
	    int romanToInt(string s) {
        int _size=s.size();
        int index,_int=0;
        for(index=0;;index++){
        	if(index==_size-1){
        		_int+=getNumber(s[index]);//遍历到最后一位时，结束循环。
        		break;
			}
        	if(getNumber(s[index])<getNumber(s[index+1])){
        		_int-=getNumber(s[index]);
			}
			else _int+=getNumber(s[index]);
		}
		return _int;
    }
    int getNumber(char c){
        int num;
        switch(c){
            case 'I':num=1;
                   break;
            case 'V':num=5;
                   break;
            case 'X':num=10;
                   break;
            case 'L':num=50;
                   break;
            case 'C':num=100;
                   break;
            case 'D':num=500;
                   break;
            case 'M':num=1000;
                   break;
        }
        return num;
    }
}; 
```
