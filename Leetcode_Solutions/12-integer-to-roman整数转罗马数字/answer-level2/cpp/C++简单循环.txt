**1. 思路：改写为罗马数字是根据每个数位分别改写再拼接。**
比如21：个位是1，改写为I，十位是2改写为XX，合起来就是XXI。
比如1943：个位是3，改写为III；十位是4改写为XL；百位是9改写为CM；千位是1，改写为M；合起来就是MCMXLIII
**注意到：个位只能用到I V X ，十位只能用到X L C，依次类推。**
2. 代码
```
class Solution {
public:
    string intToRoman(int num) {
        if(num<1||num>3999)//超过3999会越界
            return "";
        string str="IVXLCDM";
        string answer;
        int j=0;
        while(num!=0)
        {
            string temp;
            int x=num%10;
            num=num/10;

            if(x<5)
            {
                if(x==4)
                {
                 temp=str[j];
                 temp=temp+str[j+1];
                }
                else
                {
                    for(int i=0;i<x;i++)
                        temp=temp+str[j];
                }
            }
            else
            {
                if(x==9)
                {
                    temp=str[j];
                    temp=temp+str[j+2];
                }
                else
                {
                    temp=str[j+1];
                    for(int i=0;i<x%5;i++)
                        temp=temp+str[j];
                }
            }
            j+=2;
            answer=temp+answer;
        }
        return answer;
    }
};
```
3. 时间复杂度O(n),n是num的位数，本题最多为4次，里层的for循环最多12次。
4. 空间复杂度O(1) 。


