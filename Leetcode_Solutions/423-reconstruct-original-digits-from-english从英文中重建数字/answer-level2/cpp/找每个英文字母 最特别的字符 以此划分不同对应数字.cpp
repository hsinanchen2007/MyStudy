有些数字没特殊区分 可以先利用有特殊的数字 先排除完  剩下就是没特殊分别的数字
题目没说是否是按数字序号从小到大 我就sort一下
```
class Solution {
public:
//zero,one,two,three,four,five,six,seven,eight,nine
    string originalDigits(string s) {

        vector<int> vt(26,0);
        int i,j;
        for(i=0;i<s.length();i++){
            vt[s[i]-'a']++;
        }
        while(vt['z'-'a']>0){
            vt['z'-'a']--,vt['e'-'a']--,vt['r'-'a']--,vt['o'-'a']--;
            res.push_back(0);
        }
        
         while(vt['w'-'a']>0){
            vt['w'-'a']--,vt['t'-'a']--,vt['o'-'a']--;
            res.push_back(2);
        }
       
       
        while(vt['u'-'a']>0){
            vt['f'-'a']--,vt['o'-'a']--,vt['u'-'a']--,vt['r'-'a']--;
            res.push_back(4);
        }
        while(vt['f'-'a']>0){
            vt['f'-'a']--,vt['i'-'a']--,vt['v'-'a']--,vt['e'-'a']--;
            res.push_back(5);        
        }
         while(vt['r'-'a']>0){
            vt['t'-'a']--,vt['h'-'a']--,vt['r'-'a']--,vt['e'-'a']--,vt['e'-'a']--;
            res.push_back(3);
        }
         while(vt['o'-'a']>0){
            vt['o'-'a']--,vt['n'-'a']--,vt['e'-'a']--;
            res.push_back(1);
        }
        while(vt['x'-'a']>0){
            vt['s'-'a']--,vt['i'-'a']--,vt['x'-'a']--;
            res.push_back(6);
        }
        while(vt['v'-'a']>0){
            vt['s'-'a']--,vt['e'-'a']--,vt['v'-'a']--;
            vt['e'-'a']--,vt['n'-'a']--;
            res.push_back(7);
        }
        while(vt['g'-'a']>0){
            vt['e'-'a']--,vt['i'-'a']--,vt['g'-'a']--;
            vt['h'-'a']--,vt['t'-'a']--;
            res.push_back(8);
        }
        while(vt['i'-'a']>0){
            vt['n'-'a']--,vt['i'-'a']--,vt['n'-'a']--;
            vt['e'-'a']--;
            res.push_back(9);
        }
        sort(res.begin(),res.end());
        string res1;
        for(i=0;i<res.size();i++){
            res1+=res[i]+'0';
        }
        return res1;
    }
};
```
