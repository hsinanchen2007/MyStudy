### 解题思路
此处撰写解题思路
建立了一个索引数组。
### 代码

```cpp
class Solution {
public:
    string intToRoman(int num) {
         string Roman[1001];
    Roman[1]="I";Roman[4]="IV";Roman[5]="V";Roman[9]="IX";
    Roman[10]="X";Roman[40]="XL";Roman[50]="L";Roman[90]="XC";
    Roman[100]="C";Roman[400]="CD";Roman[500]="D";Roman[900]="CM"; 
    Roman[1000]="M";
    int index[13]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    string out="";

    for(int i=12;i>=0;){
        if(num-index[i]>=0){
            out+=Roman[index[i]];
            num-=index[i];
        }
        else{
            i--;
        }
    }

    return out;
        
        
    }
};
```