### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        int asize = a.size();
        int bsize = b.size();
        //补零，使位数相同
        while(asize < bsize){
            a = "0"+a;
            
            asize++;
        }
        while(asize > bsize){
            b = "0" + b;
            bsize++;
        }
        //对应位相加，结果有 0 （0，不进位）， 1 （1，不进位）， 2（0，进位） ， 3 （1，进位），
        string retdata = "";
        int temp = 0;
        for(int j = asize-1;j>=0;j--){
            int n1 = a[j] -'0';
            int n2 = b[j] -'0';
            int res = n1+n2+temp;
            cout<<res<<endl;
            if(res == 0) {
                retdata = "0" + retdata;
                temp = 0;
            }
            if(res == 1) {
                retdata = "1" +retdata;
                temp = 0;
            }
            if(res == 2){
                retdata = "0" + retdata;
                temp = 1;
            }
            if(res == 3){
                retdata = "1" +retdata;
                temp = 1;
            }

        }
        //最后若还有进位没处理，就在前面加上“1”
        if(temp == 1){
            retdata = "1" + retdata;
        }
        return retdata;
    }
};
```