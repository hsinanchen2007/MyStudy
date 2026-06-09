### 解题思路
此处撰写解题思路
我的思路:
    用比较排序算法，前一个和后一个进行对比，如果有重复的那么就记录下来，并且跳出循环，两成循环都要跳出来
最后将这个值返回
### 代码

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        boolean flag=false;
        int max=0;
        for(int i=0;i<A.length;i++){
            for(int j=i+1;j<A.length;j++){
                if(A[i]==A[j]){
                    flag=true;
                    max=A[i];
                    break;
                }else{
                    flag=false;
                }
            }
            if(flag){
                break;
            }
        }
        return max;
       
        
    }
}
```