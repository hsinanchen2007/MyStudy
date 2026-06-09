### 解题思路
1.先判断是否单元素数组和空数组避免死循环。
2.为了避免start，mid和end三个数字相同而无法判断最小数字位于左右部分，加入了顺序查找法。

### 代码

```java

class Solution {
    public int minArray(int[] numbers) {
        int l=numbers.length;
        if(l<=0)return -1;
        else if(l==1){
            return numbers[0];
        }
        int start=0;
        int end=l-1;
        int mid=start;
        while (numbers[start]>=numbers[end]){
            if(end-start==1){
                mid=end;
                break;
            }
            mid=(start+end)/2;
            if(numbers[start]==numbers[end]&&numbers[start]==numbers[mid]){
                return ThrOrder(numbers,start,end);
            }
            if(numbers[mid]>=numbers[start])start=mid;
            else if(numbers[mid]<=numbers[end])end=mid;
        }
        return numbers[mid];
    }
    private int ThrOrder(int[] numbers,int start,int end){
        int result=numbers[start];
        for (int i=start+1;i<=end;i++){
            if(result>numbers[i])result=numbers[i];
        }
        return result;
    }
}
```