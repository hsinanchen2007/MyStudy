![图片.png](https://pic.leetcode-cn.com/24b76903b670e95bbe77bbe5bac15e39f704aaba11458473b2d17081e766e69a-%E5%9B%BE%E7%89%87.png)

##代码:
```
class Solution{
public:
	    vector<int> v1={1000,500,100,50,10,5,1},v2={'M','D','C','L','X','V','I'}; 
	    int hash['X'-'C'+1]={0}; 
        int romanToInt(string s) {
            for(int i=0;i<v1.size();++i) hash[v2[i]-'C']=v1[i];
            int x=0,i=0;		
            while(i<s.size()){
                if(i<s.size()-1&&hash[s[i]-'C']<hash[s[i+1]-'C']){
                    x+=hash[s[i+1]-'C']-hash[s[i]-'C'];
                    i+=2;
                }
                else{
                    x+=hash[s[i]-'C'];
                    ++i;
                }
            }
            return x; 
        }
};
```