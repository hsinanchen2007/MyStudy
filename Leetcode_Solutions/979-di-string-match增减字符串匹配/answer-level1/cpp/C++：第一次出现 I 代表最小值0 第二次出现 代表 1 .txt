```
class Solution {
    //第一个I对应0，第二个I对应0+1。第一个D对应 N ,N第二个对应N-1。
public:
    vector<int> diStringMatch(string S) {
        vector<int> C;
        int min =0,max;
        max = S.size();
        for(auto &a:S){
            if(a == 'I'){
                C.push_back(min);
                min++;
                

            }
            else{
                C.push_back(max);
                    max--;
               
            }
        }
        C.push_back(min); //这里选min 和max都一样。
        return C;
        
        
    }
};
```
![image.png](https://pic.leetcode-cn.com/3b40b498a6429686f945c7778f610b093a94a5f1838c69df0e26f8da740714a7-image.png)

