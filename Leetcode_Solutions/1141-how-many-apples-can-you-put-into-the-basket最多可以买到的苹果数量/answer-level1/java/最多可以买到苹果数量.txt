### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxNumberOfApples(int[] arr) {
        //贪心法的应用
        Arrays.sort(arr);
        int count=0;
        int sum=0;
        for(int i=0;i<arr.length;i++)
        {
            sum+=arr[i];
            if(sum<=5000)
            {
                count++;
            }
            else
                break;
        }
        return count;
    }
}
```