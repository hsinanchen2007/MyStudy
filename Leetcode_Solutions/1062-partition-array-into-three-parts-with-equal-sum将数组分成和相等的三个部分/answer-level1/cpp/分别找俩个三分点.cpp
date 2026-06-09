### 解题思路
此处撰写解题思路
建立两个指针，当第一个指针前面所有数的和是总和的三分之一时，停下，在右边用第二个指针找后一部分的二分点，如果找到了，则返回为真，如果没有找到，则返回到第一个指针的遍历，直到找到三分情况，或已超出边界。
### 代码

```cpp
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        
        //存储每下标的左和
        vector<int> sum(A.size());
        //left和right表示俩个断点的指针
        int left=0,right;
        //计算左和
        for(int i=0;i<A.size();i++){
            if(i==0) sum[i]=A[i];
            else sum[i]=sum[i-1]+A[i];
        }
        //进入循环，判断后俩个部分的和是否是第一部分的二倍
        while(left<=A.size()-3){
            //如果是，则循环看是否能找到第二部分和第一部分相等的分割
            if(sum[A.size()-1]==3*sum[left]){
                right=left+1;
                while(right<=A.size()-2){

                    if(sum[right]-sum[left]==sum[A.size()-1]-sum[right])
                        return true;
                    else right++;
                }
            }
            left++;
        }

        return false;
    }
};
```