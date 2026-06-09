```
string originalDigits(string s) {
        int hashmap[128]={0};
        for(auto ch:s){
            hashmap[ch]++;
        }
        string res="";
        while(hashmap['z']>0){//余下的只有0的英文中有z
            hashmap['z']--;hashmap['e']--;
            hashmap['r']--;hashmap['o']--;
            res+="0";
        }
        while(hashmap['o']>hashmap['w']+hashmap['u']){//余下的只有124有o,当包含1时o个数比w+u大
            hashmap['o']--;hashmap['n']--;hashmap['e']--;
            res+="1";
        }
        while(hashmap['w']>0){//余下的只有2有w
            hashmap['t']--;hashmap['w']--;hashmap['o']--;
            res+="2";
        }
        while(hashmap['r']>hashmap['u']){//余下的只有34有r,有3时r比u多
            hashmap['t']--;hashmap['h']--;hashmap['r']--;hashmap['e']-=2;
            res+="3";
        }
        while(hashmap['u']>0){//余下的只有4有u
            hashmap['f']--;hashmap['o']--;
            hashmap['u']--;hashmap['r']--;
            res+="4";
        }
        while(hashmap['f']>0){//余下的只有5有f
            hashmap['f']--;hashmap['i']--;
            hashmap['v']--;hashmap['e']--;
            res+="5";
        }
        while(hashmap['x']>0){//余下的只有6有x
            hashmap['s']--;hashmap['i']--;hashmap['x']--;
            res+="6";
        }
        while(hashmap['v']>0){//余下的只有7有v
            hashmap['s']--;hashmap['e']-=2;
            hashmap['v']--;hashmap['n']--;
            res+="7";
        }
        while(hashmap['g']>0){//余下的只有8有g
            hashmap['e']--;hashmap['i']--;
            hashmap['g']--;hashmap['h']--;
            hashmap['t']--;res+="8";
        }
        while(hashmap['i']>0){//余下的只有9有i
            hashmap['n']-=2;hashmap['i']--;
            hashmap['e']--;
            res+="9";
        }
        return res;
    }
```