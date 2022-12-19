思路：记录当前数组的值[0]和当前位置[1]
按照值排序[0]
将数组的值[0]更替为当前的位置（排名）
res[data[1]]对应排名da[0]

```
class Solution {
       public String[] findRelativeRanks(int[] nums) {
        int data[][]=new int[nums.length][2];
        for (int i = 0; i < data.length; i++) {
            data[i]=new int[]{nums[i],i};
        }
        Arrays.sort(data,(a,b)->(b[0]-a[0]));
        for (int i = 0; i < data.length; i++) {
            data[i][0]=i+1;
        }
 //Arrays.sort(data, Comparator.comparingInt(a -> a[1]));
        String[] res=new String[nums.length];
            try {
                res[data[0][1]]="Gold Medal";
                res[data[1][1]]="Silver Medal";
                res[data[2][1]]="Bronze Medal";
            } catch (Exception e) {
               return res;
            }
            for (int i = 3; i < data.length; i++) {
            res[data[i][1]]=""+data[i][0];
        }
        return res;
    }
}
```
