### 解题思路
看到我的程序才超过15%左右的。。
然后我用python提交了一下，这下子对语言的效率有了更高的认识。

### 代码

```cpp
#include<vector>
class Solution {
public:
    void sortVector(vector<vector<int>>& box,int i,int j){
        if(i>=j){
            return;
        }
        int a=i,b=j;
        while(i<j){
            while(i<j){
                if(box[j][2]>=box[i][2]){
                    j--;
                }else{
                    swap(box[i],box[j]);
                    i++;
                    break;
                }
            }
            while(i<j){
                if(box[j][2]>=box[i][2]){
                    i++;
                }else{
                    swap(box[i],box[j]);
                    j--;
                    break;
                }
            }
        }
        sortVector(box,a,i-1);
        sortVector(box,i+1,b);
    }

    int pileBox(vector<vector<int>>& box) {
        int length=box.size();
        if(length<=0){
            return 0;
        }
        sortVector(box,0,length-1);
        int* dp=new int[length];
        dp[0]=box[0][2];

        int max,noneMax=0;
        for(int i=1;i<length;i++){
            max=0;
            for(int j=i-1;j>=0;j--){
                max=(box[i][0]>box[j][0]&&box[i][1]>box[j][1]&&box[i][2]>box[j][2]&&dp[j]>max)?max=dp[j]:max;
            }
            max+=box[i][2];
            dp[i]=max;
            noneMax=(noneMax<max)?max:noneMax;
        }
        return noneMax;
    }
};
```