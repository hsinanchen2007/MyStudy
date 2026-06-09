### 解题思路
数据结构：Hashmap，int数组 tmp
辅助函数：helper(int nums) 计算从1到nums的和。

思路：将A中每个元素加入到int数组中（不加重复元素），HashMap记录每个元素的个数。然后sort int数组。
遍历数组tmp（除了最后一个元素），int nums = map.get.(tmp[i])-1是下表为i元素多余重复次数，计算capacity = A[i+1]-A[i]-1。
（1）capacity >= nums，则 res += helper（nums）。
（2）capacity <  nums，res += helper(capacity)+(capacity+1)*(nums-capacity),map.put(tmp[i+1],(nums-capacity)+map.get(tmp[i+1]));
return res 加上helper(tmp中最后一个元素在map中的值-1);
### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A.length == 0)
            return 0;
        Map<Integer,Integer> mapNumbers = new HashMap<>();
        int[] tmp = new int[40000];
        int cnt = 0;
        int i = -1;
        for(int x:A){
            if(mapNumbers.get(x) != null)
                mapNumbers.put(x,mapNumbers.get(x)+1);
            else{
                mapNumbers.put(x,1);
                tmp[++i] = x; 
            }
        }
        Arrays.sort(tmp,0,i+1);
        int len = i+1;
        for(i = 0;i<len-1;i++){
            int nums = mapNumbers.get(tmp[i])-1;
            int capacity = tmp[i+1]-tmp[i]-1;
            System.out.println(tmp[i]+"剩余"+nums);
            System.out.println(tmp[i]+"与"+tmp[i+1]+"之间有"+capacity);
            if(capacity>=nums){
                cnt += helper(nums);
            }
            else {
                cnt  += helper(capacity);
                nums -= capacity;//剩余
                mapNumbers.put(tmp[i+1],mapNumbers.get(tmp[i+1])+nums);
                cnt  += (capacity+1)*nums; 
            }
        }
        cnt += helper(mapNumbers.get(tmp[len-1])-1);
        return cnt;
    }
    public int helper(int nums){
        return (1+nums)*nums/2;
    }
}
```