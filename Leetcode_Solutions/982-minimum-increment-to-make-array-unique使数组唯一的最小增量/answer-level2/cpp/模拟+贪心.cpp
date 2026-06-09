### 解题思路
参考官方题解
### 代码


```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        //核心思路:如[1, 1, 1, 1, 3, 5],多出来3个重复的1,那么需要将三个一增加到2,4,6
        //就相当于result先减去1+1+1,再增加2+4+6
        map<int,int> count;int maxV=0;int minV=INT_MAX;
        for(int i=0;i<A.size();i++)
        {
            maxV=max(maxV,A[i]);
            minV=min(minV,A[i]);
            count[A[i]]++;
        }
             
        int left=0;int result=0;   //left表示还剩下left个重复的数需要自增

        //x表示元素值,之所以到A.size()+maxV,因为如果数组中全是重复的元素maxV,那么就要从maxV一直到A.size()+maxV-1
        for(int x=minV;x<A.size()+maxV;x++)
        {
            //找到重复的数字
            if(count[x]>=2)
            {
                left+=count[x]-1;   //保留一个当前重复的数,其余需要被自增
                result-=x*(count[x]-1); //相当于上面例题中result-=1*(4-1)
            }
            else if(count[x]==0 && left>0)
            {
                left--;
                result+=x;             //找到了还没出现的元素,加上去,填补重复的元素
            }
        }
        return result;
    }
};
```
```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<=1) return 0;
        sort(A.begin(),A.end());
        int result=0;int left=0;   //left表示目前还有多少个重复的元素需要被填充

        //核心:先排序
        //从前向后遍历, 如果A[i]==A[i-1]说明出现重复元素了,left++
        //如果A[i]!=A[i-1],说明A[i-1]+1~A[i]-1中的共A[i]-A[i-1]-1个元素都可以
        //用于填充之前出现的left个元素,去两者最小值num
        //那么用来填充的元素是A[i-1]+1、A[i-1]+2...A[i-1]+num
        for(int i=1;i<A.size();i++)
        {
            if(A[i]==A[i-1])  //出现重复元素了
            {
                left++;
                result-=A[i];
            }
            else
            {
                int num=min(A[i]-A[i-1]-1,left);
                result+=num*A[i-1]+(num+1)*num/2;
                left-=num;
            }
        }
        //如果最后还有元素待填充，那么就用A[size-1]+1、A[size-1]+2...A[size-1]+num填充就行
        result+=left*A.back()+(left+1)*left/2;
        return result;
    }
};
```