![image.png](https://pic.leetcode-cn.com/bd458783a18d402bb75e250f27026d8e4d7b68185eb7231293903c32bd9087cd-image.png)

先判断特例 长度为0或1或者行数为0或者字符长度小于行数
下面是一般情况
将字符串分组 每组有numRows*2-2个字符
开创一个二维数组来模拟矩形，并赋初值（无效字符）
然后根据每个字符在每组的位置判断每个字符的行和列
遍历每个字符将其插入数组
按从上到下从左到右的顺序每行读取有效字符

```
class Solution {
public:
    string convert(string s, int numRows) {
        int len=s.size(),group=numRows*2-2;
        if(len==0||len==1||numRows==1||len<=numRows)return s;
        int groupnum=len/group+1;
        char** z;
        z=new char*[numRows];
        for(int i=0;i<numRows;i++)z[i]=new char[groupnum*2];
        int res,row,co,r=numRows,c=groupnum*2;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                z[i][j]='!';
        for(int i=0;i<len;i++){
            res=(i+1)%group;
            if(res<=r&&res>0){
                row=res-1;
                co=(i+1)/group*2;
            }
            else if(res>r) {
                row=2*r-res-1;
                co=(i+1)/group*2+1;
            }
            else {
                row=1;
                co=(i+1)/group*2-1;
            }
            z[row][co]=s[i];
        }
        string a(len,'!');
        int index=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(z[i][j]!='!'){
                    a[index]=z[i][j];
                    index++;
                }
            }
        }
        return a;
    }
};
```
