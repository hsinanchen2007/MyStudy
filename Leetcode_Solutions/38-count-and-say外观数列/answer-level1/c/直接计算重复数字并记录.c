class Solution {
public:
     string countAndSay(int n) {
    	if( n <= 0 || n > 30)	return string("");
    	int count = 1;
        string Str = "1";
        while( --n > 0)
        	Str =  StrInt_Say(Str);
       	return Str;
    }
    string  StrInt_Say(string StrInt){
    	if(StrInt.length() == 1) 	return "11";
    	char prech = StrInt[0];
    	int count = 1;
    	string Str_Say;
		for(int i = 1; i < StrInt.length(); ++i){
			if(prech == StrInt[i] ){
				++count;
			}else{
				Str_Say.push_back(count + '0');
				Str_Say.push_back(prech);
				prech = StrInt[i];
				count = 1;
			}
		}
		if( count != 0 ){
				Str_Say.push_back(count + '0');
				Str_Say.push_back(prech);
		}
		return Str_Say;
    }
};