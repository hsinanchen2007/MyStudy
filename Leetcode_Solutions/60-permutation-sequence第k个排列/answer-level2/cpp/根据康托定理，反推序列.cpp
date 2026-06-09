```
class Solution {
public:
    string getPermutation(int n, int k) {
        k = k-1;
        string res;
        vector<int> rom;
        for(int i=0;i<=n;i++)
            rom.push_back(0);
        int i = n-1;
        for(;i>=0;i--){
            /*如果余数为0*/
            if(k==0){
                int v = 0;
                for(int j=1;j<=n;j++){
                    if(rom[j] == 0){
                        v = j;
                        break;
                    }        
                }
                char re = '0'+v;
                res = res+re;
                rom[v] = 1;
            }
            else{
                int temp = 1;
                for(int j=i;j>=1;j--)
                    temp = temp*j;
                int a = k%temp;
                int b = k/temp;
                b++;
                int count = 0;
                /*计算前面有k/temp个未使用数对应的下标*/
                for(int z = 1;z<=n;z++){
                    if(rom[z] == 0){
                        count++;
                        if(count==b){
                            b=z;
                            break;
                        }
                    }
                }
                char re = '0'+b;
                res = res+re;
                rom[b] = 1;
                k = a;
            }
            
        }
        return res;  
    }
};
```

