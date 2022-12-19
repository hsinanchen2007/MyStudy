### 解题思路
通过找规律所得出的答案

### 代码

```cpp
class Solution {
public:
    string convert(string s, int n) {
        int size = s.length(), _n=0, _j=0;

        if(n==1) return s;

        int x=0, _x=0, *p = new int [n];

        if(n==2){
            p[0]=p[1]=size/2;
            if(size%2!=0) p[0]++;
        }else{
            if(3*n-2 > size) _n=0, _j=size;
            else{
                _n=1;
                while( (2*_n+1)*n-2*_n < size ){
                    _n++;
                }
                if( (2*_n+1)*n-2*_n == size ){;}
                else if(  (2*_n+1)*n-2*_n > size ){
                    _j = 2*n-2 - ((2*_n+1)*n-2*_n - size);
                    _n--;
                }
            }

            if(_n!=0){
                x = (_n==1)?2:(_n+1);
                _x=((2*_n+1)*n-2*_n-2*x)/(n-2);     
            }
                
            for(int i=0;i<n;i++){
                if(i==0 || i==n-1) p[i]=x;
                else p[i]=_x;
            }

            if(_n!=0){
                if(_j!=0) for(int i=n-2;i>0&&_j>0;i--,_j--) p[i]++;
                if(_j!=0) for(int i=0;i<n&&_j>0;i++,_j--) p[i]++;
            }else{
                if(_j!=0) for(int i=0;i<n&&_j>0;i++,_j--) p[i]++;
                if(_j!=0) for(int i=n-2;i>0&&_j>0;i--,_j--) p[i]++;
                if(_j!=0) for(int i=0;i<n&&_j>0;i++,_j--) p[i]++;
            }
        }

        int *q = new int [size];
        int k=0, t=2*n-2, _t;
        for(int j=0;j<n;j++){
            for(int i=0;i<p[j];i++){
                if(j==0 || j==n-1) q[k++]=j+(2*n-2)*i;
                else{
                    _t = (i%2!=0)?t:(2*n-2-t);
                    q[k++]= (i==0)?j:q[k-1]+_t;
                }
            }
            t-=2;
        }

        string str;

        for(int i=0;i<size;i++) str.insert(i,1,s[q[i]]);

        return str;
    }
};
```