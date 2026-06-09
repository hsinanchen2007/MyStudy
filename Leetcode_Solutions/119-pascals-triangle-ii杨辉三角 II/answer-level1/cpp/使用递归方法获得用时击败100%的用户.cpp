递归的概念：调用程序自身的技巧称为递归；
递归的三个条件：边界条件；前进段和返回段；当边界条件不满足是，递归前进，边界条件满足时，进行递归返回；

先看边界条件：既rowIndex为0时，返回值为1的vector：[1];
再看前进段：前进也就是这个实体和上个实体的关系，在该个题目中，第i行和第i-1行之间的关系，除第i行的第0个元素和最后一个元素都为1，其余元素的值时第i-1行的第j-1个和第j个元素的和。如何获得第i-1行呢？这个时候需要调用自身。
代码如下：
```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vAd(rowIndex+1);
        if(rowIndex == 0) 
        {
            vAd[0] = 1;
            return vAd;
        }
        else
        {
            vector<int> vAd1(rowIndex);
            vAd1 = getRow(rowIndex-1);
            for(int i = 0;i<rowIndex+1;i++)
            {
                if(i==0||i==rowIndex)
                {
                    vAd[i] = 1;
                }
                else
                {
                    vAd[i] = vAd1[i-1]+vAd1[i];
                }
            }
            return vAd;
        }
    }
};
```
