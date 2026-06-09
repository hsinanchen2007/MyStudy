
## 说明
从1到len/2来遍历循环节长度。暴力比较即可。
同时这里做一个优化： 如果长度为k的循环节比较失败，那么n*k长度的循环节必然会失败！


```c++
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if(len==0) return false;

        bool *check = new bool[len];
        memset(check, 1, len* sizeof(bool));
        for(int i=1;i<=len/2;i++){ // i = 循环节长度
            if(len % i!=0) {
                if(i>1){
                    for(int ii=i;ii<len;ii+=i){
                        check[i] = 0;
                    }
                }

                continue;
            }
            // i的因子长度不是循环节，则i也不是循环节。
            if(check[i]==0) continue;

            bool ok = true;

            for(int j=0;j<i;j++) { // 开始比较
                char f = s[j];
                for(int k=j+i;k<len;k+=i){
                    if(s[k]!=f){
                        ok= false;
                        break;
                    }
                }
                if(!ok){
                    break;
                }
            }
            if(ok){
                delete[] check;
                return true;
            }
        }
        delete[] check;
        return false;
    }
};


```