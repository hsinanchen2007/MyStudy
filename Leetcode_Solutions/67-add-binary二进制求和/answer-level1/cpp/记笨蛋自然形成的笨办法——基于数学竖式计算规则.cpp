### 解题思路
竖式数学计算中，两个0~9的数字的和的值，满十则减十进一
类比二进制，满2进1

### 代码

```cpp
// #include <numeric>
// #include <boost/algorithm/string/join.hpp>
class Solution {
public:
    string addBinary(string a, string b) {
        int la=a.length();
        int lb=b.length();
        
    
        //这个是最后加上去的，起初以为a[n]中的n哪怕超出索引，也可以通过判断是否存在补0，事实却是会随机给一个错误值？
        while(la < lb) 
        {
            a = '0' + a;
            ++ la;
        }
        while(la > lb)
        {
            b = '0' + b;
            ++ lb;
        }

   
  
        
        string result=""; 
        int in=0;
        //in是进位的值，如5+6=1，进1；14+18=2，进3

        string v0="0";
        string v1="1";
        //由于2进制，因此只能有0/1的结果

        for(int i=0;i< (la>=lb?la:lb) ;i++){
            
            int wei;
            //异常处理
            int aa=a[la-1-i]?(a[la-1-i]-48):0;
            int bb=b[lb-1-i]?(b[lb-1-i]-48):0;

            wei = aa+bb +in;
            //算得每一位的结果，对和的结果分类

            // 1+1 =1——1
            // 1+0 =1——0
            // 0+1 =1——1
            // 1+1 =1——1
            // 这是基础，再加上进位的值就行
            // x+y+ 进位 =  z_留位_进位 =0_0_0 =1_1_0 =2_0_1 =3_1_1（四种情况）

            switch(wei){
                case 0:
                    result.append(v0) ;
                    in=0;
                    break;
                case 1:
                    result.append(v1) ;
                    in =0;
                    break;
                case 2:
                    result.append(v0) ;
                    in = 1;
                    break;
                case 3:
                    result.append(v1) ;
                    in = 1;
                    break;
            }
            cout<<"result:"<<result<<endl;
            cout<<a[la-1-i]<<','<<b[lb-1-i]<<',' <<aa<<","<<bb<<","<<in<<","<<wei<<endl;
        }   
        //最后若还有进位=1，则加一即可
        if(in==1){
            result.append(v1) ;
        }
        
        reverse(result.begin(),result.end());
        return result;


    }
};
```