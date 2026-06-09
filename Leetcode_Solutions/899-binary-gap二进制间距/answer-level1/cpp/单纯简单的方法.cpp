因为预先用了bitset，所以效率不如用与运算直接统计高

```
class Solution {
public:
    int binaryGap(int N) {
      
        bitset<31> binary(N);//因为N<=10^9 所以位数设置为31位就够了
        
        //cout << binary << endl;
        
        bool flag = false;//标识符 用来开启/关闭统计周期
        int gap = 0;//单次统计距离
        int max_gap = 0;//最大统计距离
        
        for(int i=0; i<binary.size(); i++){//遍历二进制数组
            
            if(flag == true && !binary.test(i))//如果标识符打开且当且指向的二进制位数为0则累加距离
                gap++;
            
            else if(flag == false && binary.test(i))//如果标识符关闭且当前二进制位数为1则打开标识符
                flag = true;
            
            else if(flag == true && binary.test(i)){//如果标识符打开且当前二进制位数为1则结束当前统计周期，清零统计距离
                gap++;
                flag == false;
                max_gap = max(gap,max_gap);
                gap = 0;
            }
                
        }
        
        return max_gap;
        
        
    }
};
```
