```
class Solution {
public:
	int ys(int a,int b){//求最大公约数 
		int tmp;
		do{
			tmp=a%b;
			a=b;
			b=tmp;
		}while(tmp);
		return a;
	}
    bool hasGroupsSizeX(vector<int>& deck) {
    	if(deck.size()<=1)
    		return 0;
        map<int,int> m;
        map<int,int>::iterator it1,it2;
		for(int i=0;i<deck.size();i++)
			m[deck[i]]++;
		int tmp,min=10000;
		for(it1=m.begin(),it2=m.begin(),it2++;it2!=m.end();it1++,it2++){
			tmp=ys(it1->second,it2->second);
			if(tmp<min)
				min=tmp;	
		}
		return min>=2;
    }
};
```
