### 解题思路
找规律，每一行里面，间隔的距离和行数i有关系，第一行和最后一行间隔距离都是固定的2*（numRows-1），中间的行，行内奇数位与偶数位间隔是2*(numRows-i-1)，偶数位和下一个奇数位间隔是2i。

### 代码

```cpp
class Solution {
public:
    string convert(string s, int numRows) {
        string ans(s);
        if(numRows<2)
        return ans;
        int j,count,m=0;
        for(int i=0;i<numRows;i++){//逐行进行
            j=i;
            count=1;
            while(j<s.length()){
                ans[m++]=s[j];
                if(i==0||i==numRows-1)//第一行和最后一行，间隔是固定值
                {
                    j+=2*(numRows-1);

                }else{ //中间的行，交替间隔
                    if(count%2==0)//第偶数个与下一个的间隔是2i
                        j+=2*i;
                    else if(count%2==1){//奇数个与下一个的间隔为2*(numRows-i-1)
                        j+=2*(numRows-i-1);
                    }           
                }
                count++;
            }
        }
    return ans;
    }
};
```