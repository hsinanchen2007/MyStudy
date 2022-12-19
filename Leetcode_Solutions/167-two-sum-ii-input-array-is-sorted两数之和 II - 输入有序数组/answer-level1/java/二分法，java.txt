### 解题思路

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];
        for(int i =0 ; i<numbers.length-1&&numbers[i]<=target; i++)
        {
            int t= target-numbers[i];//二分法在剩下的数里查找等于t的数的下标
            int index2=erfen(numbers,i+1,numbers.length-1,t);
            if(index2!=0)
            {
                res[0]=i+1;
                res[1]=index2+1;
                return res;
            }
        }
        return res;
    }
static int erfen(int[] numbers,int start,int end,int t){   
        while(start<=end){
        int mid = (start+end)/2;
        if(numbers[mid]==t)
         return mid;
        if(numbers[mid]>t)
         end=mid-1;
        else start=mid+1;
        }
        return 0;   
    }
}
```