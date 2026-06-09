```
class Solution {
public:
    string reverseStr(string s, int k) {
        int len=s.size();
        int numk=len/k,i=0;//直接分成numk段
        while(numk>0){
            reverse(s.begin()+i,s.begin()+i+k);//每次反转一段，然后跳过一段
            i+=2*k;
            numk-=2;
        }
        if(numk==0){ //当结尾还剩下小于k个数据时直接全部反转即可
            reverse(s.begin()+i,s.end());
        }
        return s;
    }
};
```
