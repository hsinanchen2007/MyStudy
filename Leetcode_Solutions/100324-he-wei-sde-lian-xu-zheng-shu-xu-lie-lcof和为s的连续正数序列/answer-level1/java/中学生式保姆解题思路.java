### 解题思路
此方法内存占得很少但是效率不高。。
设输出的连续正整数序列首项为x，末项为y，项数为n，target为t。
则存在以下方程组：
(x+y)*n/2=t;-----1
y=x+n-1;---------2
x>=1;------------3
n>=2;------------4

由2和1可得：(2x+n-1)=2c/n；----------5
结合4可知：(2x+n-1)<=2c/2=c;
得：x<=(c-n+1)/2;----------6
又由5可得：2c/n-n+1=2x;
结合3可知：2c/n-n+1>=2;
即推:2c>=n(n+1)>=n^2;
即：n<=sqrt(2c)----------7

6,7为循环中用到的条件
第一层循环：首先确定n的最大值递减循环，然后找到在n项内x可能的最大值max_x
第二层循环：x从1递增最多循环max_x次，直到找到满足求和公式的x并输出对应数组，跳出循环

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> arrs=new ArrayList<>();
        for(int n=(int)Math.sqrt(2*target);n>=2;n--){
            int max_x=(int)Math.round((target-n+1)/2.0);
            for(int x=1;x<=max_x;x++){
                if(((2*x+n-1)*n/2)==target){
                    int[] arr=new int[n];
                    for(int i=0; i<n;i++){
                        arr[i]=x;
                        x++;
                    }
                    arrs.add(arr);
                    break;
                }
            }
        }
        return arrs.toArray(new int[0][]);
    }
}
```