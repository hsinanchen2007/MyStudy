### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int maximumSwap(int num) {
        if(num==0) return 0;
        int oldnum=num;

        vector <int > v;
        int cnt=0,max_=0,pos=0,i,j;
        while (num >0){
            v.insert(v.begin(),num % 10);
            num /= 10;
        }

        int nsize=v.size();
        for (i=1;i<nsize ;i++){
            if (v[i-1]<v[i]) break;
        }

        if (i==nsize) return oldnum;
        j=i;
        while (j<nsize ){
            if (v[j] >=max_) {
                    max_= v[j];
                    pos=j;
            }
            j++;
        }


        for (j=0;j<i;j++){
                if (v[j]<max_)  break;
            }

        swap(v[j],v[pos]);
         for (int i=0;i<v.size();i++){
                num = num * 10 + v[i];
            }
        return num;             
    }
};
```