### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int longestOnes(int[] A, int K) {
        //滑动窗口的问题
        int l=0,r=0;
        int count=0;      //负责记录窗口中0的个数
        int max=0;
        while(r<A.length){
            if(A[r]==0)   //到达K的时候，左指针移动到下一个0处 
            {
                count++;
                if(count>K)
                {
                    while(A[l]!=0)
                        l++;
                    l+=1;  //指向了下一个为0的地方
                    count--;
                }   
            }
            max=Math.max(max,r-l+1);
            r++;
        }
        return max;
    }
}
```